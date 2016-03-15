#pragma once
#include <string>
using namespace std;
struct Director
{
    string firstName;
    string lastName;

};

class People
{
    friend class Commands;
public:
    People();
    ~People();
};

