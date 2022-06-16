#include "Transaction.h"

void Transaction::setupUserId(int newUserId)
{
    if(newUserId>=0)
    {
        userId=newUserId;
    }
}

void Transaction::setupId(int newId)
{
    if(newId>=0)
    {
        id=newId;
    }
}

void Transaction::setupDate (string newDate)
{
    date=newDate;
}

void Transaction::setupIntDate(int newIntDate)
{
    intDate=newIntDate;
}

void Transaction::setupName(string newName)
{
    name=newName;
}

void Transaction::setupAmount(float newAmount)
{
    amount=newAmount;
}

int Transaction::getUserId()
{
    return userId;
}

int Transaction::getId()
{
    return id;
}

string Transaction::getDate()
{
    return date;
}

int Transaction::getIntDate()
{
    return intDate;
}

string Transaction::getName()
{
    return name;
}

float Transaction::getAmount()
{
    return amount;
}
