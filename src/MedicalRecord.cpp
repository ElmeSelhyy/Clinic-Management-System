#include "../include/MedicalRecord.h"
#include "../include/FileHandler.h"
#include "../include/MacroAndDefintions.h"

MedicalRecord::MedicalRecord(int patientId, int doctorId)
{
    this->patientId = patientId;
    this->doctorId = doctorId;
    this->recordId = nextID++;

}
MedicalRecord::MedicalRecord(int patientId, int doctorId, std::string diagnosisResult, std::string medicalNeeded)
{
    this->patientId = patientId;
    this->doctorId = doctorId;
    this->recordId = nextID++;
    this->diagnosisResult = diagnosisResult;
    this->medicalNeeded = medicalNeeded;
}

void MedicalRecord::setDiagnosisResult(std::string diagnosisResult)
{
    this->diagnosisResult = diagnosisResult;
}

void MedicalRecord::setMedicalNeeded(std::string medicalNeeded)
{
    this->medicalNeeded = medicalNeeded;
}

std::string MedicalRecord::viewDiagnosis()
{
    return diagnosisResult;
}

std::string MedicalRecord::viewMedicalNeeded()
{
    return medicalNeeded;
}

std::string MedicalRecord::getMedicalRecord()
{
    return "Record ID: " + std::to_string(recordId) + "\nPatient ID: " + std::to_string(patientId) + "\nDoctor ID: " + std::to_string(doctorId) + "\nDiagnosis: " + diagnosisResult + "\nMedical Needed: " + medicalNeeded;
}
void MedicalRecord::addRecord()
{
    std::string report = std::to_string(recordId) + " @" + std::to_string(patientId) + " #" + std::to_string(doctorId) + " '" + diagnosisResult + "' '" + medicalNeeded+"' ";

    FileHandler fileHandler = FileHandler(RECORD_FILE);
    fileHandler.writeFile(report);
}


int  MedicalRecord::nextID=0;