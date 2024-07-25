#include "admin.h"
#include "FileHandler.h"
#include <string>

bool Admin::removeUser(User &user)
{
    FileHandler &UserFile = FileHandler(USER_FILE);
    FileHandler &file = FileHandler(USER_FILE);
    return UserFile.RemoveCredentials(user.getMyId());
}

void Admin::addDoctor(Doctor &doctor)
{
    FileHandler &file = FileHandler::getInstance("users.txt");
    std::record = doctor.getMyId() + " " + doctor.getUsername() + " " + doctor.getPassword() + " " + doctor.getName() + " " + doctor.getAge() + " " + doctor.getDepartmentName();
    file.writeFile();
}