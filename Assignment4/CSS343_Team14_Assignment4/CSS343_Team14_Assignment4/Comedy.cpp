#include "Comedy.h"

ostream& operator <<(ostream& outStream, const Comedy &obj)
{
	outStream << "F, " << obj.currentStock << ", " << obj.director.firstName << " "
		<< obj.director.lastName << ", " << obj.title << ", " << obj.yearReleased;
	return outStream;

}
Comedy::Comedy()
{
}


Comedy::~Comedy()
{
}
