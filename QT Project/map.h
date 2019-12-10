
#ifndef MAPH_H_
#define MAPH_H_

#include<iostream>

/**
 *@author Aaron & Faris
 *@brief Position class
 * This is the position class used to track map positions
 *@date December 2019
 */
template<typename V>
class Position													// a (key, value) pair
{

public:
	/// Default constructor
	Position():_key(0), _free(true){}

	/// Overloaded Constructor
	Position(int key, V value):_key(key), _value(value), _free(true){}

	/**
	 * @author Aaron Geesink
	 * @brief Key()
	 * Returns the key reference
	 * @return const int &
	 */
	const int &Key(){return _key;}

	/**
	 * @author Aaron Geesink
	 * @brief Key()
	 * Returns the value reference
	 * @return const V &
	 */
	const V &Value(){return _value;}

	/**
	 * @author Aaron Geesink
	 * @brief SetKey(int key)
	 * Sets a new key
	 * @param int key
	 */
	void SetKey(int key){_key = key;}

	/**
	 * @author Aaron Geesink
	 * @brief SetValue(V value)
	 * Sets a new values
	 * @param V values
	 */
	void SetValue(V value){_value = value;}

	/// Equality operator
	bool operator==(Position<V> &n)
	{
		return n._key == this->_key && n._value == this->_value;
	}
	/// Inequality operator
	bool operator!=(Position<V> &n)
	{
		return n._key != this->_key || n._value != this->_value;
	}
	bool _free;				/// true when space is free to place a new data in it
private:

	int _key;				/// key
	V _value;				/// value
};

/**
 *@author Aaron & Faris
 *@brief Map class
 * This is the map class used to hold souvenirs
 *@date December 2019
 */
template<typename V>
class Map
{
public:
	/// Overloaded constructor
	Map(const int SIZE);		//Constructor (getting Size to create an array)

	/// Destructor
	~Map();

	/**
	 * @author Aaron Geesink
	 * @brief Size()
	 * Returns the size of the map
	 * @return int
	 */
	int Size()const;								//Returns the size of the map

	/**
	 * @author Aaron Geesink
	 * @brief Empty()
	 * Returns true of the map is empty
	 * @return bool
	 */
	bool Empty();									//Returns true of the map is empty

	/**
	 * @author Aaron Geesink
	 * @brief Find(const int& key)
	 * This function will return the position of the specified key
	 * @return Position<V>
	 */
	Position<V> Find(const int& key);				//This function will return the position of the specified key

	/**
	 * @author Aaron Geesink
	 * @brief Put(const int &key, const V &value)
	 * Puts a position into the map
	 * @return const int &key, const V &value
	 */
	void Put(const int &key, const V &value);		//Puts a position into the map

	/**
	 * @author Aaron Geesink
	 * @brief Erase(const int& key)
	 * This function will remove the position with the specified key
	 * @return const int& key
	 */
	void Erase(const int& key);						//This function will remove the position with the specified key

	/**
	 * @author Aaron Geesink
	 * @brief OutputIO()
	 * Outputs the map IO
	 */
	void OutputIO();

private:
	Position<V> *list;	/// Pointers to the Map's positions

	/**
	 * @author Aaron Geesink
	 * @brief Hash(int key, int j = 0)
	 * Hashes a key for the map
	 * @param int key, int j
	 * @return int
	 */
	int Hash(int key, int j = 0);
	int _size;										///Max size of the list
	int _filled;									///Number of positions in the list
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
