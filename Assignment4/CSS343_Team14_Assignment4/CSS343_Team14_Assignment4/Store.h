#ifndef STORE_H
#define STORE_H

#pragma once
#include <fstream>
#include <iostream>
#include "Inventory.h"
#include "HashTable.h"
#include "Customers.h"
using namespace std;

class Store
{
public:
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

    //read methods
    void readReturn(ifstream &infile);
    void readBorrow(ifstream &infile);

    //action methods
    bool executeDramaBorrow(const int id, const Person &director, const string &title);
    bool executeComedyBorrow(const int &id, const string &title, const int year);
    bool executeClassicBorrow(const int &id, const int month, const int year, Person majorActor);

    bool executeDramaReturn(const int &id, const Person &director, const string &title);
    bool executeComedyReturn(const int &id, const string &title, const int year);
    bool executeClassicReturn(const int &id, const int month, const int year, Person majorActor);

    bool displayHistory(const int id);
    void displayInventory();
};

#endif