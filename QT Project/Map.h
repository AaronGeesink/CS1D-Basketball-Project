#ifndef MAP_H_
#define MAP_H_

#include<string>
#include<iostream>

template<typename K, typename V>
class Position													// a (key, value) pair
{

public:
    Position(K key, V value):_key(key), _value(value),
                             next(nullptr), prev(nullptr){}		// Constructor
    const K &Key(){return _key;}								// Returning the key reference
    const V &Value(){return _value;}							// Returning the value reference
    void SetKey(K key){_key = key;}								// Setting a new key
    void SetValue(V value){_value = value;}						// setting a new value
    bool operator==(Position<K, V> &n){
            return n._key == this->_key && n._value == this->_value;
        }
    bool operator!=(Position<K, V> &n)
        {
        return n._key != this->_key || n._value != this->_value;
        }
    Position<K, V> *next;										// Location of the next position
    Position<K, V> *prev;										// Location of the previous position
private:
    K _key;														// key
    V _value;													// value
};


template<typename K, typename V>
class Map
{
public:

    class iterator
    {
    public:
        iterator():p(nullptr){}
        ~iterator(){p = nullptr;}
        Position<K, V> operator*()
        {
            return *p;
        }
        void operator++(int)
        {
            p = p->next;
        }
        void operator--(int)
        {
            p = p->prev;
        }
        bool operator!=(iterator n)
        {
            return n.p != this->p;
        }
        void operator=(iterator n)
        {
            this->p = n.p;
        }
        Position<K, V> *p;
    };
    Map();
    Map(K key, V value);
    ~Map();
    int Size()const;
    bool Empty();
    iterator Find(const K& key);
    iterator Put(const K &key, const V &value);
    void Erase(const K& key);
    void Erase(const V& value);
    iterator begin();
    iterator end();
    void OutputIO();


private:
    Position<K, V> *list;
    Position<K, V> *tail;
    int size;
};

template<typename K, typename V>
Map<K,V>::Map()
{
    list = nullptr;
    tail = nullptr;
    size = 0;
}

template<typename K, typename V>
Map<K,V>::~Map()
{
    Position<K, V> *cptr;
    cptr = list;

    while(list != nullptr)
    {
        cptr = list->next;
        delete list;
        list = cptr;
    }
}


template<typename K, typename V>
Map<K,V>::Map(K key, V value)
{
    list = new Position<K, V> (key, value);
    list->prev = nullptr;
    list->next = nullptr;
    tail = list;
    size = 1;
}

template<typename K, typename V>
int Map<K,V>::Size()const
{
    return size;
}

template<typename K, typename V>
bool Map<K,V>::Empty()
{
    return size == 0;
}

template<typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::Find(const K& key)
{
    bool found = false;
    Map<K,V>::iterator i = begin();
    Map<K,V>::iterator j = end();

    std::cerr << 1 << std::endl;
    while(i != j && !found)
    {

        if(i.p->Key() == key)
        {
            found = true;
            return i;
        }
        else
        {
            i++;
        }

    }

    return i;
}

template<typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::Put(const K &key, const V &value)
{
    Position<K, V> *ptr;
    Map<K,V>::iterator finder = Find(key);

    if( finder != end())
    {
        finder.p->SetValue(value);
    }
    else
    {
        ptr = new Position<K, V> (key, value) ;

        if(!Empty())
        {
            ptr->next = tail->next;
            ptr->prev = tail;
            tail->next = ptr;
            tail = ptr;
            ptr = nullptr;
        }
        else
        {
            list = ptr;
            ptr = nullptr;
            list->prev = nullptr;
            list->next = nullptr;
            tail = list;
        }
        size++;


        finder.p = tail;
    }
    return finder;
}


template<typename K, typename V>
void Map<K,V>::Erase(const K& key)
{
    Position<K, V> *delPtr;
    bool found = false;
    delPtr = list;
    try
    {
        if(Empty())
        {
            throw size;
        }

        while(delPtr != nullptr && !found)
        {

            if(delPtr->Key() == key)
            {
                found = true;
                if(size > 1)
                {
                    if(delPtr == list)
                    {
                        list = list->next;
                        delete list->prev;
                        list->prev = nullptr;
                        delPtr = nullptr;
                    }
                    else if(delPtr == tail)
                    {
                        tail = tail->prev;
                        delete tail->next;
                        tail->next = nullptr;
                        delPtr = nullptr;
                    }
                    else
                    {
                        delPtr->next->prev = delPtr->prev;
                        delPtr->prev->next = delPtr->next;
                        delete delPtr;
                        delPtr = nullptr;
                    }
                }
                else
                {
                    delete list;
                    list = nullptr;
                    tail = nullptr;
                    delPtr = nullptr;
                }

            }
            if(!found)
            {
                delPtr = delPtr->next;
            }

        }
        throw found;
    }
    catch(int e)
    {
        std::cerr << "There are " << e << " position in the list" << std::endl;
    }
    catch(bool b)
    {
        if(b)
        {
            size--;
        }
        else
        {
            std::cerr << "The key was not found\n";
        }
    }

}


template<typename K, typename V>
void Map<K,V>::Erase(const V& value)
{
    Position<K, V> *delPtr;
        bool found = false;
        delPtr = list;
        try
        {
            if(Empty())
            {
                throw size;
            }

            while(delPtr != nullptr && !found)
            {

                if(delPtr->Value() == value)
                {
                    found = true;
                    if(size > 1)
                    {
                        if(delPtr == list)
                        {
                            list = list->next;
                            delete list->prev;
                            list->prev = nullptr;
                            delPtr = nullptr;
                        }
                        else if(delPtr == tail)
                        {
                            tail = tail->prev;
                            delete tail->next;
                            tail->next = nullptr;
                            delPtr = nullptr;
                        }
                        else
                        {
                            delPtr->next->prev = delPtr->prev;
                            delPtr->prev->next = delPtr->next;
                            delete delPtr;
                            delPtr = nullptr;
                        }
                    }
                    else
                    {
                        delete list;
                        list = nullptr;
                        tail = nullptr;
                        delPtr = nullptr;
                    }

                }
                if(!found)
                {
                    delPtr = delPtr->next;
                }

            }
            throw found;
        }
        catch(int e)
        {
            std::cerr << "There are " << e << " position in the list" << std::endl;
        }
        catch(bool b)
        {
            if(b)
            {
                size--;
            }
            else
            {
                std::cerr << "The value was not found\n";
            }
        }

}


template<typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::begin()
{
    Map<K,V>::iterator i;

    i.p = list;

    return i;
}

template<typename K, typename V>
typename Map<K,V>::iterator Map<K,V>::end()
{
    Map<K,V>::iterator i;
    if(size != 0)
    {
        i.p = tail->next;
    }
    else
    {
        i.p = tail;
    }

    return i;
}


template<typename K, typename V>
void Map<K,V>::OutputIO()
{

    for(Position<K, V> *delPtr = list; delPtr != nullptr; delPtr = delPtr->next)
    {
        std::cout << delPtr->Key()<< ": " << delPtr->Value() << std::endl;
    }
}

#endif /* MAP_H_ */
