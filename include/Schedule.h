#pragma once
#include <string>
#include <vector>
#include "Slot.h"

class Schedule
{
private:
    std::vector<Slot> slots;

public:
    Schedule(std::string user_id, int user_type);
    Schedule();
    std::vector<Slot> getavailableSlots();
    void addSlot(Slot &slot);
    void removeSlot(Slot &slot);
    std::vector<Slot> getSlots();
};
