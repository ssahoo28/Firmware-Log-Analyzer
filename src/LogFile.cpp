#include "LogFile.h"
#include "LogParser.h"

#include <iostream>

bool LogFile::load(const std::string& filename)
{
    try
    {
        LogParser parser;
        logs = parser.parseFile(filename);
        return true;
    }
    catch(const std::exception& e)
    {
        std::cout << "Failed to load file: "
                  << filename
                  << std::endl;

        std::cout << e.what() << std::endl;

        return false;
    }
}

const std::vector<LogEntry>& LogFile::getLogs() const
{
    return logs;
}