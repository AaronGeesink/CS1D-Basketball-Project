
#ifndef MAPH_H_
#define MAPH_H_

#include<iostream>

template<typename V>
class Position													// a (key, value) pair
{

public:
    Position():_key(0), _free(true){}
    Position(int key, V value):_key(key), _value(value), _free(true){}		// Constructor
    const int &Key(){return _key;}								// Returning the key reference
    const V &Value(){return _value;}							// Returning the value reference
    void SetKey(int key){_key = key;}								// Setting a new key
    void SetValue(V value){_value = value;}						// setting a new value								// Place a value into the position
    bool operator==(Position<V> &n){
            return n._key == this->_key && n._value == this->_value;
        }
    bool operator!=(Position<V> &n)
        {
        return n._key != this->_key || n._value != this->_value;
        }
    bool _free;					// true when space is free to place a new data in it
private:

    int _key;														// key
    V _value;													// value
};


template<typename V>
class Map
{
public:

    Map(const int SIZE);							//Constructor (getting Size to create an array)
    ~Map();
    int Size()const;								//Returns the size of the map
    bool Empty();									//Returns true of the map is empty
    Position<V> Find(const int& key);				//This function will return the position of the specified key
    void Put(const int &key, const V &value);		//Puts a position into the map
    void Erase(const int& key);						//This function will remove the position with the specified key
    void OutputIO();



private:
    Position<V> *list;
    int Hash(int key, int j = 0);
    int _size;										//Max size of the list
    int _filled;									//Number of positions in the list
};


template<typename V>
Map<V>::Map(const int SIZE)
{
    list = nullptr;
    list = new  Position<V> [SIZE];
    _size = SIZE;
    _filled = 0;
}


template<typename V>
Map<V>::~Map()
{
    delete list;
}


template<typename V>
void Map<V>::Put(const int &key, const V &value)
{
    int index = Hash(key);

    if(index != -1 && list[index]._free)
    {
        list[index].SetKey(key);
        list[index].SetValue(value);
        list[index]._free = false;
        _filled++;
    }
    else if (!list[index]._free)
    {
        list[index].SetValue(value);
    }
    else
    {
        std::cerr << "List is full \n";
    }

}

template<typename V>
int Map<V>::Size()const
{
    return _filled;
}

template<typename V>
bool Map<V>::Empty()
{
    return _filled == 0;
}

template<typename V>
int Map<V>::Hash(int key, int j)
{
    int index;
    int h;
    int hPrime;
    const int HK = 2;

    h = key % _size;
    hPrime = j * (HK - (key % HK));
    index = (h + hPrime) % _size;

    if(list[index]._free || list[index].Key() == key)
    {
        return index;
    }
    else if(j == _size - 1)
    {
        return -1;
    }

    return Hash(key, j + 1);
}

template<typename V>
Position<V> Map<V>::Find(const int& key)
{
    return list[Hash(key)];
}

template<typename V>
void Map<V>::OutputIO()
{

    for(int count = 0; count < _size; count++)
    {
        if(!list[count]._free)
        {
            std::cout << list[count].Key() << ',' << list[count].Value() << std::endl;
        }
    }
}


template<typename V>
void Map<V>::Erase(const int& key)
{
    int index = Hash(key);

    if(!list[index]._free)
    {
        list[index]._free = true;
        list[index].SetKey(0);
        _filled--;
    }
    else
    {
        std::cerr << "The position does not exist\n\n";
    }
}



#endif /* MAPH_H_ */
