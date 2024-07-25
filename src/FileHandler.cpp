#include "../include/FileHandler.h"
#include <fstream>
#include <sstream>
#include <iostream>

FileHandler::FileHandler(const std::string &filename)
{
    this->filename = filename;
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
        std::string userID, fileUsername, filePassword, name, age, userType;

        if (!(iss >> userID >> fileUsername >> filePassword >> name >> age >> userType))
        {
            continue; // Skip malformed lines
        }
        std::cout<<"fileUsername: "<<fileUsername<<"\n";
        if (fileUsername == username && filePassword == password)
        {
            inFile.close();
            return stoi(userType);
        }
    }

    inFile.close();
    return -1;
}

bool FileHandler::RemoveCredentials(const int &ID)
{
    std::ifstream inFile(filename);
    std::ofstream tempFile("temp.txt");
    std::string line;
    bool found = false;

    if (!inFile.is_open() || !tempFile.is_open())
    {
        std::cerr << "Unable to open file for reading or writing: " << filename << std::endl;
        return false;
    }

    while (std::getline(inFile, line))
    {
        std::istringstream iss(line);
        std::string userID, fileUsername, filePassword, name, age;

        if (!(iss >> userID >> fileUsername >> filePassword >> name >> age))
        {
            tempFile << line << std::endl;
            continue;
        }

        if (stoi(userID) == ID)
        {
            found = true;
            continue;
        }

        tempFile << line << std::endl;
    }

    inFile.close();
    tempFile.close();

    if (found)
    {
        std::remove(filename.c_str());
        std::rename("temp.txt", filename.c_str());
    }
    else
    {
        std::remove("temp.txt");
    }

    return found;
}

std::vector<std::string> FileHandler::SearchinFile(const std::string &Keyword)
{
    std::ifstream inFile(this->filename);
    std::string line;
    std::vector<std::string> searchResults;

    if (!inFile.is_open())
    {
        std::cerr << "Unable to open file for reading: " << this->filename << std::endl;
        return searchResults;
    }

    while (std::getline(inFile, line))
    {
        if (line.find(Keyword) != std::string::npos)
        {
            searchResults.push_back(line);
        }
    }

    inFile.close();
    return searchResults;
}