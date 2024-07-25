#pragma one
#include <string>
#include "include/User.h"
#include <vector>
class FileHandler
{
private:
    std::string filename;

public:
    FileHandler(const std::string &filename);
    std::vector<string> SearchinFile(const std::string &Keyword);
    bool writeFile(const std::string &record);
    int searchCredentials(const std::string &username, const std::string &password);
    bool RemoveCredentials(const &int userID);
};
