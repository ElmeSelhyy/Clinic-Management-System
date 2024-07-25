#include <iostream>
#include "../include/User.h"


int main(){
    std::string userName="weloo22";
    std::string password="weloo1";
    std::string name="ahmed";
    int age=1;
    int userType =1;
    User *user;
    

    // bool IsSigned = user->SignUp(userName,password,name,age,userType);
    bool isLogged = user->Login(userName,password);

    std::cout<<" IsSigned: "<<isLogged<<"\n";
    return 0;
}
