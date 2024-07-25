#pragma once

#include "User.h"

class Admin : public User
{

public:
    bool removeUser(User &user);
    void addDoctor(Doctor &doctor);
};