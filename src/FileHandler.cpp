#include "include/FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileHandler::FileHandler(const std::string &filename)
{
    this->filename = filename;
}

static FileHandler::FileHandler &getInstance(const std::string &filename)
{
    if (instance == nullptr)
    {
        instance = new FileHandler(filename);
    }
    return *instance;
}

bool FileHandler::writeFile(const std::string &record)
{
    std::ofstream outFile(filename, std::ios::app); // Append mode

    if (!outFile.is_open())
    {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return false;
    }

    outFile << record << std::endl;
    outFile.close();
    return true;
}

int FileHandler::searchCredentials(const std::string &username, const std::string &password)
{
    std::ifstream inFile(this->filename);
    std::string line;

    if (!inFile.is_open())
    {
        std::cerr << "Unable to open file for reading: " << this->filename << std::endl;
        return false;
    }

    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string userID, fileUsername, filePassword, name, age;

        if (!(iss >> userID >> fileUsername >> filePassword >> name >> age))
        {
            continue; // Skip malformed lines
        }

        if (fileUsername == username && filePassword == password)
        {
            userDetails = line;
            inFile.close();
            return userID;
        }
    }

    inFile.close();
    return -1;
}