#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#pragma once
#include "Person.h"

class Customers: public Person
{
public:
    Customers(int id);
    ~Customers();
private:
    Person name;
    int id;
};

#endif

