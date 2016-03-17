// ----------------------------------------------------Movies.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the movie object which will act 
// as a base class for the specific genres of movies. This class contains 3 pure
// virtual functions that each of our child classes will be implementing to stort
// in their own specific format. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIES_H
#define MOVIES_H

#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Movies
{

public:
    Movies();
    virtual ~Movies();
 
    bool addStock(const int& num);
    bool removeStock(const int& num);

    Person getDirector() const;
    string getTitle() const;
    int getYearReleased() const;

    void setTitle(const string &title);
    bool setStock(const int &stock);
    void setDirector(const Person &director);
    void setDirector(const string &first, const string &last);
    void setReleaseYear(const int &releaseYear);

protected:
    string title;
    int initialStock;
    int currentStock;
    Person director;
    int yearReleased;
    char type;
};

#endif

