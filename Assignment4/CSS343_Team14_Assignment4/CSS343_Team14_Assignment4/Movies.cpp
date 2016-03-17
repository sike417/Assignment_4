#include "Movies.h"



Movies::Movies()
{
}


Movies::~Movies()
{
}

bool Movies::addStock(const int & num)
{
	currentStock += num;
	return true;
}

bool Movies::removeStock(const int & num)
{
	int temp = (currentStock - num);
	if (temp < 0)
	{
		return false;
	}

	currentStock = temp;
	return true; 

}

Person Movies::getDirector() const
{
	return director;
}

string Movies::getTitle() const
{
	return title;
}

int Movies::getYearReleased() const
{
	return yearReleased;
}

void Movies::setTitle(const string & title)
{
    this->title = title;
}

bool Movies::setStock(const int & stock)
{
    if (stock < 0)
    {
        initialStock = 0;   //invalid input, defaults to 0
        return false;
    }
    else
        initialStock = stock, currentStock = initialStock;
    return true;
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

void Movies::setReleaseYear(const int & releaseYear)
{
    this->yearReleased = releaseYear;
}