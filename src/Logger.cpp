#include "../include/Logger.h"
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>

Logger::Logger(const std::string &filename) : logFile(filename, std::ios::app)
{
    if (!logFile.is_open())
    {
        std::cerr << "Could not open the log file: " << filename << std::endl;
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

void Logger::log(const std::string &message)
{
    if (logFile.is_open())
    {
        logFile << message << std::endl;
    }
}
