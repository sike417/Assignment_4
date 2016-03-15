#ifndef DRAMA_H
#define DRAMA_H
#pragma once
#include "Movies.h"
class Drama :
    public Movies
{
    friend class Commands;
public:
    using Movies::operator<;
    using Movies::operator>;
    using Movies::operator==;
    Drama();
    ~Drama();
};

#endif


