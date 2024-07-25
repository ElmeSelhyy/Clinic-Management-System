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
    Doctor(const std::string &DoctorID, const std::string &username, const std::string &password, const std::string &name, const int &age, std::string usedID, std::string departmentname);
    std::vector<std::string> getScheduler();

    void SetSchedule(std::string &timeslot);
    bool RemoveSchedule(Slot &slot);
    std::string getDepartmentName();
};
