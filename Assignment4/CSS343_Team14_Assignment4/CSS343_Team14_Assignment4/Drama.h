// ----------------------------------------------------Drama.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the genre movie type 'Drama' which
// inherits from the movie class. The class overloaded comparison operators which 
// will be used for sorting. It also includes an output operator that will be able to
// output everything in the correct format.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef DRAMA_H
#define DRAMA_H
#pragma once
#include "Movies.h"
class Drama :
    public Movies
{
	friend ostream& operator <<(ostream& outStream, const Drama &obj);
public:
	bool operator<(const Drama &obj) const;
	bool operator>(const Drama &obj) const;
	bool operator==(const Drama &obj) const;
    Drama();
    ~Drama();
};

#endif


