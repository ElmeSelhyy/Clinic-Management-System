#include "../include/Schedule.h"
#include "../include/FileHandler.h"
#include "../include/MacroAndDefintions.h"
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
Schedule::Schedule()
{
    // Default constructor
}
Schedule::Schedule(std::string user_id, int user_type)
{
    FileHandler fileHandler = FileHandler(SLOT_FILE);
    this->slots = fileHandler.getAllDataWithID(user_id);
}

void Schedule::addSlot(std::string &slot)
{
    slots.push_back(slot);
     FileHandler fileHandler = FileHandler(SLOT_FILE);
    fileHandler.writeFile(slot);


}

void Schedule::removeSlot(std::string &slot)
{
    for (int i = 0; i < slots.size(); i++)
    {
        if (slots[i] == slot)
        {
            slots.erase(slots.begin() + i);
            break;
        }
    }
}

std::vector<std::string> Schedule::getavailableSlots()
{
    std::vector<std::string> slots;

    for (int i = 0; i < slots.size(); i++)
    {
        std::istringstream iss(slots[i]);
        std::string patientName;
        iss >> patientName;
        if (patientName == "NULL")
        {
            slots.push_back(slots[i]);
        }
    }

    return slots;
}

std::vector<std::string> Schedule::getSlots()
{
    return slots;
}
