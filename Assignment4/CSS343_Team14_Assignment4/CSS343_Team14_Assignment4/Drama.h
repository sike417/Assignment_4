#ifndef DRAMA_H
#define DRAMA_H
#pragma once
#include "Movies.h"
class Drama :
    public Movies
{
    friend class Commands;
public:
	bool operator<(const Drama &obj);
	bool operator>(const Drama &obj);
    Drama();
    ~Drama();
};

#endif


