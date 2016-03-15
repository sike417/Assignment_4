#ifndef INVENTORY_H
#define INVENTORY_H

#pragma once

#include "Classics.h"
#include "Comedy.h"
#include "Drama.h"
#include <vector>
using namespace std;

class Inventory
{
    friend class Commands;
public:
    Inventory();
    ~Inventory();
    bool addClassic(const Classics &newClassic);
    bool addComedy(const Comedy &newComedy);
    bool addDrama(const Drama &newDrama);

private:
    vector<Classics> classicList;
    vector<Comedy> comedyList;
    vector<Drama> dramaList;
};

#endif

