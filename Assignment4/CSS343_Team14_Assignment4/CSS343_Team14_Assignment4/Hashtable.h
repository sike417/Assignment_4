#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
using namespace std;

#pragma once
template <typename object>
class Hashtable
{
public:
    Hashtable();
    ~Hashtable();

    bool contains(const object &obj) const;
    void empty();
    bool insert(const object &obj) const;
    bool remove(const object &obj);

    enum bucketType {EMPTY, DELETED, USED};

private:
    struct bucket
    {
        object element;
        bucketType info;
    };

    vector<bucket> table;
    int size;

    bool isActive(int position) const;



};

#endif

