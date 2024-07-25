#include <string>
class Slot;
class Department;
class SCHEDULE;

class Doctor : private User
{
private:
    SCHEDULE doctorschedule;
    Department departmentname;
    std::string status;

public:
    void SetSchedule(timeSlot slot);
    bool RemoveSchedule(Slot slot);
    Department getDepartmentName();
    std::string getDoctorName();
};
