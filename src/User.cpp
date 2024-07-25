#include "../include/User.h"
#include <iostream>


User::User(std::string userName, std::string password, std::string name, int age, int userType,std::string usedId)
{
    this->usedId =usedId;
    this->userName = userName;
    this->password = password;
    this->name = name;
    this->age = age;
    this->userType = userType;
}

int User::Login(std::string userName, std::string password)
{
    FileHandler fileHandler = FileHandler(USER_FILE);
    return fileHandler.searchCredentials(userName, password);
}

// TODO
// CHECK USERNAME IS USED 
bool User::SignUp(std::string userName, std::string password, std::string name, int age, int userType)
{   
    UserCounter++;
    FileHandler fileHandler = FileHandler(USER_FILE);
    std::string userReferenceId= (userType == DOCTOR) ? ("#" + std::to_string(UserCounter)) : ("@" + std::to_string(UserCounter));
    return fileHandler.writeFile(userReferenceId + " " + userName + " " + password + " " + name + " " + std::to_string(age) + " " +std::to_string(userType));
}

std::string User::getMyId()
{
    return usedId;
}

int User:: UserCounter=0;