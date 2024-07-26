#include "../include/Doctor.h"
#include "../include/Slot.h"
#include "../include/Department.h"
#include "../include/Schedule.h"
#include "../include/MacroAndDefintions.h"
Doctor::Doctor(const std::string &DoctorID, const std::string &username, const std::string &password, const std::string &name, const int &age, std::string usedID, std::string departmentname) : User(username, password, name, age, DOCTOR, usedID)
{
    this->doctorschedule = Schedule(DoctorID, DOCTOR);
    this->departmentname = departmentname;
}

// Set the schedule for the doctor
void Doctor::SetSchedule(std::string &timeslot)
{
    std::string slot = "\n#"+ this->getMyId() +" NULL " + timeslot;
    doctorschedule.addSlot(slot);
}

bool Doctor::RemoveSchedule(Slot &slot)
{
    // for (auto it = doctorschedule.getSlots().begin(); it != doctorschedule.getSlots().end(); it++)
    // {
    //     if (it->gettimeSlot() == slot.gettimeSlot())
    //     {
    //         doctorschedule.removeSlot(*it);
    //         return true;
    //     }
    // }
    return false;
}

std::string Doctor::getDepartmentName()
{
    return departmentname;
}

std::vector<std::string> Doctor::getScheduler()
{
    return doctorschedule.getSlots();
}