#pragma once
#include <fstream>
#include <iostream>
#include "Inventory.h"
#include "CustomerHash.h"

using namespace std;

class Store
{
public:
    Store();
    Store(string movieListFileName);
    Store(ifstream &movieList);
    virtual ~Store();



private:
    Inventory store_Inventory;
    CustomerHash customers;
};

