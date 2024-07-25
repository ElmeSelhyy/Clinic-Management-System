#pragma once
#include <string>

class User
{
private:
    static int UserCounter;
    int usedId;
    std::string userName;
    std::string password;
    std::string name;
    int age;
    int userType;

    User(std::string userName, std::string password, std::string name, int age, int userType);

public:
    bool Login(std::string userName, std::string password);
    bool SignUp(std::string userName, std::string password, std::string name, int age, int userType);
    bool ChangePassword(std::string newPassword);
    int getMyId();
    ~User();
};
