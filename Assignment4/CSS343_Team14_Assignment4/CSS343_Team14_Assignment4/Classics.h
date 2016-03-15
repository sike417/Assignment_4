#ifndef CLASSICS_H
#define CLASSICS_H
#pragma once
#include <iostream>
#include <string>
#include "Movies.h"
class Classics :
    public Movies
{
    friend class Commands;
public:
	bool operator<(const Classics &obj);
	bool operator>(const Classics &obj);
    Classics();
    ~Classics();
private:
	string majorActor;
	int releaseDate;

};

#endif
