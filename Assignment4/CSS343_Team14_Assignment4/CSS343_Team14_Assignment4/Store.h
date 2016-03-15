#pragma once
#include <fstream>
#include <iostream>
#include "Commands.h"
#include "Inventory.h"
#include "CustomerHash.h"

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
    Inventory store_Inventory;
    CustomerHash customers;
};

