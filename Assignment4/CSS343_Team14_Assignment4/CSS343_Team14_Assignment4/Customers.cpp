#include "Customers.h"


Customers::Customers()
{
}

Customers::Customers(int id)
{
}


Customers::~Customers()
{
}

bool Customers::operator==(const Customers & obj)
{
    return false;
}

bool Customers::operator!=(const Customers & obj)
{
    return false;
}

void Customers::setName(const string & first, const string & last)
{
	name.firstName = first;
	name.lastName = last;
}

int Customers::getID()
{
	return this->id;
}

Person Customers::getName()
{
	return this->name;
}
