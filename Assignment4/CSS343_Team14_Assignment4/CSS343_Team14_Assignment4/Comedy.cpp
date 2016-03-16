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

