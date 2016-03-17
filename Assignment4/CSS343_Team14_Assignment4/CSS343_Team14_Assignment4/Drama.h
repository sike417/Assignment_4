#ifndef DRAMA_H
#define DRAMA_H
#pragma once
#include "Movies.h"
class Drama :
    public Movies
{
	friend ostream& operator <<(ostream& outStream, const Drama &obj);
public:
	bool operator<(const Drama &obj);
	bool operator>(const Drama &obj);
	bool operator==(const Drama &obj);
    Drama();
    ~Drama();
};

#endif


