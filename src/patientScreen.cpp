#include "../include/Patient.h"
#include "../include/screens.h"
#include "../include/FileHandler.h"
#include <iostream>
#include <string>
#include <sstream>
void patientScreen(std::string patientId)
{
    FileHandler fileHandler = FileHandler(PATIENT_FILE);

    std::string patientData = fileHandler.getFirstDataWithID(patientId);
    std::istringstream iss(patientData);
    std::string userid, userName, password, name, age, userId,weight,bloodGroup ;
    iss >> userid >> userName >> password >> name >> age >> userId >> weight >> bloodGroup ;
    std::cout << "Welcome Patient " << name << std::endl;
  
    int option;
    std::cout << "Choose an option: \n1. View Schedule\n2. Book appointment\n3. View Medical Records\n";
    std::cin >> option;

    while (option != 1 && option != 2 && option != 3)
    {
        std::cout << "Invalid option. Please choose again.\n";
        std::cin >> option;
    }

    switch (option)
    {
    case 1:
    {
        // view Schedule
        // Patient patient = Patient(patientId,userName,password,name,stoi(age),weight,bloodGroup,userId);
        
        // Slot slot = patient.ViewMySchedule();
            
         break;
    }
    case 2:
    {
        /// Book appointment
         Patient patient = Patient(patientId,userName,password,name,stoi(age),stoi(weight),bloodGroup,userId);
         std::string time_Slot;
         std::string doctorId;
         std::cout << "Enter the time slot to book.\n";
         std::cin  >> time_Slot;
         std::cout<<"Enter the Doctor Id.\n";
         std::cin  >> doctorId;

         if(patient.BookAppointment(time_Slot,doctorId)){
             std::cout << "Booked successfully.\n";
         }else{
             std::cout << "Doctor is busy.\n";
         }
         break;
    }
    case 3:
    {
        //  Patient patient = Patient(patientId,userName,password,name,stoi(age),weight,bloodGroup,userId);
        //  patient.ViewMedicalRecords();
        break;
    }
    }
}