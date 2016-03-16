#include "Movies.h"



Movies::Movies()
{
}


Movies::~Movies()
{
}

Person Movies::getDirector()
{
	return director;
}

string Movies::getTitle()
{
	return title;
}

int Movies::getYearReleased()
{
	return yearReleased;
}

void Movies::setTitle(const string & title)
{
    this->title = title;
}

void Movies::setStock(const int & stock)
{
    currentStock = stock;
}

void Movies::setDirector(const Person & director)
{
    this->director = director;
}

void Movies::setDirector(const string & first, const string & last)
{
    director.firstName = first;
    director.lastName = last;
}

bool Movies::setReleaseYear(int & releaseYear)
{
    return false;
}

void Movies::setType(char type)
{
    this->type = type;
}
