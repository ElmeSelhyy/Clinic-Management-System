#pragma once
#include <string>
#include <vector>
// #include "Slot.h"

class Schedule
{
private:
    std::vector<std::string> slots;

public:
    Schedule(std::string user_id, int user_type);
    Schedule();
    std::vector<std::string> getavailableSlots();
    void addSlot(std::string &slot);
    void removeSlot(std::string &slot);
    std::vector<std::string> getSlots();
};
