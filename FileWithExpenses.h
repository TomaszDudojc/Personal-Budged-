#ifndef FILEWITHIEXPENSES_H
#define FILEWITHIEXPENSES_H

#include <iostream>
#include <vector>

#include "DateManager.h"
#include "XmlFile.h"
#include "Transaction.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile
{
    DateManager dateManager;
    string fileNameWithExpenses;
    int lastExpenseId;
    int loggedInUserId;
    vector <Transaction> expenses;

public:
    FileWithExpenses(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses)
    {
        loggedInUserId = 0;
        lastExpenseId = 0;
    };

    void addExpenseToFile(Transaction expense);
    vector <Transaction> loadExpensesOfLoggedInUserFromFile(int loggedInUserId);
    int getLastExpenseIdFromFile();
};

#endif
