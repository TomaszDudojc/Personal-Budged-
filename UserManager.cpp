#include "UserManager.h"

void UserManager::registerUser()
{
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Account has been successfully created" << endl << endl;
    system("pause");
}

User UserManager::getNewUserData()
{
    User user;

    user.setupUserId(getNewUserId());

    string name;
    cout << "Enter name: ";
    cin >> name;
    name = AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(name);
    user.setupName(name);

    string surname;
    cout << "Enter surname: ";
    cin >> surname;
    surname = AuxiliaryMethods::changeFirstLetterForUpperCaseAndOthersForLowerCase(surname);
    user.setupSurname(surname);

    string login;
    do
    {
        cout <<"Enter login: ";
        cin>>login;
        user.setupLogin(login);
    }
    while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Enter password: ";
    cin>>password;
    user.setupPassword(password);

    return user;
}

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

void UserManager::displayAllUsers()
{
    for (int i=0; i<users.size(); i++)
    {
        cout<<"User ID: "<<users[i].getUserId();
        cout<<"|Name: "<<users[i].getName();
        cout<<"|Surname: "<<users[i].getSurname();
        cout<<"|Login: "<<users[i].getLogin();
        cout<<"|Password: "<<users[i].getPassword()<<endl;
        system("pause");
    }
}
bool UserManager::loginExists(string login)
{
    for (int i=0; i<users.size(); i++)
    {
        if (users[i].getLogin()==login)
        {
            cout << endl << "There is a user with this login." << endl;

            return true;
        }
    }
    return false;
}

int UserManager::loginUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter the password. Attempts left: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You logged in." << endl << endl;
                    system("pause");
                    loggedInUserId = itr -> getUserId();
                    return loggedInUserId;
                }
            }
            cout << "Wrong password entered 3 times." << endl;
            system("pause");

            return 0;
        }
        itr++;
    }
    cout << "There is no user with this login." << endl << endl;
    system("pause");

    return 0;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void UserManager::logoutUser()
{
    loggedInUserId=0;
}

char UserManager::selectOptionFromUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance for current month" << endl;
    cout << "4. Display balance for previous month" << endl;
    cout << "5. Display balance for selected period" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadCharacter();
    cout<<endl;

    return choice;
}

void UserManager::changePassword()
{
    string newPassword = "";
    cout << "Enter new password: ";
    newPassword = AuxiliaryMethods::loadLine();

    addNewPasswordToFile(newPassword);

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getUserId() == loggedInUserId)
        {
            itr -> setupPassword(newPassword);
            cout << "Password has been changed." << endl << endl;
            system("pause");
        }
    }
}

void UserManager::addNewPasswordToFile(string newPassword)
{
    fileWithUsers.addNewPasswordToFile(newPassword, loggedInUserId);
}

int UserManager::getLoggedInUserId()
{
    return loggedInUserId;
}

