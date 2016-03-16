#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<class key, class object>
class HashTable
{
public:
    HashTable();
    ~HashTable();

    bool contains(const key &key) const;
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

    vector<bucket> table;
    int size;

    bool isActive(int position) const;      //checks if a given bucket is currently being used.
    int Hash(const key &val) const;            //hash function
    int findlocal (const key &val, const object &obj) const;       //finds the location of an object
    void rehash();                          //rehashes the hash table with an expanded size
};

template<class key, class object>
HashTable<key, object>::HashTable()
{

}

template<class key, class object>
HashTable<key, object>::~HashTable()
{

}