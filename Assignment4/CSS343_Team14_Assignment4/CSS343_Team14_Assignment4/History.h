#ifndef HISTORY_H
#define HISTORY_H

#pragma once
#include <list>
#include <iostream>
using namespace std;
class History
{
public:
    History();
    ~History();
    
    void addTransaction(string transaction);
    friend ostream& operator<<(ostream& output, const History &obj);

private:
    list<string> history;
};

#endif

