// Hash node class template
const static int TABLE_SIZE = 30;

template <typename K, typename V>
class HashNode {
public:
    HashNode(const K &key, const V &value) :
    key(key), value(value), next(nullptr) {
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
    unsigned long operator()(const K& key) const
    {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
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

    ~HashMap() {
        // destroy all buckets one by one
        if(table != nullptr)
        {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            HashNode<K, V> *entry = table[i];
            while (entry != nullptr) {
                HashNode<K, V> *prev = entry;
                entry = entry->getNext();
                delete prev;
            }
            table[i] = nullptr;
        }
        // destroy the hash table
        delete [] table;
        }
    }

    V at(const K &key) {
        V value;
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];

        while (entry != nullptr) {
            if (entry->getKey() == key) {
                //value = entry->getValue();
                break;
                //return true;
            }
            else
                entry = entry->getNext();
        }
        return entry->getValue();
    }

    void insert(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == nullptr) {
            entry = new HashNode<K, V>(key, value);
            if (prev == nullptr) {
                // insert as first bucket
                table[hashValue] = entry;
            } else {
                prev->setNext(entry);
            }
        } else {
            // just update the value
            entry->setValue(value);
        }
    }

    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = nullptr;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != nullptr && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == nullptr) {
            // key not found
            return;
        }
        else {
            if (prev == nullptr) {
                // remove first bucket of the list
                table[hashValue] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            delete entry;
        }
    }

private:
    // hash table
    HashNode<K, V> **table;
    F hashFunc;
};
/* EXAMPLE IMPLIMENTATION*/
/*HashMap<int, string, MyKeyHash> hmap;
hmap.put(1, "val1");
hmap.put(2, "val2");
hmap.put(3, "val3");

string value;
hmap.get(2, value);
cout << value << endl;
bool res = hmap.get(3, value);
if (res)
    cout << value << endl;
hmap.remove(3);
res = hmap.get(3, value);
if (res)
    cout << value << endl;*/
