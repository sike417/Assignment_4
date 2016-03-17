// ----------------------------------------------------Person.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent People. This class contains a struct
// of Person which contains a first name and a last name. This class is used by the 
// children class of customer. In the beginning of our design this class was not included
// but we decided to add it to further implement 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef PEOPLE_H
#define PEOPLE_H

#pragma once
#include <string>
using namespace std;

struct Person
{
    string firstName;
    string lastName;
};

class People
{
    friend class Commands;
public:
    People();
    ~People();
};

#endif

