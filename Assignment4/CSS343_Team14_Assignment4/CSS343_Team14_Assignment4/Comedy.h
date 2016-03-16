#pragma once
#include "Movies.h"
class Comedy :
    public Movies
{
    friend class Commands;
	friend ostream& operator <<(ostream& outStream, const Comedy &obj);

public:
    using Movies::operator<;
    using Movies::operator>;
    using Movies::operator==;

    Comedy();
    ~Comedy();

private:

};

