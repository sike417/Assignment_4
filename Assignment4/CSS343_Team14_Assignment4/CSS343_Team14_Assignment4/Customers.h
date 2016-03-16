#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#pragma once
#include "Person.h"

class Customers: public Person
{
public:
    Customers(int id);
    ~Customers();
	void setName(const string& first, const string &last);
	int getID();
	Person getName();

private:
    Person name;
    int id;
};

#endif

