#pragma once
#include "Movies.h"
class Comedy :
    public Movies
{
    friend class Commands;
public:
    using Movies::operator<;
    using Movies::operator>;
    using Movies::operator==;

    Comedy();
    ~Comedy();

private:

};

