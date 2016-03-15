#ifndef MOVIES_H
#define MOVIES_H

#pragma once
#include "Commands.h"
#include "Person.h"
#include <string>
using namespace std;

class Movies
{
    friend class Commands;
public:
    Movies();
    virtual ~Movies();
 
    bool addStock();
    bool removeStock();

    Person getDirector();
    string getTitle();
    int getYearReleased();

    bool operator<(const Movies &obj);
    bool operator>(const Movies &obj);
    bool operator==(const Movies &obj);

    void setTitle();
    bool setStock();
    int setDirector();
    bool setReleaseYear();
    bool setType(char type); // can only set once
    //void setType();

protected:
    string title;
    int initialStock;
    int currentStock;
    Person director;
    int yearReleased;
    char type;
};

#endif

