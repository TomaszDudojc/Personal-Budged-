#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

class Transaction
{
    int userId;
    int id;
    string name;
    string date;
    int intDate;
    float amount;

public:
    Transaction(int userId = 0, int id = 0, string date = "", int intDate = 0, string name = "", float amount = 0.0)
    {
        this->userId = userId;
        this->id = id;
        this->date = date;
        this->intDate = intDate;
        this->name = name;
        this->amount = amount;
    }

    void setupUserId (int newUserId);
    void setupId (int newId);
    void setupDate (string newDate);
    void setupIntDate (int newIntDate);
    void setupName(string newName);
    void setupAmount(float newAmount);

    int getUserId();
    int getId();
    string getDate();
    int getIntDate();
    string getName();
    float getAmount();
};

#endif
