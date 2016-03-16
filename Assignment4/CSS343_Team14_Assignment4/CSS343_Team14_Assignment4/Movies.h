#ifndef MOVIES_H
#define MOVIES_H
#pragma once
#include "Commands.h"
#include "People.h"
#include <string>
using namespace std;

class Movies
{
    friend class Commands;
public:
    Movies();
    virtual ~Movies();
 
    bool addStock(const int& num);
    bool removeStock(const int& num);

    person getDirector();
    string getTitle();
    int getYearReleased();
private:
    string title;
    int initialStock;
    int currentStock;
    person director;
    int yearReleased;
};

#endif

