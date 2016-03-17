#include "Store.h"
#include "HashTable.h"
#include <sstream>
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
    string typeOfTransaction;

    while (infile >> typeOfTransaction)
    {
        if (infile.eof())
            break;
        if (typeOfTransaction == "I")
            displayInventory();
        else if (typeOfTransaction == "B")
        {
            readBorrow(infile);
        }
        else if (typeOfTransaction == "R")
        {
            readReturn(infile);
        }
        else if (typeOfTransaction == "H")
        {
            int id;
            infile >> id;

            displayHistory(id);
        }
        else
        {
            getline(infile, typeOfTransaction); //reads in and dismisses the corresponding line.
        }
    }
}

void Store::retrieveClassic(ifstream & infile, Classics & classic, string &data)
{
    Person director;    //stores director, and major actor
    int intData;        //stores month, year, and stock
    string title;

    infile >> intData; //grab stock
    classic.setStock(intData);
    infile >> data;             //grabs and dismisses the remaining comma

    infile >> director.firstName >> director.middleName;

    if(director.middleName[director.middleName.size() - 1] == ',')
    {
        director.lastName = director.middleName;
        director.middleName = "";
        director.lastName.pop_back();
    }
    else
    {
        infile >> director.lastName;
        director.lastName.pop_back(); //removes trailing comma
    }
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

    infile >> director.firstName >> director.lastName;      //reuse director for majoractor

    classic.setMajorActor(director);

    infile >> intData;
    classic.setMonth(intData);
    infile >> intData;
    classic.setReleaseYear(intData);
    storeInventory.addClassic(classic);
}

void Store::retrieveComedy(ifstream & infile, Comedy & comedy, string & data)
{
    Person director;    //stores director
    int intData;        //stores year and stock
    string title = "";

    infile >> intData >> data;
    comedy.setStock(intData);

    infile >> director.firstName >> director.middleName;
    if (director.middleName[director.middleName.size() - 1] == ',')
    {
        director.lastName = director.middleName;
        director.middleName = "";
        director.lastName.pop_back();
    }
    else
    {
        infile >> director.lastName;
        director.lastName.pop_back(); //removes trailing comma
    }
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
    storeInventory.addComedy(comedy);
}

void Store::retrieveDrama(ifstream & infile, Drama & drama, string & data)
{
    Person director;    //stores director
    int intData;        //stores year and stock
    string title = "";

    infile >> intData >> data;
    drama.setStock(intData);

    infile >> director.firstName >> director.middleName;
    if (director.middleName[director.middleName.size() - 1] == ',')
    {
        director.lastName = director.middleName;
        director.middleName = "";
        director.lastName.pop_back();
    }
    else
    {
        infile >> director.lastName;
        director.lastName.pop_back(); //removes trailing comma
    }
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
    storeInventory.addDrama(drama);
}

void Store::readReturn(ifstream & infile)
{
    int id;
    string mediaType, movieType;

    infile >> id >> mediaType >> movieType;

    if (movieType == "C")
    {
        //5000 D C 3 1971 Ruth Gordon
        int month, year;
        Person majorActor;

        infile >> month >> year >> majorActor.firstName >> majorActor.lastName;
        bool test = executeClassicReturn(id, month, year, majorActor);
        Customers *customer;
        bool found = customers.retrieve(id, customer);

        if (found == false)
            return;
        if (test == false)
        {
            string transaction = "Invalid Borrow transaction";
            customer->addTransaction(transaction);
        }

        string transaction = "R " + static_cast<ostringstream*>(&(ostringstream() << id))->str();
        transaction += " " + mediaType + " " + movieType + " " + static_cast<ostringstream*>(&(ostringstream() << month))->str();
        transaction += " " + static_cast<ostringstream*>(&(ostringstream() << year))->str()
            + " " + majorActor.firstName + " " + majorActor.lastName;

        customer->addTransaction(transaction);
        customer = NULL;
    }
    else if (movieType == "F")
    {
        //Sleepless in Seattle, 1993
        string data, title = "";
        int year;


        int count = 0;
        while (infile >> data)
        {
            if (count != 0)
                title.append(" ");
            title.append(data);
            count += 1;
            if (title[title.size() - 1] == ',')
                break;
        }
        title.pop_back();

        infile >> year;
        bool test = executeComedyReturn(id, title, year);
        Customers *customer;
        bool found = customers.retrieve(id, customer);

        if (found == false)
            return;
        if (test == false)
        {
            string transaction = "Invalid Borrow transaction";
            customer->addTransaction(transaction);
        }

        string transaction = "R " + static_cast<ostringstream*>(&(ostringstream() << id))->str();
        transaction += " " + mediaType + " " + movieType + " " + title + ", "
            + static_cast<ostringstream*>(&(ostringstream() << year))->str();
        customer->addTransaction(transaction);
        customer = NULL;
    }
    else if (movieType == "D")
    {
        //Barry Levinson, Good Morning Vietnam,
        Person director;
        string data, title;

        infile >> director.firstName >> director.middleName;
        if (director.middleName[director.middleName.size() - 1] == ',')
        {
            director.lastName = director.middleName;
            director.middleName = "";
            director.lastName.pop_back();
        }
        else
        {
            infile >> director.lastName;
            director.lastName.pop_back(); //removes trailing comma
        }

        int count = 0;
        while (infile >> data)
        {
            if (count != 0)
                title.append(" ");
            title.append(data);
            count += 1;

            if (title[title.size() - 1] == ',')
                break;
        }
        title.pop_back();

        bool test = executeDramaReturn(id, director, title);
        Customers *customer;
        bool found = customers.retrieve(id, customer);

        if (found == false)
            return;
        if (test == false)
        {
            string transaction = "Invalid Borrow transaction";
            customer->addTransaction(transaction);
        }

        string transaction = "B " + static_cast<ostringstream*>(&(ostringstream() << id))->str();
        transaction += " " + transaction + " " + mediaType + " "
            + movieType + " " + director.firstName + " ";
        if (director.middleName != "")
            transaction += director.middleName + " ";
        transaction += director.lastName + ", " + title + ",";
        customer->addTransaction(transaction);
        customer = NULL;
    }
    else
    {
        getline(infile, mediaType);
    }
}

void Store::readBorrow(ifstream & infile)
{
    int id;
    string mediaType, movieType;

    infile >> id >> mediaType >> movieType;

    if (movieType == "C")
    {
        //5000 D C 3 1971 Ruth Gordon
        int month, year;
        Person majorActor;

        infile >> month >> year >> majorActor.firstName >> majorActor.lastName;
        bool test = executeClassicBorrow(id, month, year, majorActor);

        Customers *customer;
        bool found = customers.retrieve(id, customer);

        if (found == false)
            return;
        if (test == false)
        {
            string transaction = "Invalid Borrow transaction";
            customer->addTransaction(transaction);
        }

        string transaction = "B " + static_cast<ostringstream*>(&(ostringstream() << id))->str();
        transaction += " " + mediaType + " " + movieType + " " + static_cast<ostringstream*>(&(ostringstream() << month))->str();
        transaction += " " + static_cast<ostringstream*>(&(ostringstream() << year))->str()
            + " " + majorActor.firstName + " " + majorActor.lastName;

        customer->addTransaction(transaction);
        customer = NULL;
    }
    else if (movieType == "F")
    {
        //Sleepless in Seattle, 1993
        string data, title = "";
        int year;

        int count = 0;

        while (infile >> data)
        {
            if (count != 0)
                title.append(" ");
            title.append(data);
            count += 1;

            if (title[title.size() - 1] == ',')
                break;
        }
        title.pop_back();

        infile >> year;
        bool test = executeComedyBorrow(id, title, year);
        Customers *customer;
        bool found = customers.retrieve(id, customer);

        if (found == false)
            return;
        if (test == false)
        {
            string transaction = "Invalid Borrow transaction";
            customer->addTransaction(transaction);
        }

        string transaction = "B " + static_cast<ostringstream*>(&(ostringstream() << id))->str();
        transaction += " " + mediaType + " " + movieType + " " + title + ", "
            + static_cast<ostringstream*>(&(ostringstream() << year))->str();
        customer->addTransaction(transaction);
        customer = NULL;
    }
    else if (movieType == "D")
    {
        //Barry Levinson, Good Morning Vietnam,
        Person director;
        string data, title;

        infile >> director.firstName >> director.middleName;
        if (director.middleName[director.middleName.size() - 1] == ',')
        {
            director.lastName = director.middleName;
            director.middleName = "";
            director.lastName.pop_back();
        }
        else
        {
            infile >> director.lastName;
            director.lastName.pop_back(); //removes trailing comma
        }

        int count = 0;
        while (infile >> data)
        {
            if (count != 0)
                title.append(" ");
            title.append(data);
            count += 1;

            if (title[title.size() - 1] == ',')
                break;
        }
        title.pop_back();

        bool test = executeDramaBorrow(id, director, title);
        Customers *customer;
        bool found = customers.retrieve(id, customer);

        if (found == false)
            return;
        if (test == false)
        {
            string transaction = "Invalid Borrow transaction";
            customer->addTransaction(transaction);
        }

        //constructs the transaction from the scattered pieces.
        string transaction = "B " + static_cast<ostringstream*>(&(ostringstream() << id))->str();
        transaction += " " + mediaType + " " + movieType + " " + director.firstName
            + " ";
        if (director.middleName != "")
            transaction += director.middleName + " ";
        transaction += director.lastName + ", " + title + ",";

        customer->addTransaction(transaction);
        customer = NULL;
    }
    else
    {
        getline(infile, mediaType);
    }
}

bool Store::executeDramaBorrow(const int id, const Person & director, const string & title)
{
    Customers *customer;
    bool exists = customers.retrieve(id, customer);

    if (exists = true)
    {
                Drama *drama;
                exists = storeInventory.retrieveDrama(director, title, drama);

        if (exists == true)
        {
            if (drama->getCurrentStock() <= 0)
                return false;
            Drama newDrama(*drama);
            newDrama.removeInitialStock(drama->getInitialStock());
            newDrama.removeStock(drama->getCurrentStock());
            newDrama.addInitialStock(1), newDrama.addStock(1);
            customer->borrowed.addDrama(newDrama);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Store::executeComedyBorrow(const int & id, const string & title, const int year)
{
    Customers *customer;
    bool exists = customers.retrieve(id, customer);

    if (exists = true)
    {
        Comedy *comedy;
        exists = storeInventory.retrieveComedy(title, year, comedy);

        if (exists == true)
        {
            if (comedy->getCurrentStock() <= 0)
                return false;
            Comedy newComedy(*comedy);
            newComedy.removeInitialStock(comedy->getInitialStock());
            newComedy.removeStock(comedy->getCurrentStock());
            newComedy.addInitialStock(1), newComedy.addStock(1);
            customer->borrowed.addComedy(newComedy);
            comedy->removeStock(1);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Store::executeClassicBorrow(const int & id, const int month, const int year, Person majorActor)
{
    Customers *customer;
    bool exists = customers.retrieve(id, customer);

    if (exists == true)
    {
        Classics *classic;
        exists = storeInventory.retrieveClassic(month, year, majorActor, classic);

        if (exists == true)
        {
            if (classic->getCurrentStock() <= 0)
                return false;
            Classics newClassic(*classic);
            newClassic.removeInitialStock(classic->getInitialStock());
            newClassic.removeStock(classic->getCurrentStock());
            newClassic.addInitialStock(1), newClassic.addStock(1);
            customer->borrowed.addClassic(newClassic);
            return true;
        }
        else
        {
            return false;
        }
    }

}

bool Store::executeDramaReturn(const int & id, const Person & director, const string & title)
{
    Customers *customer;
    bool exists = customers.retrieve(id, customer);

    if (exists == true)
    {
        Drama *drama;
        exists = customer->borrowed.retrieveDrama(director, title, drama);

        if (exists == true)
        {
            if (drama->getCurrentStock() <= 0)
                return false;
            drama->removeStock(1);
            storeInventory.retrieveDrama(director, title, drama);
            drama->addStock(1);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Store::executeComedyReturn(const int & id, const string & title, const int year)
{
    Customers *customer;
    bool exists = customers.retrieve(id, customer);

    if (exists == true)
    {
        Comedy *comedy;
        exists = customer->borrowed.retrieveComedy(title, year, comedy);

        if (exists == true)
        {
            if (comedy->getCurrentStock() <= 0)
                return false;
            comedy->removeStock(1);
            storeInventory.retrieveComedy(title, year, comedy);
            comedy->addStock(1);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Store::executeClassicReturn(const int & id, const int month, const int year, Person majorActor)
{
    Customers *customer;
    bool exists = customers.retrieve(id, customer);

    if (exists == true)
    {
        Classics *classic;
        exists = customer->borrowed.retrieveClassic(month, year, majorActor, classic);

        if (exists == true)
        {
            if (classic->getCurrentStock() <= 0)
                return false;
            classic->removeStock(1);
            storeInventory.retrieveClassic(month, year, majorActor, classic);
            classic->addStock(1);
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    return false;
}

bool Store::displayHistory(const int id)
{
    Customers *customer;
    bool exists = customers.retrieve(id, customer);

    if (exists = true)
    {
        customer->displayHistory();
    }
    else
    {
        //customer not found.
    }
    return false;
}

void Store::displayInventory()
{
    cout << storeInventory;
    //cout >> storeInventory;
}
