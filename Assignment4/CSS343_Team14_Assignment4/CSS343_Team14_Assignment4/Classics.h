// ----------------------------------------------------Classics.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the genre movie type 'Classics' which
// inherits from the movie class. The class overloaded comparison operators which 
// will be used for sorting. It also includes an output operator that will be able to
// output everything in the correct format.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef CLASSICS_H
#define CLASSICS_H
#pragma once
#include <iostream>
#include <string>
#include "Movies.h"

class Classics :
    public Movies
{
	friend ostream& operator <<(ostream& outStream, const Classics &obj);
public:
	bool operator<(const Classics &obj) const;
	bool operator>(const Classics &obj) const;
	bool operator==(const Classics &obj) const;
	void setMajorActor(const Person &majorActor);
	void setMajorActor(const string &firstName, const string &lastName);
	bool setMonth(const int &month);
	int getMonth() const;
	Person getMajorActor() const;

    Classics();
    ~Classics();
private:
    Person majorActor;
    int month;
};

#endif
