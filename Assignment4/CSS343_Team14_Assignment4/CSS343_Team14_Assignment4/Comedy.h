// ----------------------------------------------------Comedy.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the genre movie type 'Comedy' which
// inherits from the movie class. The class overloaded comparison operators which 
// will be used for sorting. It also includes an output operator that will be able to
// output everything in the correct format.
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H
#pragma once
#include "Movies.h"
class Comedy :
    public Movies
{
    friend class Commands;
	friend ostream& operator <<(ostream& outStream, const Comedy &obj);

public:
	bool operator<(const Comedy &obj) const;
	bool operator>(const Comedy &obj) const;
	bool operator==(const Comedy &obj) const;

    Comedy();
    ~Comedy();

private:

};

#endif
