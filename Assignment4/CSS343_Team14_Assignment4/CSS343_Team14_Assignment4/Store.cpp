#include "Store.h"



Store::Store()
{
}

Store::Store(string movieListFileName)
{
	char movieType;
	ifstream infile1(movieListFileName);
	if (!infile1) 
	{
		cout << "File could not be opened." << endl;
		return;
	}
	while (!infile1.eof())
	{
		infile1 >> movieType;
		switch (movieType)
		{
		case 'F':
			break;

		case 'D':
			break;

		case 'C':
			break;
		}
	}


}

Store::Store(ifstream & movieList)
{
	char movieType;
	if (!movieList)
	{
		cout << "File could not be opened." << endl;
		return;
	}
	while (!movieList.eof())
	{
		movieList >> movieType;
		switch (movieType)
		{
		case 'F':
			break;

		case 'D':
			break;

		case 'C':
			break;
		}
	}
}


Store::~Store()
{
}
