#include "Comedy.h"
#include <sstream>

Comedy::Comedy()
{
    type = 'F';
}


Comedy::~Comedy()
{
}

ostream& operator <<(ostream& outStream, const Comedy &obj)
{
	outStream << string("F, ") << static_cast<ostringstream*>(&(ostringstream() << obj.currentStock))->str() << string(", ") << obj.director.firstName << string(" ")
		<< obj.director.lastName << string(", ") << obj.title << string(", ") << static_cast<ostringstream*>(&(ostringstream() << obj.yearReleased))->str();
	return outStream;

}

bool Comedy::operator<(const Comedy & obj) const
{
	if (this->title == obj.title)
	{
		if (this->yearReleased < obj.yearReleased)
		{
			return true;
		}
	}

	else if (this->title < obj.title)
	{
		return true;
	}

	return false;
}

bool Comedy::operator>(const Comedy & obj) const
{
	if (this->title == obj.title)
	{
		if (this->yearReleased > obj.yearReleased)
		{
			return true;
		}
	}

	else if (this->title > obj.title)
	{
		return true;
	}

	return false;
}

bool Comedy::operator==(const Comedy & obj) const
{
	if (this->title == obj.title && this->yearReleased == obj.yearReleased)
	{
		return true;
	}

	return false;
}

