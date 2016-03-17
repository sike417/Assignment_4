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
    class bucket //needed to have it as a class so that i could use the copy constructor.
    {
    public:
        object element;
        key itemKey;
        bucketType info;
        bucket()
        {

        }
        ~bucket()
        {

        }
    };

    vector<bucket> table;
    int currentSize;
    float loadFactor;
    int collisions;

    bool isActive(int position) const;      //checks if a given bucket is currently being used.
    int hashFunction(const key &val) const;            //hash function
    int secondHashFunction(const key &val);
    int findlocal (const key &val, const object &obj) const;       //finds the location of an object
    int findNextPrime(int &current) const;    //finds the next prime number that comes after the current inputted number
    bool isPrime(const int &num);
    void rehash(int num);                          //rehashes the hash table with an expanded size
};

template<class key, class object>
HashTable<key, object>::HashTable()
{
    empty();
    bucket newBucket;
    table.push_back(newBucket);
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
        currentSize += 1;
        loadFactor = currentSize / table.size();

        if (loadFactor > .5)
            rehash(table.size() * 2);
        collisions = 0;
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

template<class key, class object>
inline int HashTable<key, object>::findNextPrime(int & current) const
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
inline bool HashTable<key, object>::isPrime(const int & num)
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
    
}
