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

