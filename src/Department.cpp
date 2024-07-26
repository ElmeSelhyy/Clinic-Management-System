#include "../include/Department.h"
#include "../include/FileHandler.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iostream>
Department::Department()
{
    FileHandler filehandler = FileHandler(DEPARTMENTS_FILE);
    std::vector<std::string> departments = filehandler.getAllData();
    for (auto &department : departments)
    {
        std::istringstream iss(department);
        std::string departmentName, doctorName, DoctorID;
        iss >> departmentName;
        departmentList.insert(departmentName);
        while (iss >> DoctorID >> doctorName)
        {
            this->departments[departmentName].push_back(doctorName + " id: " + DoctorID);
        }
    }
}

void Department::addDoctor(Doctor &doctor)
{
    this->departments[doctor.getDepartmentName()].push_back(doctor.getDoctorName() + " id: " + doctor.getMyId());
}

void Department::removeDoctor(Doctor &doctor)
{
    auto &doctors = departments[doctor.getDepartmentName()];
    auto it = std::remove(doctors.begin(), doctors.end(), doctor);
    doctors.erase(it, doctors.end());
}

void Department::getDoctorList(std::string departmentname)
{
    for (auto &doctor : departments[departmentname])
    {
        std::cout << doctor.getDoctorName() << std::endl;
    }
}

void Department::getDepartmentList()
{
    for (auto &department : departmentList)
    {
        std::cout << department << std::endl;
    }
}
