#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>

#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User>users;
    FileWithUsers fileWithUsers;

    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
    UserManager(string fileNameWithUsers): fileWithUsers(fileNameWithUsers)
    {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile ();
    };

    void registerUser();
    void displayAllUsers();
    int loginUser();
    bool isUserLoggedIn();
    void changePassword();
    void addNewPasswordToFile(string newPassword);
    void addUserToFile();
    void logoutUser();
    char selectOptionFromUserMenu();
    int getLoggedInUserId();
};

#endif
