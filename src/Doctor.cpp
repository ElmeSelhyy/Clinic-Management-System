#include "Doctor.h"
#include "Slot.h"
#include "Department.h"
#include "SCHEDULE.h"
#include <Logger.h>

// Set the schedule for the doctor
void Doctor::SetSchedule(timeSlot timeslot)
{
    Slot slot = Slot(this, timeslot);
    doctorschedule.addSlot(slot);
}

bool Doctor::RemoveSchedule(Slot slot)
{
    if (doctorschedule.removeSlot(slot))
    {
        return true;
    }
    return false;
}

// Get the department name
Department Doctor::getDepartmentName()
{
    return departmentname;
}

// Get the doctor's name
std::string Doctor::getDoctorName()
{
    return name;
}
