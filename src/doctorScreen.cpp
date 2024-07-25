

#include "../include/Doctor.h"
#include "../include/screens.h"
#include "../include/FileHandler.h"
#include <iostream>
#include <string>
#include <sstream>
void doctorScreen(std::string doctorID)
{
    FileHandler fileHandler = FileHandler(DOCTOR_FILE);

    std::string doctorData = fileHandler.getFirstDataWithID(doctorID);
    std::istringstream iss(doctorData);
    std::string userid, userName, password, name, age, userId, departmentName;
    iss >> userid >> userName >> password >> name >> age >> userId >> departmentName;
    std::cout << "Welcome Doctor " << name << "\nDepartment " << departmentName << std::endl;

    int option;
    std::cout << "Choose an option: \n1. View Appointments\n2. Set Schedule\n3. Remove Schedule\n 4.logout\n";
    std::cin >> option;

    while (option != 1 && option != 2 && option != 3 && option != 4)
    {
        std::cout << "Invalid option. Please choose again.\n";
        std::cin >> option;
    }

    switch (option)
    {
    case 1:
    {
        Doctor doctor = Doctor(doctorID, userName, password, name, stoi(age), userId, departmentName);
        std::vector<std::string> appointments = doctor.getScheduler();
        for (int i = 0; i < appointments.size(); i++)
        {
            std::cout << appointments[i] << std::endl;
        }
        break;
    }
    }
}