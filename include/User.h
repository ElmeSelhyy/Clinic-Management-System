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

public:
    User(std::string userName, std::string password, std::string name, int age, int userType, std::string usedId);
    static std::string Login(std::string userName, std::string password);
    static bool SignUp(std::string userName, std::string password, std::string name, int age, int userType);
    // bool ChangePassword(std::string newPassword);
    std::string getMyId();
    std::string getName();
    // ~User();
};
