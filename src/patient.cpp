#include "include/Patient.h"
#include <algorithm>
#include <isotream>

Patient::Patient(const int &userID, const std::string &username, const std::string &password, const std::string &name, const int &age, const int &weight, const std::string &bloodGroup) : User(username, password, name, age)
{
    this->weight = weight;
    this->bloodGroup = bloodGroup;
    this->medicalRecords.clear();
}

Schedule Patient::ViewMySchedule()
{
    return mySchedule;
}

void Patient::ViewMedicalRecords()
{
    for (auto record : medicalRecords)
    {
        std::cout << record.getMedicalRecord() << std::endl;
    }
}

bool Patient::BookAppointment(const std::string &doctorName, const std::string &departmentName, const std::string &slot)
{
    if (mySchedule.BookSlot(slot))
    {
        return true;
    }
    return false;
}