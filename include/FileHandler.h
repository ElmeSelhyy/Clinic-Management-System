#pragma one
#include <string>
#include "include/User.h"

class FileHandler
{
private:
    std::string filename;
    static FileHandler *instance;
    FileHandler(const std::string &filename);

public:
    static FileHandler &getInstance(const std::string &filename);

    bool writeFile(const std::string &record);
    User &searchCredentials(const std::string &username, const std::string &password);

    // delete copy constructor and assignment operator
    FileHandler(FileHandler const &) = delete;
    void operator=(FileHandler const &) = delete;
};

FileHandler *FileHandler::instance = nullptr;