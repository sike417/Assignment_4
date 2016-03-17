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

