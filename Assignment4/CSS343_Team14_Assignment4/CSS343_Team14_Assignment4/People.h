#ifndef PEOPLE_H
#define PEOPLE_H

#pragma once
#include <string>
using namespace std;
struct person
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

