#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include "Doctor.h"

class Department
{
    static std::unordered_set<std::string> departmentList;
    std::unordered_map<std::string, std::vector<Doctor>> departments;
    std::string departmentName;

public:
    Department(std::string departmentname);
    void addDoctor(Doctor &doctor);
    void removeDoctor(Doctor &doctor);
    void getDoctorList();

};