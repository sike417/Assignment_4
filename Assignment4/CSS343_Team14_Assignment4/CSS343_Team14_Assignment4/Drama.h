#pragma once
#include "Movies.h"
class Drama :
    public Movies
{
    friend class Commands;
public:
    Drama();
    ~Drama();
};

