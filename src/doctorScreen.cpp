

#include "../include/Doctor.h"
#include "../include/FileHandler.h"
#include <iostream>
#include <string>

void doctorScren(std::string doctorID)
{
    FileHandler fileHandler = FileHandler(DOCTOR_FILE);
    std::string doctorData = fileHandler.searchData(doctorID);
    std::cout << doctorData << std::endl;
}