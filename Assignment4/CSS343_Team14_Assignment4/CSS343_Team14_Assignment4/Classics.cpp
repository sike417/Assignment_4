
#include "Classics.h"
#include <sstream>

Classics::Classics()
{
    type = 'C';
}


Classics::~Classics()
{
}

ostream& operator <<(ostream& outStream, const Classics &obj)
{
	outStream << string("C, ") << static_cast<ostringstream*>(&(ostringstream() << obj.currentStock))->str() << string(", ") << obj.director.firstName << string(" ")
		<< obj.director.lastName << string(", ") << obj.title << string(", ") << obj.majorActor.firstName
		<< " " << obj.majorActor.lastName << string(" ") << static_cast<ostringstream*>(&(ostringstream() << obj.month))->str() << string(" ") << static_cast<ostringstream*>(&(ostringstream() << obj.yearReleased))->str();
	return outStream;
}

bool Classics::operator<(const Classics & obj) const
{
	if (this->yearReleased == obj.yearReleased)
	{
		if (this->month == obj.month)
		{
			if (this->majorActor.firstName == obj.majorActor.firstName)
			{
				if (this->majorActor.lastName < obj.majorActor.lastName)
				{
					return true;
				}
			}
		}
	}

	else if (this->yearReleased == obj.yearReleased)
	{
		if (this->month == obj.month)
		{
			if (this->majorActor.firstName < obj.majorActor.firstName)
			{
				return true;
			}
		}
	}

	else if (this->yearReleased == obj.yearReleased)
	{
		if (this->month < obj.month)
		{
			return true;
		}
	}

	else if (this->yearReleased < obj.yearReleased)
	{
		return true;
	}

	return false;
}

bool Classics::operator>(const Classics & obj) const
{
	if (this->yearReleased == obj.yearReleased)
	{
		if (this->month == obj.month)
		{
			if (this->majorActor.firstName == obj.majorActor.firstName)
			{
				if (this->majorActor.lastName > obj.majorActor.lastName)
				{
					return true;
				}
			}
		}
	}

	else if (this->yearReleased == obj.yearReleased)
	{
		if (this->month == obj.month)
		{
			if (this->majorActor.firstName > obj.majorActor.firstName)
			{
				return true;
			}
		}
	}

	else if (this->yearReleased == obj.yearReleased)
	{
		if (this->month > obj.month)
		{
			return true;
		}
	}

	else if (this->yearReleased > obj.yearReleased)
	{
		return true;
	}

	return false;
}

bool Classics::operator==(const Classics & obj) const
{
	if (this->yearReleased == obj.yearReleased && this->month == obj.month
		&& this->majorActor.firstName == obj.majorActor.firstName
		&& this->majorActor.lastName == obj.majorActor.lastName)
	{
		return true;
	}

	return false;
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

int Classics::getMonth() const
{
	return month;
}

Person Classics::getMajorActor() const
{
	return majorActor;
}

