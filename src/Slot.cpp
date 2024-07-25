#include "../include/Slot.h"

Slot::Slot(Doctor *doctor, timeSlot slot)
{
    this->id = id++;
    doctorPtr = doctor;
    this->slot = slot;
}
{
    this->id = id++;
    doctorPtr = doctor;
}
{
}
Doctor *Slot::getDoctorPtr()
{
    return doctorPtr;
}

Patient *Slot::getPatientPtr()
{
    return patientPtr;
}

timeSlot Slot::gettimeSlot()
{
    return slot_time;
}
bool Slot::isAvailable();
{
    return available;
}
void Slot::assignPatient(Patient *patient)
{
    patientPtr = patient;
    available = false;
}
void Slot::removePatient()
{
    patientPtr = nullptr;
    available = true;
}
