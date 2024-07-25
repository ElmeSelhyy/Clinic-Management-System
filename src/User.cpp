#include "include/User.h"

User::User(std::string userName, std::string password, std::string name, int age)
{
    UserCounter++;
    this->usedId = UserCounter;
    this->userName = userName;
    this->password = password;
    this->name = name;
    this->age = age;
}

int User::Login(std::string userName, std::string password)
{
    FileHandler &fileHandler = FileHandler::getInstance("users.txt");
    return fileHandler.searchCredentials(userName, password);
}

bool User::SignUp(std::string userName, std::string password, std::string name, int age)
{
    FileHandler &fileHandler = FileHandler::getInstance("users.txt");
    return fileHandler.writeFile(std::to_string(usedId) + " " + userName + " " + password + " " + name + " " + std::to_string(age));
}

int User::getMyId()
{
    return usedId;
}