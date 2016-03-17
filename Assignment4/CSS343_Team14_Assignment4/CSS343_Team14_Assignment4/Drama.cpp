#include "Drama.h"


Drama::Drama()
{
    type = 'D';
}

Drama::~Drama()
{
}

ostream& operator <<(ostream& outStream, const Drama &obj)
{
	outStream << "D, " << obj.currentStock << ", " << obj.director.firstName << " "
		<< obj.director.lastName << ", " << obj.title << ", " << obj.yearReleased;
	return outStream;

}

bool Drama::operator<(const Drama & obj)
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

bool Drama::operator>(const Drama & obj)
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

bool Drama::operator==(const Drama & obj)
{
	if (this->director.firstName == obj.director.firstName
		&& this->director.lastName == obj.director.lastName
		&& this->title == obj.title)
	{
		return true;
	}

	return false;
}
