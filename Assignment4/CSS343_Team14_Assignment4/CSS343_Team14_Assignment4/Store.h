#ifndef STORE_H
#define STORE_H

#pragma once
#include <fstream>
#include <iostream>
#include "Commands.h"
#include "Inventory.h"
#include "Hashtable.h"
#include "Customers.h"

using namespace std;

class Store
{
public:
    friend class Commands;
    Store();
    Store(string movieListFileName);
    Store(ifstream &movieList);
    virtual ~Store();

private:
    Inventory storeInventory;
    Hashtable<Customers> customers;
};

#endif