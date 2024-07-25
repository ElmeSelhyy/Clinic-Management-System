#pragma once
#include <string>
#include <vector>
class FileHandler
{
private:
    std::string filename;

public:
    FileHandler(const std::string &filename);
    std::vector<std::string> getAllDataWithID(const std::string &Keyword);
    std::string getFirstDataWithID(const std::string &Keyword);
    bool writeFile(const std::string &record);
    std::string searchCredentials(const std::string &username, const std::string &password);
    bool RemoveCredentials(const int &userID);
};
