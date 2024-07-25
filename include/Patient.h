#pragma once

#include "User.h"
#include "Schedule.h"
#include "MedicalRecord.h"
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
    bool BookAppointment(const std::string &doctorName, const std::string &departmentName, const std::string &slot);
    bool UpdateMyAccount(const int &option, const std::string &newData);

    ~Patient();
};
