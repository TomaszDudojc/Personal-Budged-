#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include <iostream>
#include <vector>
#include <iomanip>

#include "DateManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

using namespace std;

class TransactionManager
{
    const int LOGGED_IN_USER_ID;
    vector <Transaction> incomes;
    vector <Transaction> expenses;

    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Transaction getNewIncomeData();
    Transaction getNewExpenseData();
    string getTransactionDate();
    string loadDate();
    void sortIncomesByDate();
    void sortExpensesByDate();
    float correctAmountFormat(string amount);
    void displayBalanceFromDateToDate(string firstDate, string lastDate);
    float getIncomesFromDateToDate(string firstDate, string lastDate);
    float getExpensesFromDateToDate(string firstDate, string lastDate);
    void displayIncome(int i);
    void displayExpense(int i);
    void displayAllIncomesSortedByDate();
    void displayAllExpensesSortedByDate();

public:
    TransactionManager (string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId) : fileWithIncomes (fileNameWithIncomes), fileWithExpenses (fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesOfLoggedInUserFromFile(LOGGED_IN_USER_ID);
    };

    void addIncome();
    void addExpense();

    void displayBalanceForSelectedPeriod();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
};

#endif
