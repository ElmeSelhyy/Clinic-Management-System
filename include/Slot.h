#pragma once

#include "timeSlot.h"
#include "Doctor.h"  // Include the Doctor class definition
#include "Patient.h" // Include the Patient class definition

class Slot
{
private:
    static int id;
    Doctor *doctorPtr;
    Patient *patientPtr;
    bool available;
    timeSlot slot_time;

public:
    Doctor *getDoctorPtr();
    Patient *getPatientPtr();
    timeSlot *gettimeSlot();
    bool isAvailable();
    Slot(Doctor *doctor, timeSlot slot);
    void assignPatient(Patient *patient);
    void removePatient();
};