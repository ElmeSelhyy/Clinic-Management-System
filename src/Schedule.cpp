#include "../include/Schedule.h"
#include "../include/FileHandler.h"
#include "../include/MacroAndDefintions.h"
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream> 
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

bool Schedule::removeSlot(std::string &slot)
{
    for (int i = 0; i < slots.size(); i++)
    {
        if (slots[i] == slot)
        
        {
            slots.erase(slots.begin() + i);
            break;
        }
    }

    
    std::vector<std::string> words;
    std::istringstream iss(slot);
    // Extract words from the line
    while (iss >> slot)
    {
        words.push_back(slot);
    }
    std::ifstream infile(SLOT_FILE);
    std::ofstream outfile(TEMP_FILE);
    std::string line;
    bool changed=false;

    while (std::getline(infile, line)) {
        if (line.find(words[0]) != std::string::npos && 
            line.find(words[1]) != std::string::npos && 
            line.find(words[2]) != std::string::npos){

            changed=true;
            continue;
        }
        outfile << line << std::endl;
    }
    infile.close();
    outfile.close();

    if(changed){
        remove(SLOT_FILE);
        rename(TEMP_FILE, SLOT_FILE);
    }
    else{
       
        remove(TEMP_FILE);
        return false;
    }
    return true;

    
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
