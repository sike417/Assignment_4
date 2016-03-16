#include "Store.h"
#include <cstdlib>


Store::Store()
{
}

<<<<<<< HEAD
//assumes that the user only inputs the file name not the extentsion
Store::Store(string movieListFileName)
{
    ifstream infile(movieListFileName + ".txt");
    LoadMovieFromFile(infile);
=======
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


>>>>>>> sainos-master
}

Store::Store(ifstream & movieList)
{
<<<<<<< HEAD
=======
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
>>>>>>> sainos-master
}


Store::~Store()
{
}

void Store::LoadMovieFromFile(ifstream & infile)
{

    string data;

    while (infile >> data)
    {
        data.pop_back(); //removes the trailing comma

        if (data == "C")
        {
            Classics classic;

            infile >> data; //grab next section.

            data.pop_back();//removes trailing comma.

            classic.setStock(atoi(data.c_str()));

            Person director;

            infile >> director.firstName;
            infile >> director.lastName;
            director.lastName.pop_back(); //removes trailing comma

            classic.setDirector(director);

            infile >> data;
            data.pop_back(); //removes trailing whitespace.
            classic.setTitle(data);

            cout << endl;
        }
        else if (data == "F")
        {
            Comedy comedy;
            
        }
        else if (data == "D")
        {
            Drama drama;
        }
        else
        {
            //invalid data
        }
    }
}

void Store::LoadCustomersFromFile(ifstream & infile)
{
}
