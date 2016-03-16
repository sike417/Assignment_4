#include "Store.h"
#include <cstdlib>


Store::Store()
{
}

//assumes that the user only inputs the file name not the extentsion
Store::Store(string movieListFileName)
{
    ifstream infile(movieListFileName + ".txt");
    LoadMovieFromFile(infile);
}

Store::Store(ifstream & movieList)
{
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
            classic.setType(data[0]);

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
