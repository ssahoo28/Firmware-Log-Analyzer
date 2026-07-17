#include "LogParser.h"

#include <fstream>
#include <iostream>

std::vector<LogEntry> LogParser::parseFile(const std::string& filename)
{
    std::vector<LogEntry> logs;

    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "Unable to open file\n";
        return logs;
    }

    std::string line;

    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }

    return logs;
}