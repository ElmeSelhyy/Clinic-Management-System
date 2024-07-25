#include "../include/Department.h"

Department::Department(std::string departmentname) : departmentname(departmentname)
{
}

void Department::addDoctor(Doctor &doctor)
{
    departmentmap[doctor.getDepartmentName()].push_back(doctor);
}

void Department::removeDoctor(Doctor &doctor)
{
    auto &doctors = departmentmap[doctor.getDepartmentName()];
    auto it = std::remove(doctors.begin(), doctors.end(), doctor);
    doctors.erase(it, doctors.end());
}

void Department::getDoctorList()
{
    for (auto &doctor : departmentmap[departmentname])
    {
        cout << doctor.getDoctorName() << endl;
    }
}
