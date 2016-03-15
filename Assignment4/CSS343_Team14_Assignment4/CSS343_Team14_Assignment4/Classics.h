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
<<<<<<< HEAD
    person majorActor;
    int month
=======
	string majorActor;
	int releaseDate;

>>>>>>> a0195c6e591225f9fd751ed97264f797fecf5a6d
};

#endif
