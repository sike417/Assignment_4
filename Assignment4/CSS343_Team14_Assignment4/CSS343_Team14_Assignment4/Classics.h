#pragma once
#include "Movies.h"
class Classics :
    public Movies
{
    friend class Commands;
public:
    Classics();
    ~Classics();
};

