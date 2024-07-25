#include <iostream>
#include "../include/User.h"


int main(){
    User *user;
    std::string userName="weloo";
    std::string password="weloo1";
    std::string name="ahmed";
    int age=1;
    int userType =1;

    bool IsSigned = user->SignUp(userName,password,name,age,userType);


    std::cout<<" IsSigned: "<<"\n";
    return 0;
}