#pragma once

// #include "Slot.h"
#include <vector>
class Slot;
class Schedule
{
private:
    std::vector<Slot> slots;

public:
    Schedule(int user_id, int user_type);
    Schedule();
    std::vector<Slot> getavailableSlots();
    void addSlot(Slot &slot);
    void removeSlot(Slot &slot);
    std::vector<Slot> getSlots();
};
