#include "PersonalBudget.h"

char PersonalBudget::selectOptionFromMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. End " << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods :: loadCharacter();

    return choice;
}

void PersonalBudget::registerUser()
{
    userManager.registerUser();
}

void PersonalBudget::displayAllUsers()
{
    userManager.displayAllUsers();
}

int PersonalBudget::loginUser()
{
    userManager.loginUser();
    if (userManager.isUserLoggedIn())
    {
        transactionManager = new TransactionManager (FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES, userManager.getLoggedInUserId());
    }
}

bool PersonalBudget::isUserLoggedIn()
{
    userManager.isUserLoggedIn();
}

void PersonalBudget::logoutUser()
{
    userManager.logoutUser();
    delete transactionManager;
    transactionManager = NULL;
}

char PersonalBudget::selectOptionFromUserMenu()
{
    userManager.selectOptionFromUserMenu();
}

void PersonalBudget::changePassword()
{
    userManager.changePassword();
}

void PersonalBudget::addIncome()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager->addIncome();
    }
    else
    {
        cout << "You need to login " << endl;
        system ("pause");
    }
}

void PersonalBudget::addExpense()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager->addExpense();
    }
    else
    {
        cout << "You need to login " << endl;
        system ("pause");
    }
}

void PersonalBudget::displayBalanceForSelectedPeriod()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager->displayBalanceForSelectedPeriod();
    }
    else
    {
        cout << "You need to login " << endl;
        system ("pause");
    }
}

void PersonalBudget::displayBalanceForCurrentMonth()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager->displayBalanceForCurrentMonth();
    }
    else
    {
        cout << "You need to login " << endl;
        system ("pause");
    }
}

void PersonalBudget::displayBalanceForPreviousMonth()
{
    if (userManager.isUserLoggedIn())
    {
        transactionManager->displayBalanceForPreviousMonth();
    }
    else
    {
        cout << "You need to login " << endl;
        system ("pause");
    }
}
