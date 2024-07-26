#pragma once
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include "Doctor.h"

class Department
{
    std::unordered_set<std::string> departmentList;
    std::unordered_map<std::string, std::vector<std::string>> departments;

public:
    Department();
    void addDoctor(Doctor &doctor);
    void removeDoctor(Doctor &doctor);
    void getDoctorList(std::string departmentname);
    void getDepartmentList();
};