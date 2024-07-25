#pragma once

#include "MacroAndDefintions.h"
// #include "Doctor.h"  // Include the Doctor class definition
#include "Patient.h" // Include the Patient class definition
class doctor;        // Forward declaration of the Doctor class
class Slot
{
private:
    static int id;
    Doctor *doctorPtr;
    Patient *patientPtr;
    bool available;
    timeSlot slot_time;

public:
    Slot(Doctor *doctor, timeSlot slot);
    Slot();
    Doctor *getDoctorPtr();
    Patient *getPatientPtr();
    timeSlot *gettimeSlot();
    bool isAvailable();

    void assignPatient(Patient *patient);
    void removePatient();
};