// ----------------------------------------------------History.h-------------------------------------------------------
// Jayse Farrell, Eduardo Sainos CSS343 Section Number
// Created:	March 8, 2016
// Date of Last Modification:	March 16, 2016
// --------------------------------------------------------------------------------------------------------------------
// Purpose: This class will be used to represent the transaction history. It contains a
// linked list that will be used to store strings that contain the specific commands 
// called. This class also has an overloaded output operator which will be able to 
// display the whole history in the correct format. 
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// This class assumes that all of the information read from file is correct and valid.
// --------------------------------------------------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H

#pragma once
#include <vector>
#include <string>
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
    vector<string> history;
};

#endif

