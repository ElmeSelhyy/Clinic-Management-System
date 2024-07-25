#include "../include/MedicalRecord.h"


MedicalRecord::MedicalRecord(int patientId,int doctorId)
{
   this->patientId = patientId;
   this->doctorId  = doctorId;
   this->recordId  = nextID++;
}

void MedicalRecord::setDiagnosisResult(std::string diagnosisResult){
    this->diagnosisResult = diagnosisResult;
}

void MedicalRecord::setMedicalNeeded( std::string medicalNeeded){
    this->medicalNeeded = medicalNeeded;
}

std::string MedicalRecord::viewDiagnosis(){
    return diagnosisResult;
}

std::string MedicalRecord::viewMedicalNeeded(){
    return medicalNeeded;
}