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
    bool contains(const key &val, const object &obj);
    void empty();
    bool insert(const key &val, const object &obj) const;
    bool remove(const key &val);

    enum bucketType { EMPTY, DELETED, USED };

private:
    struct bucket
    {
        object element;
        key itemKey;
        bucketType info;
    };

    bucket table[STARTINGSIZE];
    int size;
    float loadFactor;
    int rehashes;

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
    //rehashes = 0;
    //loadFactor = 0;
    //size = table;

    //for (int i = 0; i < )
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
inline bool HashTable<key, object>::contains(const key & val, const object & obj)
{
    return false;
}

template<class key, class object>
inline bool HashTable<key, object>::insert(const key & val, const object & obj) const
{
    return false;
}
