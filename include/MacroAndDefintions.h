#pragma once

#define USER_FILE "users.txt"
#define DOCTOR_FILE "doctors.txt"
#define PATIENT_FILE "patient.txt"
#define DEPARTMENTS_FILE "departments.txt"
#define DOCTOR_REQUEST_FILE "doctorRequest.txt"
#define MEDICAL_RECORD_FILE "medicalRecord.txt"
#define SLOT_FILE "slots.txt"
#define TEMP_FILE "temp.txt"
#define RECORD_FILE "record.txt"

enum UserType
{
    ADMIN,
    DOCTOR,
    PATIENT
};

enum LoginSignUp
{
    LOGIN = 1,
    SIGNUP
};

enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

struct timeSlot
{
    int starthour;
    int endhour;
    int date;
};
