#include "User.h"

void User::setupUserId(int newUserId)
{
    if (newUserId>=0)
        userId=newUserId;
}

void User::setupName(string newName)
{
    name=newName;
}

void User::setupSurname(string newSurname)
{
    surname=newSurname;
}

void User::setupLogin(string newLogin)
{
    login=newLogin;
}

void User::setupPassword(string newPassword)
{
    password=newPassword;
}

int User::getUserId()
{
    return userId;
}

string User :: getName()
{
    return name;
}

string User :: getSurname()
{
    return surname;
}

string User :: getLogin()
{
    return login;
}

string User::getPassword()
{
    return password;
}


