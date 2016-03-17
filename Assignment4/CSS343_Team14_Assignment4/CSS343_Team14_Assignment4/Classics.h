#ifndef CLASSICS_H
#define CLASSICS_H
#pragma once
#include <iostream>
#include <string>
#include "Movies.h"

class Classics :
    public Movies
{
	friend ostream& operator <<(ostream& outStream, const Classics &obj);
public:
	bool operator<(const Classics &obj);
	bool operator>(const Classics &obj);
	bool operator==(const Classics &obj);
	void setMajorActor(const Person &majorActor);
	void setMajorActor(const string &firstName, const string &lastName);
	bool setMonth(const int &month);

    Classics();
    ~Classics();
private:
    Person majorActor;
    int month;
};

#endif
