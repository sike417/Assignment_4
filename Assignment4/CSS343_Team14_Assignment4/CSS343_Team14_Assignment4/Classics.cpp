
#include "Classics.h"

Classics::Classics()
{
    type = 'C';
}


Classics::~Classics()
{
}

ostream& operator <<(ostream& outStream, const Classics &obj)
{
	outStream << "C, " << obj.currentStock << ", " << obj.director.firstName << " "
		<< obj.director.lastName << ", " << obj.title << ", " << obj.majorActor.firstName
		<< " " << obj.majorActor.lastName << " " << obj.month << " " << obj.yearReleased;
	return outStream;
}

void Classics::setMajorActor(const Person & majorActor)
{
    this->majorActor = majorActor;  //creates a copy of the major actor variable.
}

void Classics::setMajorActor(const string & firstName, const string & lastName)
{
    this->majorActor.firstName = firstName, this->majorActor.lastName = lastName;
}

bool Classics::setMonth(const int & month)
{
    //month should only be between 1 and 12.
    if (month > 12 || month <= 0)
    {
        this->month = 0;
        return false;
    }
    else
    {
        this->month = month;
        return true;
    }
}

