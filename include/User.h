#pragma once
#include <string>
#include "../include/MacroAndDefintions.h"
#include "../include/FileHandler.h"

class User
{
private:
    static int UserCounter;
    std::string usedId;
    std::string userName;
    std::string password;
    std::string name;
    int age;
    int userType;

    User(std::string userName, std::string password, std::string name, int age, int userType,std::string usedId);

public:
    int Login(std::string userName, std::string password);
    bool SignUp(std::string userName, std::string password, std::string name, int age, int userType);
    // bool ChangePassword(std::string newPassword);
    std::string getMyId();
    // ~User();
};
