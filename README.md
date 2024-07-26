## README for Hospital Management System

### Project Overview

This Hospital Management System helps manage hospital operations like scheduling appointments, viewing medical records, and managing user accounts. The system is designed for patients, doctors, and administrators to efficiently interact with hospital services.

### Features

- **Patients** can view doctors, schedule appointments, and manage their medical records.
- **Doctors** can manage their schedules, view patient records, and handle appointments.
- **Admins** can manage users, validate doctors, and oversee the system operations.

### Class Diagram Overview

#### Key Classes and Their Responsibilities

- **User**
  - Base class for all users (patients and admins)
  - Methods: Login, Signup, ChangePassword

- **Patient** (inherits from User)
  - Attributes: Weight, BloodType, MedicalRecord
  - Methods: ViewDoctors, ViewSchedule, BookSlot, ManageMyAccount

- **Doctor**
  - Attributes: Schedule, Department, Status
  - Methods: ManageSchedule, WriteMedicalRecord, ViewPatientDetails

- **Admin** (inherits from User)
  - Methods: RemoveUser, ValidateDoctor

- **Department**
  - Methods: GetDoctorList, AddRemoveDoctor

- **Schedule**
  - Attributes: List of Slots
  - Methods: GetAvailableSlots, GetSlotByDoctor, GetSlotByPatient

- **Slot**
  - Attributes: SlotID, DoctorID, PatientID, TimeSlot, RoomNumber, Availability
  - Methods: GetTimeSlot, GetPatient, GetDoctor

- **MedicalRecords**
  - Attributes: PatientID, DoctorID, RecordID, RecordDate, Diagnosis, Medications
  - Methods: GetDiagnosis, SetDiagnosis, SetMedications

- **Logger**
  - Methods: Log

### How to Build and Run the Project

#### Build

To compile the project, use the following command:

```sh
g++ FileHandler.cpp Slot.cpp Department.cpp Schedule.cpp User.cpp Doctor.cpp MedicalRecord.cpp Patient.cpp ScreenOne.cpp DoctorScreen.cpp PatientScreen.cpp main.cpp -o main
```

#### Run

To execute the compiled program, use:

```sh
./main
```

### Dependencies

- C++ compiler (e.g., g++)
- Standard C++ libraries

### Usage

1. **Login** or **Signup** as a new user.
2. **Patients** can:
   - View doctors and their schedules.
   - Book appointments.
   - View and manage their medical records.
3. **Doctors** can:
   - Manage their schedules.
   - View patient details and medical histories.
   - Update patient medical records.
4. **Admins** can:
   - Manage user accounts.
   - Validate and manage doctors.

This system simplifies hospital operations and enhances the efficiency of hospital management.
