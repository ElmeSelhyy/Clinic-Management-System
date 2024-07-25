#include "Doctor.h"
#include "Slot.h"
#include "Department.h"
#include "SCHEDULE.h"
#include <Logger.h>

// Set the schedule for the doctor
void Doctor::SetSchedule(timeSlot &timeslot)
{
    Slot slot = Slot(this, timeslot);
    doctorschedule.addSlot(slot);
}

bool Doctor::RemoveSchedule(Slot &slot)
{
    for (auto it = doctorschedule.slots.begin(); it != doctorschedule.slots.end(); it++)
    {
        if (it->gettimeSlot() == slot.gettimeSlot())
        {
            doctorschedule.removeSlot(*it);
            return true;
        }
    }
    return false;
}


std::string Doctor::getDepartmentName()
{
    return departmentname;
}

// Get the doctor's name
std::string Doctor::getDoctorName()
{
    return name;
}
