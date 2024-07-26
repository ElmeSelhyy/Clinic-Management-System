#pragma once

#include <string>

class MedicalRecord
{
private:
    static int nextID;
    int recordId;
    int patientId;
    int doctorId;
    std::string recordDate;
    std::string diagnosisResult;
    std::string medicalNeeded;

public:
    MedicalRecord(int patientId, int doctorId);
    MedicalRecord(int patientId, int doctorId, std::string diagnosisResult, std::string medicalNeeded);
    void setDiagnosisResult(std::string diagnosisResult);
    void setMedicalNeeded(std::string medicalNeeded);
    std::string viewDiagnosis();
    std::string viewMedicalNeeded();
    std::string getMedicalRecord();
    void addRecord();
};
