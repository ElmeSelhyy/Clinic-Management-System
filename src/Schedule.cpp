#include "../include/Schedule.h"
#include "../include/FileHandler.h"
#include "../include/MacroAndDefintions.h"
#include <vector>
#include <algorithm>

Schedule::Schedule()
{
    // Default constructor
}
Schedule::Schedule(std::string user_id, int user_type)
{
    FileHandler fileHandler = FileHandler(SLOT_FILE);
    std::vector<std::string> slots = fileHandler.getAllDataWithID(user_id);
    // for (int i = 0; i < slots.size(); i++)
    // {
    //     std::vector<std::string> slot = split(slots[i], ' ');
    //     Slot newSlot = Slot(slot[0], slot[1], slot[2], slot[3], slot[4]);
    //     slots.push_back(newSlot);
    // }
}

void Schedule::addSlot(Slot &slot)
{
    slots.push_back(slot);
}

void Schedule::removeSlot(Slot &slot)
{
    // for (int i = 0; i < slots.size(); i++)
    // {
    //     if (slots[i].getDoctorPtr() == slot.getDoctorPtr() && slots[i].gettimeSlot() == slot.gettimeSlot())
    //     {
    //         slots.erase(slots.begin() + i);
    //     }
    // }
}

std::vector<Slot> Schedule::getavailableSlots()
{
    std::vector<Slot> slotss;
    // Filter the existing slots vector to remove unavailable slots
    // slots.erase(
    //     std::remove_cv(slots.begin(), slots.end(), [](const Slot &slot)
    //                    { return slot.getPatientPtr() == nullptr; }),
    //     slots.end());

    // Return the filtered slots vector
    return slotss;
}
std::vector<Slot> Schedule::getSlots()
{
    return slots;
}
