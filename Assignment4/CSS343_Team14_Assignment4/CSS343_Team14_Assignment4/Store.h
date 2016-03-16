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
    Store(const string &movieListFileName);
    Store(ifstream &movieList);
    Store(ifstream &movieList, ifstream &customerList);
    Store(const string &movieListFileName, const string &customerListFileName);
    Store(ifstream &movieList, ifstream &customerList, ifstream &transactionList);
    Store(const string &movieListFileName, const string &customerListFileName, const string &transactionListFileName);
    virtual ~Store();

    void LoadMovieFromFile(ifstream &infile);
    void LoadCustomersFromFile(ifstream &infile);
    void LoadTransactionsFromFile(ifstream &infile);

private:
    Inventory storeInventory;
    HashTable<int, Customers> customers;
    void retrieveClassic(ifstream &infile, Classics &classic, string &data);
    void retrieveComedy(ifstream &infile, Comedy &comedy, string &data);
    void retrieveDrama(ifstream &infile, Drama &drama, string &data);
};

#endif