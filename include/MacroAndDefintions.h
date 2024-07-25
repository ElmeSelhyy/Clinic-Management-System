#pragma once

#define USER_FILE "users.txt"
#define DOCTOR_FILE "doctors.txt"
#define PATIENT_FILE "patient.txt"
#define DOCTOR_REQUEST_FILE "doctorRequest.txt"
#define MEDICAL_RECORD_FILE "medicalRecord.txt"
#define SLOT_FILE "slots.txt"

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
    Day day;
    int date;
};
