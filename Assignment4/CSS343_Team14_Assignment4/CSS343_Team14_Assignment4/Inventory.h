// ----------------------------------------------------Inventory.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the inventory of movies that the store
// currently has. This class has a vector for all of the movie types so that they
// can be stored by each specific type of movie. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
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
	friend ostream& operator <<(ostream& outStream, const Inventory &obj);

public:
    Inventory();
    ~Inventory();
    bool addClassic(const Classics &newClassic);
    bool addComedy(const Comedy &newComedy);
    bool addDrama(const Drama &newDrama);
	bool findClassic(const int &month, const int &year, const Person &majorActor);
	bool findComedy(const string &title, const int &year);
	bool findDrama(const Person &director, const string &title);

private:
    vector<Classics> classicList;
    vector<Comedy> comedyList;
    vector<Drama> dramaList;
};

#endif

