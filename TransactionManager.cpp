#include "TransactionManager.h"

void TransactionManager::addIncome()
{
    Transaction income;

    system("cls");

    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;

    income = getNewIncomeData();
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
    cout << "Income added to the file" << endl;

    displayIncome(incomes.size()-1);//displayAllIncomesSortedByDate();
    system("pause");
}

void TransactionManager::addExpense()
{
    Transaction expense;

    system("cls");

    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;

    expense = getNewExpenseData();
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
    cout << "Expense added to the file" << endl;

    displayExpense(expenses.size()-1);//displayAllExpensesSortedByDate();
    system("pause");
}

Transaction TransactionManager::getNewIncomeData()
{
    DateManager dateManager;
    Transaction transaction;
    string date, name;
    float amount;
    int id, intDate;

    transaction.setupId(fileWithIncomes.getLastIncomeIdFromFile()+1);
    transaction.setupUserId(LOGGED_IN_USER_ID);

    date = getTransactionDate();

    transaction.setupDate(date);
    intDate=dateManager.convertStringDateToIntDate(date);
    transaction.setupIntDate(intDate);

    cout << "Enter income name: ";
    name = AuxiliaryMethods::loadLine();
    transaction.setupName(name);

    cout << "Enter amount: ";
    string stringAmount = AuxiliaryMethods::loadLine();
    amount = correctAmountFormat(stringAmount);
    transaction.setupAmount(amount);

    return transaction;
}

Transaction TransactionManager::getNewExpenseData()
{
    DateManager dateManager;
    Transaction transaction;
    string date, name;
    float amount;
    int id, intDate;

    transaction.setupId(fileWithExpenses.getLastExpenseIdFromFile()+1);
    transaction.setupUserId(LOGGED_IN_USER_ID);

    date = getTransactionDate();

    transaction.setupDate(date);
    intDate=dateManager.convertStringDateToIntDate(date);
    transaction.setupIntDate(intDate);

    cout << "Enter expense name: ";
    name = AuxiliaryMethods::loadLine();
    transaction.setupName(name);

    cout << "Enter amount: ";
    string stringAmount = AuxiliaryMethods::loadLine();
    amount = correctAmountFormat(stringAmount);
    transaction.setupAmount(amount);

    return transaction;
}

string TransactionManager::getTransactionDate()
{
    char choice;
    string date;
    DateManager dateManager;

    cout << "Do you want to add transaction with current date?" <<endl;
    cout << "If yes, please type 'y', if you want to chose other date, please type 'n': " << endl;

    choice = AuxiliaryMethods::loadCharacter();

    if (choice == 'y'||choice == 'Y')
    {
        date = dateManager.createCurrentDate();
        cout<<"Current date: "<<date<<endl;
    }
    else if (choice == 'n'||choice == 'N')
    {
        date=loadDate();
    }
    return date;
}

string TransactionManager::loadDate()
{
    DateManager dateManager;
    string date="";
    do
    {
        cout << "Enter date in format YYYY-MM-DD: ";
        date = AuxiliaryMethods::loadLine();
    }
    while (dateManager.isDateCorrect(date) == false);

    return date;
}

void TransactionManager::displayAllIncomesSortedByDate()
{
    sortIncomesByDate();

    float totalIncomesAmount=0.00;

    for (int i = 0; i < incomes.size(); i++)
    {
        displayIncome(i);
        totalIncomesAmount+=incomes[i].getAmount();
    }
    cout<<"Total incomes amouont: "<<totalIncomesAmount<<fixed<<setprecision(2)<<endl<<endl;
}

void TransactionManager::displayAllExpensesSortedByDate()
{
    sortExpensesByDate();

    float totalExpensesAmount=0.00;

    for (int i = 0; i < expenses.size(); i++)
    {
        displayExpense(i);
        totalExpensesAmount+=expenses[i].getAmount();
    }
    cout<<"Total expenses amouont: "<<totalExpensesAmount<<fixed<<setprecision(2)<<endl<<endl;
}

void TransactionManager::displayIncome(int i)
{
    cout<<"date: "<<incomes[i].getDate()<<"| id: "<<incomes[i].getId()<<".| user id: "<<incomes[i].getUserId()<<".| name: "<<incomes[i].getName()<<"| amount: "<<incomes[i].getAmount()<<fixed<<setprecision(2)<<endl;
}

void TransactionManager::displayExpense(int i)
{
    cout<<"date: "<<expenses[i].getDate()<<"| id: "<<expenses[i].getId()<<".| user id: "<<expenses[i].getUserId()<<".| name: "<<expenses[i].getName()<<"| amount: "<<expenses[i].getAmount()<<fixed<<setprecision(2)<<endl;
}

void TransactionManager::sortIncomesByDate()
{
    std::sort(incomes.begin(), incomes.end(), [](auto && l, auto && r)
    {
        return l.getIntDate() < r.getIntDate();
    });
}

void TransactionManager::sortExpensesByDate()
{
    std::sort(expenses.begin(), expenses.end(), [](auto && l, auto && r)
    {
        return l.getIntDate() < r.getIntDate();
    });
}

float TransactionManager::correctAmountFormat(string stringAmount)
{
    stringAmount = AuxiliaryMethods::replaceCommaWithDot(stringAmount);
    float amount=AuxiliaryMethods::convertStringToFloat(stringAmount);

    return amount;
}

void TransactionManager::displayBalanceForSelectedPeriod()
{
    string firstDateOfPeriod="";
    string lastDateOfPeriod="";

    cout<<"Enter first date. ";
    firstDateOfPeriod=loadDate();
    cout<<"Enter last date. ";
    lastDateOfPeriod=loadDate();

    while(firstDateOfPeriod>lastDateOfPeriod)
    {
        cout<<"Uncorrect range of dates!"<<endl;
        cout<<"Enter first date. ";
        firstDateOfPeriod=loadDate();
        cout<<"Enter last date. ";
        lastDateOfPeriod=loadDate();
    }
    displayBalanceFromDateToDate(firstDateOfPeriod, lastDateOfPeriod);
}

void TransactionManager::displayBalanceFromDateToDate(string firstDate, string lastDate)
{
    DateManager dateManager;

  float totalIncomesAmount=getIncomesFromDateToDate(firstDate, lastDate);

    if (totalIncomesAmount==0) cout<<"There are no incomes in selected period."<<endl<<endl;
    else cout<<"Total incomes amouont: "<<totalIncomesAmount<<fixed<<setprecision(2)<<endl<<endl;

    float totalExpensesAmount=getExpensesFromDateToDate(firstDate, lastDate);

    if (totalExpensesAmount==0) cout<<"There are no expenses in selected period."<<endl<<endl;
    else cout<<"Total expenses amouont: "<<totalExpensesAmount<<fixed<<setprecision(2)<<endl<<endl;

    cout<<"Transaction balance of period from "<<firstDate<<" to "<<lastDate<<": "<<totalIncomesAmount-totalExpensesAmount<<fixed<<setprecision(2)<<endl;
    cout<<"---------------------------------------------------------------------"<<endl<<endl;
    system("pause");
}

float TransactionManager::getIncomesFromDateToDate(string firstDate, string lastDate)
{
    DateManager dateManager;
    float totalIncomesAmount=0.00;

    int intFirstDate=dateManager.convertStringDateToIntDate(firstDate);
    int intLastDate=dateManager.convertStringDateToIntDate(lastDate);

          sortIncomesByDate();

        cout<<endl<<"Incomes of period from "<<firstDate<<" to "<<lastDate<<":"<<endl;

        for (int i = 0; i < incomes.size(); i++)
        {
            if (incomes[i].getIntDate()>=intFirstDate && incomes[i].getIntDate()<=intLastDate)
            {
                displayIncome(i);
                totalIncomesAmount+=incomes[i].getAmount();
            }
        }
        return totalIncomesAmount;
}

float TransactionManager::getExpensesFromDateToDate(string firstDate, string lastDate)
{
    DateManager dateManager;
    float totalExpensesAmount=0.00;

    int intFirstDate=dateManager.convertStringDateToIntDate(firstDate);
    int intLastDate=dateManager.convertStringDateToIntDate(lastDate);

        sortExpensesByDate();

        cout<<"Expenses of period from "<<firstDate<<" to "<<lastDate<<":"<<endl;

        for (int i = 0; i < expenses.size(); i++)
        {
            if (expenses[i].getIntDate()>=intFirstDate && expenses[i].getIntDate()<=intLastDate)
            {
                displayExpense(i);
                totalExpensesAmount+=expenses[i].getAmount();
            }
        }
        return totalExpensesAmount;
}

void TransactionManager::displayBalanceForCurrentMonth()
{
    DateManager dateManager;

    int year = dateManager.getCurrentYear();
    int month = dateManager.getCurrentMonth();
    const int firstDayOfMonth=1;
    int lastDayOfMonth = dateManager.checkNumberOfDaysInMonth(year, month);

    string dateOfFirstDayOfMonth = dateManager.convertIntDateToStringDate(year, month, firstDayOfMonth);
    string dateOfLastDayOfMonth = dateManager.convertIntDateToStringDate (year, month, lastDayOfMonth);

    displayBalanceFromDateToDate(dateOfFirstDayOfMonth, dateOfLastDayOfMonth);
}

void TransactionManager::displayBalanceForPreviousMonth()
{
    DateManager dateManager;
    int year = 0;
    int month = 0;

    if (dateManager.getCurrentMonth()==1)
    {
        year = dateManager.getCurrentYear()-1;
        month = 12;
    }
    else
    {
        year = dateManager.getCurrentYear();
        month = dateManager.getCurrentMonth()-1;
    }

    const int firstDayOfMonth = 1;
    int lastDayOfMonth = dateManager.checkNumberOfDaysInMonth(year, month);

    string dateOfFirstDayOfMonth = dateManager.convertIntDateToStringDate(year, month, firstDayOfMonth);
    string dateOfLastDayOfMonth = dateManager.convertIntDateToStringDate (year, month, lastDayOfMonth);

    displayBalanceFromDateToDate(dateOfFirstDayOfMonth, dateOfLastDayOfMonth);
}
