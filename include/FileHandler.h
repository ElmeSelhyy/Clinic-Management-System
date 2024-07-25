#pragma one
#include <string>
#include "include/User.h"

class FileHandler
{
private:
    std::string filename;

public:
    FileHandler(const std::string &filename);
    std::string readFile();
    bool writeFile(const std::string &record);
    int searchCredentials(const std::string &username, const std::string &password);
    bool RemoveCredentials(const &int userID);
};
