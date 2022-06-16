#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "DateManager.h"
#include "XmlFile.h"
#include "Transaction.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithIncomes : public XmlFile
{
    DateManager dateManager;
    string fileNameWithIncomes;
    int lastIncomeId;
    int loggedInUserId;
    vector <Transaction> incomes;

public:
    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes)
    {
        loggedInUserId = 0;
        lastIncomeId = 0;
    };

    void addIncomeToFile(Transaction income);
    vector <Transaction> loadIncomesOfLoggedInUserFromFile(int loggedInUserId);
    int getLastIncomeIdFromFile();
};

#endif
