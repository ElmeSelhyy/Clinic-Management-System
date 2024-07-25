#pragma once
#include "User.h"
#include "Schedule.h"
#include "Slot.h"
#include <string>


class Doctor : public User
{
private:
    Schedule doctorschedule;
    std::string departmentname;
    std::string status;

public:
    void SetSchedule(timeSlot &slot);
    bool RemoveSchedule(Slot &slot);
    std::string getDepartmentName();
    std::string getDoctorName();
};
