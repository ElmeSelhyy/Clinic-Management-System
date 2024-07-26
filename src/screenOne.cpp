#include "../include/screens.h"

void ScreenOne()
{
    std::cout << "Choose an option: \n1. Login\n2. SignUp\n";
    int option;
    std::cin >> option;
    while (option != 1 && option != 2)
    {
        std::cout << "Invalid option. Please choose again.\n";

        std::cin >> option;
    }

    std::string userName, password;
    std::cout << "Enter your username: ";
    std::cin >> userName;
    std::cout << std::endl
              << "Enter your password: ";
    std::cin >> password;
    std::cout << std::endl;
    std::string userId;

    switch (option)
    {
    case LOGIN:
    {
        userId = User::Login(userName, password);
        if (userId[0] == '#')
        {
            doctorScreen(userId);
            std::cout << "DOCTOR\n";
        }
        else if (userId[0] == '@')
        {
            patientScreen(userId);
            std::cout << "PATIENT\n";
        }
        break;
    }
    case SIGNUP:
    {
        int age;
        std::string name;
        std::cout << "Enter your name: ";
        std::cin >> name;
        std::cout << std::endl
                  << "Enter your age: ";
        std::cin >> age;
        std::cout << std::endl
                  << "Choose your type: \n1. Doctor\n2. Patient\n";
        std::cin >> userId;
        if (stoi(userId) == DOCTOR)
        {
            if (User::SignUp(userName, password, name, age, DOCTOR))
            {
                std::cout << "Sign up successful\n";
            }
            else
            {
                std::cout << "Sign up failed\n";
                ScreenOne();
            }
        }
        else
        {
            if (User::SignUp(userName, password, name, age, PATIENT))
            {
                std::cout << "Sign up successful\n";
            }
            else
            {
                std::cout << "Sign up failed\n";
                ScreenOne();
            }
        }
        break;
    }
    default:
        std::cout << "Invalid option\n";
    }
}
