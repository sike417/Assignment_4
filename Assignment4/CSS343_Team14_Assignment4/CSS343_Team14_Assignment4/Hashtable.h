#pragma once

#include <iostream>
#include <vector>

using namespace std;
const int STARTINGSIZE = 17;

template<class key, class object>
class HashTable
{
public:
    HashTable();
    ~HashTable();

    bool contains(const key &val) const;
    bool contains(const key &val, const object &obj) const;
    void empty();
    bool insert(const key &val, const object &obj);
    bool remove(const key &val);

    enum bucketType { EMPTY, DELETED, ACTIVE };

private:
    struct bucket
    {
        object element;
        key itemKey;
        bucketType info;
    };

    vector<bucket> table;
    int currentSize;
    float loadFactor;
    int collisions;

    bool isActive(int position) const;      //checks if a given bucket is currently being used.
    int hashFunction(const key &val) const;            //hash function
    int secondHashFunction(const key &val);
    int findlocal (const key &val, const object &obj) const;       //finds the location of an object
    int findNextPrime(const int &current) const;    //finds the next prime number that comes after the current inputted number
    void rehash();                          //rehashes the hash table with an expanded size
};

template<class key, class object>
HashTable<key, object>::HashTable()
{
    empty();
    //table
}

template<class key, class object>
HashTable<key, object>::~HashTable()
{

}

template<class key, class object>
inline bool HashTable<key, object>::contains(const key & val) const
{
    return false;
}

template<class key, class object>
inline bool HashTable<key, object>::contains(const key & val, const object & obj) const
{
    return false;
}

template<class key, class object>
inline void HashTable<key, object>::empty()
{
    currentSize = collisions = loadFactor = 0;
    for (int i = 0; i < table.size(); i++)
    {
        table[i].info = EMPTY;
    }
}

template<class key, class object>
inline bool HashTable<key, object>::insert(const key & val, const object & obj)
{
    int elementNum = hashFunction(val);
    bucket tempStorage = table[elementNum];

    while (tempStorage.info != EMPTY ||tempStorage.info != DELETED && tempStorage.element != obj)
    {
        collisions += 1;
        elementNum = secondHashFunction(val);
    }

    if (tempStorage.info != ACTIVE)//assume object is not in hash table
    {
        table[elementNum].info = ACTIVE;
        table[elementNum].element = obj;
        table[elementNum].itemKey = val;
        return true;
    }
    else
    {
        return false;
    }
}

template<class key, class object>
inline int HashTable<key, object>::hashFunction(const key & val) const
{
    return (val * 13) % table.size();
}

template<class key, class object>
inline int HashTable<key, object>::secondHashFunction(const key & val)
{
    return (hashFunction(val) + collisions * (7 - (val % 7)));
}
