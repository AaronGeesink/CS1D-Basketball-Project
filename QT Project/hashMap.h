#pragma once

/**
 * Copyright 2017 HashMap Development Team
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "HashNode.h"
#include "KeyHash.h"
#include <cstddef>

struct MyKeyHash
{
    unsigned long operator()(const int& k) const
    {
        return k % 30;
    }
};

// Hash map class template
template <typename K, typename V, size_t tableSize, typename F = KeyHash<K, tableSize> >
class HashMap
{
public:
    HashMap() :
        table(),
        hashFunc()
    {
    }

    ~HashMap()
    {
        // destroy all buckets one by one
        for (size_t i = 0; i < tableSize; ++i) {
            HashNode<K, V> *entry = table[i];

            while (entry != NULL) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }

            table[i] = NULL;
        }
    }

	V at(const K &key)
    {
        //V value;
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];

        while (entry != NULL) {
            if (entry->getKey() == key) {
                //value = entry->getValue();
                //return true;
				return entry->getValue();
            }
            else
            {
                entry = entry->getNext();
            }
        }
    }

    void insert(const K &key, const V &value)
    {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            entry = new HashNode<K, V>(key, value);

            if (prev == NULL) {
                // insert as first bucket
                table[hashValue] = entry;
                tSize++;

            } else {
                prev->setNext(entry);
                tSize++;
            }

        } else {
            // just update the value
            entry->setValue(value);
        }
    }

    void remove(const K &key)
    {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            // key not found
            return;

        } else {
            if (prev == NULL) {
                // remove first bucket of the list
                table[hashValue] = entry->getNext();

            } else {
                prev->setNext(entry->getNext());
            }

            delete entry;
        }
    }

    const HashMap & operator=(const HashMap * other)
    {
        delete this->table;
        //delete this->hashFunc;
        table = other->table;
        hashFunc = other->hashFunc;
    }
    int size()
    {
        return tSize;
    }

    //HashMap(const HashMap & other);
private:
    // hash table
    HashNode<K, V> *table[tableSize];
    int tSize = 0;
    F hashFunc;
};
