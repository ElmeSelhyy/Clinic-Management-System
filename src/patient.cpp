#include "../include/Patient.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include "../include/FileHandler.h"
#include "../include/MacroAndDefintions.h"
#include <fstream>
#include <string>
#include <vector>

Patient::Patient(const std::string &patientId, const std::string &username, const std::string &password, const std::string &name, const int &age, const int &weight, const std::string &bloodGroup, std::string &usedID) : User(username, password, name, age, PATIENT, usedID)
{
    this->weight = weight;
    this->bloodGroup = bloodGroup;
    this->medicalRecords.clear();
    this->mySchedule = Schedule(patientId, PATIENT);
}

void Patient::ViewMySchedule()
{
    FileHandler Filehandler = FileHandler(SLOT_FILE);
    std::vector<std::string> slots = Filehandler.getAllDataWithID("@" + this->getMyId());

    for (auto it : slots)
    {
        std::cout << it << std::endl;
    }
}

void Patient::ViewMedicalRecords()
{
    FileHandler fileHandler = FileHandler(RECORD_FILE);
    std::vector<std::string> medicalRecords = fileHandler.getAllDataWithID("@"+this->getMyId());
    for (auto it : medicalRecords)
    {
        std::cout << it << std::endl;
    }
    
}

bool Patient::BookAppointment(std::string slot, std::string doctorId)
{
    Schedule doctorSchedule = Schedule(doctorId, DOCTOR);
    std::vector<std::string> availableSlots = doctorSchedule.getSlots();

    for (std::string &availableSlot : availableSlots)
    {
        std::istringstream iss(availableSlot);
        std::string segment;
        std::vector<std::string> tokens;

        while (std::getline(iss, segment, ' '))
        {
            tokens.push_back(segment);
        }

        if (tokens.size() > 3 && tokens[3] == slot)
        {

            doctorSchedule.removeSlot(availableSlot);
            std::string TimeSlot;
            std::string timeslot_date = tokens[2];
            std::string timeslot_end_hour = tokens[4];

            TimeSlot = "#" + doctorId + " @" + this->getMyId() + " " + getName() + " " + timeslot_date + " " + slot + " " + timeslot_end_hour + "\n";
            doctorSchedule.addSlot(TimeSlot);
            return true;
        }
    }
    return false;
}
