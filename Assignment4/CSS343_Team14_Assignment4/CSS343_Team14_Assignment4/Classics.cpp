
#include "Classics.h"

ostream& operator <<(ostream& outStream, const Classics &obj)
{
	outStream << "C, " << obj.currentStock << ", " << obj.director.firstName << " "
		<< obj.director.lastName << ", " << obj.title << ", " << obj.majorActor.firstName
		<< " " << obj.majorActor.lastName << " " << obj.month << " " << obj.yearReleased;
	return outStream;
}

Classics::Classics()
{
}


Classics::~Classics()
{
}
