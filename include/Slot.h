#pragma once

#include "MacroAndDefintions.h"
#include <string>

class Slot
{
private:
    static int idNext;
    int id;
    std::string doctorId;
    std::string patientId;
    bool available;
    timeSlot slot;

public:
    Slot(std::string doctorId, timeSlot slot);
    Slot();
    std::string getDoctorId();
    std::string getPatientId();
    timeSlot gettimeSlot();
    bool isAvailable();

    void assignPatient(std::string patient);
    void removePatient();
};