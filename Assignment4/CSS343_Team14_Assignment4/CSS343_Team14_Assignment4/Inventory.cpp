#include "Inventory.h"

ostream& operator <<(ostream& outStream, const Inventory &obj)
{
	outStream << "---------------------------------- Classics ----------------------------------" << endl;
	for (int i = 0; i < obj.classicList.size(); i++)
	{
		outStream << obj.classicList[i] << endl;
	}

	outStream << "----------------------------------- Comedies ----------------------------------" << endl;
	for (int i = 0; i < obj.comedyList.size(); i++)
	{
		outStream << obj.comedyList[i] << endl;
	}

	outStream << "----------------------------------- Dramas ----------------------------------" << endl;
	for (int i = 0; i < obj.dramaList.size(); i++)
	{
		outStream << obj.dramaList[i] << endl;
	}

	return outStream;
}

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
}

bool Inventory::addClassic(const Classics & newClassic)
{
	for (int i = 0; i < classicList.size(); i++)
	{
		if (newClassic == classicList[i])
		{
			return false;
		}
	}

	classicList.push_back(newClassic);
	return true;
}

bool Inventory::addComedy(const Comedy & newComedy)
{
	for (int i = 0; i < comedyList.size(); i++)
	{
		if (newComedy == comedyList[i])
		{
			return false;
		}
	}

	comedyList.push_back(newComedy);
	return true;
}

bool Inventory::addDrama(const Drama & newDrama)
{
	for (int i = 0; i < dramaList.size(); i++)
	{
		if (newDrama == dramaList[i])
		{
			return false;
		}
	}

	dramaList.push_back(newDrama);
	return true;

}

bool Inventory::retrieveClassic(const int & month, const int & year, const Person & majorActor, Classics &classic)
{
	for (int i = 0; i < classicList.size(); i++)
	{
		if (month == classicList[i].getMonth() && year == classicList[i].getYearReleased()
			&& majorActor.firstName == classicList[i].getMajorActor().firstName
			&& majorActor.lastName == classicList[i].getMajorActor().lastName)
		{
        classic = classicList[i];
        return true;
		}
	}

	return false;
}

bool Inventory::retrieveComedy(const string & title, const int & year, Comedy &comedy)
{
	for (int i = 0; i < comedyList.size(); i++)
	{
		if (title == comedyList[i].getTitle() && year == comedyList[i].getYearReleased())
		{
        comedy = comedyList[i];
			return true;
		}
	}

	return false;
}

bool Inventory::retrieveDrama(const Person & director, const string & title, Drama &drama)
{
	for (int i = 0; i < dramaList.size(); i++)
	{
		if (director.firstName == dramaList[i].getDirector().firstName
			&& director.lastName == dramaList[i].getDirector().lastName
			&& title == dramaList[i].getTitle())
		{
        drama = dramaList[i];
			return true;
		}
	}

	return false;
}
