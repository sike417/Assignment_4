#include "Store.h"
#include "HashTable.h"
#include <cstdlib>


Store::Store()
{
}

//assumes that the user only inputs the file name not the extentsion
Store::Store(const string &movieListFileName)
{
    ifstream infile(movieListFileName + ".txt");
    LoadMovieFromFile(infile);
    infile.close();
}

Store::Store(ifstream & movieList)
{
	LoadMovieFromFile(movieList);
}

Store::Store(ifstream & movieList, ifstream & customerList)
{
    LoadMovieFromFile(movieList);
    LoadCustomersFromFile(movieList);
}

Store::Store(const string & movieListFileName, const string & customerListFileName)
{
    ifstream infile(movieListFileName + ".txt");
    LoadMovieFromFile(infile);
    infile.close();

    infile.open(customerListFileName + ".txt");
    LoadCustomersFromFile(infile);
    infile.close();
}

Store::Store(ifstream & movieList, ifstream & customerList, ifstream & transactionList)
{
    LoadMovieFromFile(movieList);
    LoadCustomersFromFile(customerList);
    LoadTransactionsFromFile(customerList);
}

Store::Store(const string & movieListFileName, const string & customerListFileName, const string & transactionListFileName)
{
    ifstream infile(movieListFileName + ".txt");
    LoadMovieFromFile(infile);
    infile.close();

    infile.open(customerListFileName + ".txt");
    LoadCustomersFromFile(infile);
    infile.close();

    infile.open(transactionListFileName + ".txt");
    LoadTransactionsFromFile(infile);
    infile.close();
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
            retrieveClassic(infile, classic, data);
        }
        else if (data == "F")
        {
            Comedy comedy;
            retrieveComedy(infile, comedy, data);
        }
        else if (data == "D")
        {
            Drama drama;
            retrieveDrama(infile, drama, data);
        }
        else
        {
            
            //invalid data
        }
    }
}

void Store::LoadCustomersFromFile(ifstream & infile)
{
	string idstr, fName, lName;
	while (infile >> idstr >> lName >> fName)
	{
		int id = stoi(idstr);
		if(customers.contains(id) == false)
		{
			Customers cust(id);
			cust.setName(fName, lName);
			customers.insert(id, cust);
		}
	}
}

void Store::LoadTransactionsFromFile(ifstream & infile)
{
}

void Store::retrieveClassic(ifstream & infile, Classics & classic, string &data)
{
    Person director;    //stores director, and major actor
    int intData;        //stores month, year, and stock
    string title;

    infile >> intData; //grab stock
    classic.setStock(intData);
    infile >> data;             //grabs and dismisses the remaining comma

    infile >> director.firstName >> director.lastName;
    director.lastName.pop_back(); //removes trailing comma
    classic.setDirector(director);

    intData = 0;
    while (infile >> data)
    {
        if (intData != 0)
        {
            title.push_back(' '), title.append(data);
        }
        else
            title.append(data);

        if (title[title.size() - 1] == ',')
        {
            title.pop_back();       //removes trailing comma
            break;
        }
        intData += 1;
    }
    classic.setTitle(title);

    infile >> director.firstName >> director.lastName;  //reuse director for major actor.
    classic.setMajorActor(director);

    infile >> intData;
    classic.setMonth(intData);
    infile >> intData;
    classic.setReleaseYear(intData);
}

void Store::retrieveComedy(ifstream & infile, Comedy & comedy, string & data)
{
    Person director;    //stores director
    int intData;        //stores year and stock
    string title = "";

    infile >> intData >> data;
    comedy.setStock(intData);

    infile >> director.firstName >> director.lastName;
    director.lastName.pop_back();
    comedy.setDirector(director);

    intData = 0;
    while (infile >> data)
    {
        if (intData != 0)
        {
            title.push_back(' '), title.append(data);
        }
        else
            title.append(data);

        if (title[title.size() - 1] == ',')
        {
            title.pop_back();       //removes trailing comma
            break;
        }
        intData += 1;
    }
    comedy.setTitle(title);

    infile >> intData;
    comedy.setReleaseYear(intData);
}

void Store::retrieveDrama(ifstream & infile, Drama & drama, string & data)
{
    Person director;    //stores director
    int intData;        //stores year and stock
    string title = "";

    infile >> intData >> data;
    drama.setStock(intData);

    infile >> director.firstName >> director.lastName;
    director.lastName.pop_back();
    drama.setDirector(director);

    intData = 0;
    while (infile >> data)
    {
        if (intData != 0)
        {
            title.push_back(' '), title.append(data);
        }
        else
            title.append(data);

        if (title[title.size() - 1] == ',')
        {
            title.pop_back();       //removes trailing comma
            break;
        }
        intData += 1;
    }
    drama.setTitle(title);

    infile >> intData;
    drama.setReleaseYear(intData);
}
