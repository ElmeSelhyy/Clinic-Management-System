#include "../include/Schedule.h"

void Schedule::addSlot(Slot slot)
{
    slots.push_back(slot);
}

void Schedule::removeSlot(Slot slot)
{
    for (int i = 0; i < slots.size(); i++)
    {
        if (slots[i].getDoctorPtr() == slot.getDoctorPtr() && slots[i].gettimeSlot() == slot.gettimeSlot())
        {
            slots.erase(slots.begin() + i);
        }
    }
}

std::vector<Slot> &Schedule::getavailableSlots()
{
    // Filter the existing slots vector to remove unavailable slots
    slots.erase(
        std::remove_if(slots.begin(), slots.end(), [](const Slot &slot)
                       { return slot.getPatientPtr() == nullptr; }),
        slots.end());

    // Return the filtered slots vector
    return slots;
}
std::vector<Slot> &Schedule::getSlots()
{
    return slots;
}
