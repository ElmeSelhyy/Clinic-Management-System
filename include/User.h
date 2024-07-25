#pragma once
#include <string>

class User
{
private:
    static int usedId;
    std::string userName;
    std::string password;
    std::string name;
    int age;

    User(std::string userName, std::string password, std::string name, int age);

public:
    bool Login(std::string userName, std::string password);
    bool SignUp(std::string userName, std::string password, std::string name, int age);
    bool ChangePassword(std::string newPassword);
    ~User();
};
