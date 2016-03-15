#pragma once
#include "Movies.h"
class Comedy :
    public Movies
{
    friend class Commands;
public:
	bool operator<(const Comedy &obj);
	bool operator>(const Comedy &obj);
    Comedy();
    ~Comedy();

private:

};

