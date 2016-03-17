// ----------------------------------------------------Customers.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the customer class which will inherit
// from the person class. This class is used to store the id, first name, and last name
// of the customer. The class has overloaded comparison operators to check if the
// customer is already in the database. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#pragma once
#include "Person.h"
#include "History.h"
#include "Inventory.h"

class Customers: public Person
{
public:
    Customers();
    Customers(int id);
    ~Customers();
    bool operator==(const Customers &obj);
    bool operator!=(const Customers &obj);
	void setName(const string& first, const string &last);
	int getID();
	Person getName();
  void displayHistory();
private:
    History history;
    Inventory borrowed;
    Person name;
    int id;
};

#endif

