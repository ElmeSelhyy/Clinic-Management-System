#include "../include/Slot.h"

Slot::Slot(std::string doctorId, timeSlot slot)
{
    this->id = idNext++;
    this->doctorId = doctorId;
    this->slot = slot;
}

Slot::Slot()
{
    doctorId = "";
    patientId = "";
}

std::string Slot::getDoctorId()
{
    return doctorId;
}

std::string Slot::getPatientId()
{
    return patientId;
}

timeSlot Slot::gettimeSlot()
{
    return slot;
}
bool Slot::isAvailable()
{
    return available;
}

void Slot::assignPatient(std::string patient)
{
    patientId = patient;
    available = false;
}

void Slot::removePatient()
{
    patientId = "";
    available = true;
}

int Slot:: idNext=0 ;