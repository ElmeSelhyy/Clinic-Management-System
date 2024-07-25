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
    Doctor(const std::string &username, const std::string &password, const std::string &name, const int &age,std::string departmentname);
    void SetSchedule(timeSlot &slot);
    bool RemoveSchedule(Slot &slot);
    std::string getDepartmentName();
    std::string getDoctorName();
};
