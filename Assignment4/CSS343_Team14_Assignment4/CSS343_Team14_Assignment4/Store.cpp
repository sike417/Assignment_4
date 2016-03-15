#include "Store.h"



Store::Store()
{
}

//assumes that the user only inputs the file name not the extentsion
Store::Store(string movieListFileName)
{
    ifstream infile(movieListFileName + ".txt");

    if (!infile)
    {
        cout << movieListFileName << endl;
    }

    string data;

    while (infile >> data)
    {
        data.pop_back(); //removes the trailing comma

        if (data == "C")
        {
            Classics classic;
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

Store::Store(ifstream & movieList)
{
}


Store::~Store()
{
}
