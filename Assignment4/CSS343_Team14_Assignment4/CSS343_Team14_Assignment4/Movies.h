#ifndef MOVIES_H
#define MOVIES_H

#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Movies
{

public:
    Movies();
    virtual ~Movies();
 
    bool addStock(const int& num);
    bool removeStock(const int& num);

    Person getDirector();
    string getTitle();
    int getYearReleased();

    bool operator<(const Movies &obj);
    bool operator>(const Movies &obj);
    bool operator==(const Movies &obj);

    void setTitle(const string &title);
    bool setStock(const int &stock);
    void setDirector(const Person &director);
    void setDirector(const string &first, const string &last);
    void setReleaseYear(const int &releaseYear);

protected:
    string title;
    int initialStock;
    int currentStock;
    Person director;
    int yearReleased;
    char type;
};

#endif

