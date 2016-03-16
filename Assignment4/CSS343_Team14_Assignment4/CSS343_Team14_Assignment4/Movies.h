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

    void setTitle(const string &title);
    bool setStock(const int &stock);
    bool setDirector(const Person &director);
    bool setDirector(const string &first, const string &last);
    bool setReleaseYear(int &releaseYear);
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

