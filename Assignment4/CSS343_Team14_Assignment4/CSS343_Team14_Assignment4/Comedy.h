#pragma once
#include "Movies.h"
class Comedy :
    public Movies
{
    friend class Commands;
	friend ostream& operator <<(ostream& outStream, const Comedy &obj);

public:
	bool operator<(const Comedy &obj);
	bool operator>(const Comedy &obj);
	bool operator==(const Comedy &obj);

    Comedy();
    ~Comedy();

private:

};

