

#include "../include/Doctor.h"
#include "../include/screens.h"
#include "../include/FileHandler.h"
#include "../include/MedicalRecord.h"
#include <iostream>
#include <string>
#include <sstream>
#include <limits> 

std::string createRemovalTimeSlot(){
    std::string timeslot_date;
    std::string timeslot_start_hour;
    std::string TimeSlot;

    std::cout << "Please enter the Date.\n";
    std::cin >> timeslot_date;
    std::cout << "Please enter the Start Hour.\n";
    std::cin >> timeslot_start_hour;
    TimeSlot = timeslot_date + " " + timeslot_start_hour;
    return TimeSlot;
}

std::string createTimeSlot(){
    std::string timeslot_date;
    std::string timeslot_start_hour;
    std::string timeslot_end_hour;
    std::string TimeSlot;

    std::cout << "Please enter the Date.\n";
    std::cin >> timeslot_date;
    std::cout << "Please enter the Start Hour.\n";
    std::cin >> timeslot_start_hour;
    std::cout << "Please enter the End Hour.\n";
    std::cin >> timeslot_end_hour;
    TimeSlot = timeslot_date + " " + timeslot_start_hour + " " + timeslot_end_hour;
    return TimeSlot;
}

MedicalRecord createReport(Doctor doctor){
    std::string patientId;
    std::string diagnosis_result;
    std::string medicine_needed;
    std::cout << "Enter the patient ID.\n";
    std::cin >> patientId;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << "Enter the Diagnosis Result:\n";
    std::getline(std::cin,diagnosis_result);
    std::cout << "Enter the Medicine Needed.\n";
    std::getline(std::cin,medicine_needed);
    return MedicalRecord(stoi(patientId), stoi(doctor.getMyId()),diagnosis_result, medicine_needed);
}



void doctorScreen(std::string doctorID)
{
    FileHandler fileHandler = FileHandler(DOCTOR_FILE);

    std::string doctorData = fileHandler.getFirstDataWithID(doctorID);
    std::istringstream iss(doctorData);
    std::string userid, userName, password, name, age, userId, departmentName;
    iss >> userid >> userName >> password >> name >> age >> userId >> departmentName;
    std::cout << "Welcome Doctor " << name << "\nDepartment " << departmentName << std::endl;

    int option;
    while(1)
        {
        std::cout << "Choose an option: \n1. View Appointments\n2. Set Schedule\n3. Remove Schedule\n4.Submit Report\n5.logout\n";
        std::cin >> option;

        while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
        {
            std::cout << "Invalid option. Please choose again.\n";
            std::cin >> option;
        }

        switch (option)
        {
        case 1:
        {
            Doctor doctor = Doctor(doctorID, userName, password, name, stoi(age), userId, departmentName);
            std::vector<std::string> appointments = doctor.getScheduler();
            for (int i = 0; i < appointments.size(); i++)
            {
                if(appointments[i].find("NULL") == std::string::npos)
                    std::cout << appointments[i] << std::endl;
            }
            break;
        }
        case 2: // Set Schedule
        {
            std::string TimeSlot;
            Doctor doctor = Doctor(doctorID, userName, password, name, stoi(age), userId, departmentName);
            TimeSlot = createRemovalTimeSlot();
            doctor.SetSchedule(TimeSlot);
            std:: cout << "Schedule set successfully\n";
            break;
        }
        case 3: // remove schedule
        {
            Doctor doctor = Doctor(doctorID, userName, password, name, stoi(age), userId, departmentName);
            std::string TimeSlot;
            TimeSlot = createRemovalTimeSlot();
           
            if (doctor.RemoveSchedule(TimeSlot))
            {
                std::cout << "Schedule removed successfully\n";
            }
            else
            {
                std::cout << "Schedule not found! Enter the slot again.\n";
            }
            break;
        }
        case 4:
        {
            Doctor doctor = Doctor(doctorID, userName, password, name, stoi(age), userId, departmentName);
            MedicalRecord medicalRecord = createReport(doctor);
            medicalRecord.addRecord();
            break;
        }
        case 5:
        {
            std::cout << "Logging out\n";
            return;
        }
        }
}
}
