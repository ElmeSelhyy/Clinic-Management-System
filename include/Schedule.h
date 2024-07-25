#pragma once

#include "Slot.h"
#include <vector>

class Schedule
{
private:
    std::vector<Slot> slots;

public:
    Schedule(int user_id, int user_type);
    Slot getavailableSlots();
    void addSlot(Slot &slot);
    void removeSlot(Slot &slot);
    void getSlots();
};
