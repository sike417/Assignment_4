#ifndef STORE_H
#define STORE_H

#pragma once
#include <fstream>
#include <iostream>
#include "Commands.h"
#include "Inventory.h"
#include "HashTable.h"
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
    HashTable<int, Customers> customers;
    void LoadMovieFromFile(ifstream &infile);
    void LoadCustomersFromFile(ifstream &infile);
    void LoadTransactionsFromFile(ifstream &infile);
    void retrieveClassic(ifstream &infile, Classics &classic, string &data);
    void retrieveComedy(ifstream &infile, Comedy &comedy, string &data);
    void retrieveDrama(ifstream &infile, Drama &drama, string &data);
};

#endif