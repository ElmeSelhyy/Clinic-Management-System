#include <unordered_map>
#include <vector>
#include <string>
#include "Doctor.h"
class Department
{
    std::unordered_map<std::string, std::vector<Doctor>> departments;
    std::string departmentName;

public:
    void addDoctor(Doctor doctor);
    void removeDoctor(Doctor doctor);
    void getDoctorList();
};