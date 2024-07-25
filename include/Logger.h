#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Logger
{

    std::ofstream logFile;

public:
    Logger(const std::string &filename);

    ~Logger();

    void log(const std::string &message);
};
