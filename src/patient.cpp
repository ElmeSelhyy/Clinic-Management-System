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

bool Patient::BookAppointment(Slot &slot)
{
    if (slot.isAvailable())
    {
        slot.assignPatient(this);
        mySchedule.addSlot(slot);
        slot.isAvailable() = false;
        return true;
    }
    return false;
}
