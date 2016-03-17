#include "Customers.h"


Customers::Customers()
{
}

Customers::Customers(int id)
{
    this->id = id;
}


Customers::~Customers()
{
}

bool Customers::operator==(const Customers & obj)
{
	if (this->name.firstName == obj.name.firstName && 
		this->name.lastName == obj.name.lastName && this->id == obj.id)
	{
		return true;
	}

	return false;
}

bool Customers::operator!=(const Customers & obj)
{
	if (this->name.firstName != obj.name.firstName ||
		this->name.lastName != obj.name.lastName || this->id != obj.id)
	{
		return true;
	}

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

void Customers::addTransaction(string transaction)
{
    history.addTransaction(transaction);
}

void Customers::displayHistory()
{
    cout << history;
}
