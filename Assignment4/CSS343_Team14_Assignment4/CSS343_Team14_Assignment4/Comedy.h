#pragma once
#include "Movies.h"
class Comedy :
    public Movies
{
    friend class Commands;
public:
    Comedy();
    ~Comedy();
};

