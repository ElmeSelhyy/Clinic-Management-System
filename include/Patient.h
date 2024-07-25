#pragma once

#include "User.h"
#include "Schedule.h"
#include "MedicalRecord.h"
#include "Slot.h"
#include <string>
#include <vector>

class Patient : public User
{
private:
    int weight;
    std::string bloodGroup;
    std::vector<MedicalRecord> medicalRecords;
    Schedule mySchedule;

public:
    Patient(const std::string &username, const std::string &password, const std::string &name, const int &age, const int &weight, const std::string &bloodGroup);

    void ViewDoctorList(const std::string &departmentName);
    Schedule ViewMySchedule();
    void ViewMedicalRecords();
    bool BookAppointment(Slot &slot);

    ~Patient();
};
