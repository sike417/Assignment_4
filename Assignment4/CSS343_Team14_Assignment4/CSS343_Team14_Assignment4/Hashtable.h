// ----------------------------------------------------HashTable.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the template for a hash table that will be 
// used for storing both the customer information. The hash table contains a bucket class 
// which holds a variable for a key, an object for storage and the bucketype info which
// will let the program know if the bucket is empty, deleted, or active.  
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef HASH_TABLE_H
#define HASH_TABLE_H
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

    bool contains(const key &val);
    bool contains(const key &val, const object &obj);
    bool retrieve(const key &val, object &);
    void empty();
    bool insert(const key &val, const object &obj);
    bool remove(const key &val, const object & obj);

    enum bucketType { EMPTY, DELETED, ACTIVE };

private:
    class bucket //needed to have it as a class so that i could use the copy constructor.
    {
    public:
        object element;
        key itemKey;
        bucketType info;
        bucket()
        {
            info = EMPTY;
            itemKey = 0;
            element = NULL;
        }
        ~bucket()
        {

        }
    };

    vector<bucket> table;
    int currentSize;
    float loadFactor;
    int collisions;

    int hashFunction(const key &val) const;            //hash function
    int secondHashFunction(const key &val) const;
    int findNextPrime(int current);    //finds the next prime number that comes after the current inputted number
    int findVal(const key &val, const object &obj);
    bool isPrime(const int &num);
    void rehash(int num);                          //rehashes the hash table with an expanded size
};

#endif

template<class key, class object>
HashTable<key, object>::HashTable()
{
    empty();
}

template<class key, class object>
HashTable<key, object>::~HashTable()
{

}

template<class key, class object>
inline bool HashTable<key, object>::contains(const key & val)
{
    int elementNum = hashFunction(val);

    while ((table[elementNum].info == ACTIVE || table[elementNum].info == DELETED))
    {
        if (table[elementNum].info == ACTIVE && table[elementNum].itemKey == val)
        {
            collisions = 0;
            return true;
        }
        collisions += 1;
        elementNum = secondHashFunction(val);
    }
    collisions = 0;
    return false;
}

template<class key, class object>
inline bool HashTable<key, object>::contains(const key & val, const object & obj)
{
    int elementNum = hashFunction(val);

    while ((table[elementNum].info == ACTIVE || table[elementNum].info == DELETED))
    {
        if (table[elementNum].info == ACTIVE && table[elementNum].element == obj)
        {
            collisions = 0;
            return true;
        }
        collisions += 1;
        elementNum = secondHashFunction(val)
    }
    collisions = 0;
    return false;
}

template<class key, class object>
inline bool HashTable<key, object>::retrieve(const key & val, object &customer)
{
    int elementNum = hashFunction(val);

    while ((table[elementNum].info == ACTIVE || table[elementNum].info == DELETED))
    {
        if (table[elementNum].info == ACTIVE && table[elementNum].itemKey == val)
        {
            collisions = 0;
            customer = table[elementNum].element;
            return true;
        }
        collisions += 1;
        elementNum = secondHashFunction(val);
    }
    collisions = 0;
    return false;
}

template<class key, class object>
inline void HashTable<key, object>::empty()
{
    currentSize = collisions = loadFactor = 0;
    for (int i = 0; i < table.size(); i++)
    {
        table[i].info = EMPTY;
        table[i].element = NULL;
        table[i].itemKey = 0;
    }
    table.resize(STARTINGSIZE);
}

template<class key, class object>
inline bool HashTable<key, object>::insert(const key & val, const object & obj)
{
    int elementNum = hashFunction(val);
    bucket tempStorage = table[elementNum];

    while ((tempStorage.info != EMPTY && tempStorage.info != DELETED) && tempStorage.element != obj)
    {
        collisions += 1;
        elementNum = secondHashFunction(val);
        tempStorage = table[elementNum];
    }

    if (tempStorage.info != ACTIVE)//assume object is not in hash table
    {
        table[elementNum].info = ACTIVE;
        table[elementNum].element = obj;
        table[elementNum].itemKey = val;

        currentSize += 1;
        loadFactor = static_cast<float>(currentSize) / table.size();

        if (loadFactor > .5)
            rehash(table.size() * 2);
        collisions = 0;
        return true;
    }
    else
    {
        collisions = 0;
        return false;
    }
}

template<class key, class object>
inline bool HashTable<key, object>::remove(const key & val, const object & obj)
{
    int elementNumber = findVal(val, obj);

    if (elementNumber == -1 || elementNumber >= table.size())
        return false;
    else
    {
        currentSize -= 1;
        loadFactor = static_cast<float>(currentSize) / table.size();
        table[elementNumber].info = DELETED;
    }
}

template<class key, class object>
inline int HashTable<key, object>::hashFunction(const key & val) const
{
    return (val * 13) % table.size();
}

template<class key, class object>
inline int HashTable<key, object>::secondHashFunction(const key & val) const
{
    return (hashFunction(val) + collisions * (7 - (val % 7)));
}

template<class key, class object>
inline int HashTable<key, object>::findNextPrime(int current)
{
    while(true)
    {
        if (isPrime(++current) == true)
            break;
        else
            continue;
    }
    return current;
}

template<class key, class object>
inline int HashTable<key, object>::findVal(const key & val, const object & obj)
{
    int elementNum = hashFunction(val);

    while ((table[elementNum].info == ACTIVE || table[elementNum].info == DELETED))
    {
        if (table[elementNum].info == ACTIVE && table[elementNum].element == obj)
        {
            collisions = 0;
            return elementNum;
        }
        collisions += 1;
        elementNum = secondHashFunction(val)
    }
    collisions = 0;
    return -1;
}

template<class key, class object>
inline bool HashTable<key, object>::isPrime(const int &num)
{

    if (num == 2 || num == 3)
        return true;
    else if (num % 2 == 0 || num % 3 == 0)
        return false;

    for (int i = 3; i < num / 2; i += 2)
    {
        if (num % (i - 1) == 0)
            return false;
        else if (num % (i + 1) == 0)
            return false;
    }

    return true;
}

template<class key, class object>
inline void HashTable<key, object>::rehash(int num)
{
    num = findNextPrime(num + 1);

    vector<bucket> oldTable = table;
    table.resize(num);

    for (int i = 0; i < table.size(); i++)
    {
        table[i].info = EMPTY;
        table[i].element = NULL;
        table[i].itemKey = 0;
    }

    currentSize = 0;
    loadFactor = 0;

    for (int i = 0; i < oldTable.size(); i++)
    {
        if (oldTable[i].info == ACTIVE)
            insert(oldTable[i].itemKey, oldTable[i].element);
    }
}
