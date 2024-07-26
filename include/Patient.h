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
    Patient(const std::string &patientId, const std::string &username, const std::string &password, const std::string &name, const int &age, const int &weight, const std::string &bloodGroup, std::string &usedID);

    // void ViewDoctorList(const std::string &departmentName);
    void ViewMySchedule();
    void ViewMedicalRecords();
    bool BookAppointment(std::string slot, std::string doctorId);

    // ~Patient();
};
