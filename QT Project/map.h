#ifndef MAPH_H_
#define MAPH_H_
#define TABLE_SIZE 10

#include<iostream>

// Hash node class template
template <typename K, typename V>
class HashNode {
public:
	HashNode(const K &key, const V &value) :
	key(key), value(value), next(NULL) {
	}

	K getKey() const {
		return key;
	}

	V getValue() const {
		return value;
	}

	void setValue(V value) {
		HashNode::value = value;
	}

	HashNode *getNext() const {
		return next;
	}

	void setNext(HashNode *next) {
		HashNode::next = next;
	}

private:
	// key-value pair
	K key;
	V value;
	// next bucket with the same key
	HashNode *next;
};

// Default hash function class
template <typename K>
struct KeyHash {
	int operator()(const K& key) const
	{
		return key % TABLE_SIZE;
	}
};

// Hash map class template
template <typename K, typename V, typename F = KeyHash<K>>
class HashMap {
public:
	HashMap() {
		// construct zero initialized hash table of size
		table = new HashNode<K, V> *[TABLE_SIZE]();
	}

	HashMap(const HashMap<K, V, F> &other)
	{
		this->size = other.size;

		for (int i = 0; i < TABLE_SIZE; ++i)
		{
			*(table[i]) = other.*(table[i]);
		}

	}

	~HashMap() {
		// destroy all buckets one by one
		for (int i = 0; i < TABLE_SIZE; ++i) {
			HashNode<K, V> *entry = table[i];
			while (entry != NULL) {
				HashNode<K, V> *prev = entry;
				entry = entry->getNext();
				delete prev;
			}
			table[i] = NULL;
		}
		// destroy the hash table
		delete [] table;
	}

	bool get(int key, V &value) {
		int hashValue = hashFunc(key);
		qDebug() << hashFunc(key) << "\n";
		HashNode<K, V> *entry = table[hashValue];

		qDebug() << key << "\n";
		while (entry != NULL) {
			qDebug() << entry->getKey()  << "\n";
			if (entry->getKey() == key) {
				value = entry->getValue();
				return true;
			}
			entry = entry->getNext();
		}
		return false;
	}

	void put(const int key, const V &value) {
		int hashValue = hashFunc(key);
		qDebug() << key;
		qDebug() << hashValue;
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
				size++;
			} else {
				prev->setNext(entry);
				size++;
			}
		} else {
			// just update the value
			entry->setValue(value);
		}
	}

	void remove(const K &key) {
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
		}
		else {
			if (prev == NULL) {
				// remove first bucket of the list
				table[hashValue] = entry->getNext();
			} else {
				prev->setNext(entry->getNext());
			}
			delete entry;
			size--;
		}
	}

	int getSize()
	{
		return size;
	}

private:
	// hash table
	HashNode<K, V> **table;
	F hashFunc;
	int size = 0;
};

#endif /* MAPH_H_ */
