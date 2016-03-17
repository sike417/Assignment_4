#include "Comedy.h"


Comedy::Comedy()
{
    type = 'F';
}


Comedy::~Comedy()
{
}

ostream& operator <<(ostream& outStream, const Comedy &obj)
{
	outStream << "F, " << obj.currentStock << ", " << obj.director.firstName << " "
		<< obj.director.lastName << ", " << obj.title << ", " << obj.yearReleased;
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

