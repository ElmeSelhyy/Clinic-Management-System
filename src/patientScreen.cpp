#include "../include/Patient.h"
#include "../include/screens.h"
#include "../include/FileHandler.h"
#include "../include/Department.h"
#include <iostream>
#include <string>
#include <sstream>
void patientScreen(std::string patientId)
{
    FileHandler fileHandler = FileHandler(PATIENT_FILE);

    std::string patientData = fileHandler.getFirstDataWithID(patientId);
    std::istringstream iss(patientData);
    std::string userid, userName, password, name, age, userId, weight, bloodGroup;
    iss >> userid >> userName >> password >> name >> age >> userId >> weight >> bloodGroup;
    std::cout << "Welcome Patient " << name << std::endl;

    int option;
    
    while (1)
    {
        std::cout << "Choose an option: \n1. search for appointment \n2. View Schedule\n3. Book appointment\n4. View Medical Records \n5. Log out\n";
        std::cin >> option;
        while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5)
        {
            std::cout << "Invalid option. Please choose again.\n";
            std::cin >> option;
        }
        Patient patient = Patient(patientId, userName, password, name, stoi(age), stoi(weight), bloodGroup, userId);
        switch (option)
        {
        case 1:
        {
            Department department = Department();
            department.getDepartmentList();
            std::string departmentName;
            std::cout << "Enter the department name.\n";
            std::cin >> departmentName;
            department.getDoctorList(departmentName);
            std::string doc_id;
            std::cout << "Please choose doctor id.\n";
            std::cin >> doc_id;
            department.viewDoctorSlots(doc_id);
        
            // patient.ViewDoctorList(departmentName);
            break;
        }
        case 2:
        {

            patient.ViewMySchedule();

            break;
        }
        case 3:
        {

            std::string time_Slot;
            std::string doctorId;

            std::cout << "Enter the time slot to book.\n";
            std::cin >> time_Slot;
            std::cout << "Enter the Doctor Id.\n";
            std::cin >> doctorId;

            if (patient.BookAppointment(time_Slot, doctorId))
            {
                std::cout << "Booked successfully.\n";
            }
            else
            {
                std::cout << "Doctor is busy.\n";
            }
            break;
        }
        case 4:
        {
            patient.ViewMedicalRecords();
            break;
        }
        case 5:
        {
            std::cout << "Logged out successfully\n";
            return;
        }
        }
    }
}