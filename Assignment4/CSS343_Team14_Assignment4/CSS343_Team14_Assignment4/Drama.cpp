#include "Drama.h"
#include <sstream>


Drama::Drama()
{
    type = 'D';
}

Drama::~Drama()
{
}

ostream& operator <<(ostream& outStream, const Drama &obj)
{
	outStream << string("D, ") << static_cast<ostringstream*>(&(ostringstream() << obj.currentStock))->str() << string(", ") << obj.director.firstName << string(" ")
		<< obj.director.lastName << string(", ") << obj.title << string(", ") << static_cast<ostringstream*>(&(ostringstream() << obj.yearReleased))->str();
	return outStream;

}

bool Drama::operator<(const Drama & obj) const
{
	if (this->director.firstName == obj.director.firstName)
	{
		if (this->director.lastName == obj.director.lastName)
		{
			if (this->title < obj.title)
			{
				return true;
			}
		}
	}

	else if (this->director.firstName == obj.director.firstName)
	{
		if (this->director.lastName < obj.director.lastName)
		{
			return true;
		}
	}

	else if (this->director.firstName < obj.director.firstName)
	{
		return true;
	}

	return false;
}

bool Drama::operator>(const Drama & obj) const
{
	if (this->director.firstName == obj.director.firstName)
	{
		if (this->director.lastName == obj.director.lastName)
		{
			if (this->title > obj.title)
			{
				return true;
			}
		}
	}

	else if (this->director.firstName == obj.director.firstName)
	{
		if (this->director.lastName > obj.director.lastName)
		{
			return true;
		}
	}

	else if (this->director.firstName > obj.director.firstName)
	{
		return true;
	}

	return false;
}

bool Drama::operator==(const Drama & obj) const
{
	if (this->director.firstName == obj.director.firstName
		&& this->director.lastName == obj.director.lastName
		&& this->title == obj.title)
	{
		return true;
	}

	return false;
}
