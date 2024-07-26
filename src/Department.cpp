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
    this->departments[doctor.getDepartmentName()].push_back(doctor.getName() + " id: " + doctor.getMyId());
}

void Department::removeDoctor(Doctor &doctor)
{
    auto &doctors = departments[doctor.getDepartmentName()];
    std::string doctorStr = doctor.getName() + " id: " + doctor.getMyId();
    // auto it = std::remove(doctors.begin(), doctors.end(), doctorStr);
    for(auto it = doctors.begin(); it != doctors.end(); it++)
    {
        if(*it == doctorStr)
        {
            doctors.erase(it);
            break;
        }
    }
    
}

void Department::getDoctorList(std::string departmentname)
{
    for (auto &doctor : departments[departmentname])
    {
        std::cout << doctor << std::endl;
    }
}
void Department::viewDoctorSlots(std:: string doctorId){
    
    FileHandler fileHandler = FileHandler(SLOT_FILE);
   

    std::vector<std::string> slots=fileHandler.getAllDataWithID("#"+doctorId);

    for (int i = 0; i < slots.size(); i++)
    {
        std::istringstream iss(slots[i]);
        std::string patientName;
        iss >> patientName >> patientName;
        if (patientName == "NULL")
        {
            std::cout << "*"+slots[i].substr(7) << std::endl;
        }
    }

}

void Department::getDepartmentList()
{
    std::cout << "Departments: " << std::endl;
    for (auto &department : departmentList)
    {
        std::cout << department << std::endl;
    }
}
