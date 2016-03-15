#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#pragma once
#include "People.h"

class Customers: public People
{
public:
    Customers(int id);
    ~Customers();
private:
    person name;
    int id;
};

#endif

