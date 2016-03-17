#include "History.h"

ostream& operator<<(ostream& output, const History &obj)
{
	output << "----------------------------Customer History--------------------------- " << endl;
	for (int i = 0; i < obj.history.size(); i++)
	{
		output << obj.history[i] << endl;
	}

	return output;
}

History::History()
{
}


History::~History()
{
}

void History::addTransaction(string transaction)
{
	history.push_back(transaction);
}
