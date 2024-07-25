#include "../include/User.h"
#include "../include/MacroAndDefintions.h"
User::User(std::string userName, std::string password, std::string name, int age, int userType)
{
    UserCounter++;
    this->usedId = UserCounter;
    this->userName = userName;
    this->password = password;
    this->name = name;
    this->age = age;
    this->userType = userType;
}

int User::Login(std::string userName, std::string password)
{
    FileHandler &fileHandler = FileHandler(USER_FILE);
    return fileHandler.searchCredentials(userName, password);
}

bool User::SignUp(std::string userName, std::string password, std::string name, int age, int userType)
{
    FileHandler &fileHandler = FileHandler(USER_FILE);
    return fileHandler.writeFile(std::to_string(usedId) + " " + userName + " " + password + " " + name + " " + std::to_string(age));
}

int User::getMyId()
{
    return usedId;
}