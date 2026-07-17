#include "LogParser.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>


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
        LogEntry entry;

        // -----------------------------
        // Extract Timestamp
        // -----------------------------
        size_t endBracket = line.find(']');

        if (endBracket == std::string::npos)
            continue;

        entry.timestamp = line.substr(1, endBracket - 1);

        // Remaining part after ]
        std::string remaining = line.substr(endBracket + 2);

        std::stringstream ss(remaining);

        // -----------------------------
        // Extract Level
        // -----------------------------
        ss >> entry.level;

        // -----------------------------
        // Extract Module
        // -----------------------------
        ss >> entry.module;

        // -----------------------------
        // Extract Message
        // -----------------------------
        std::getline(ss >> std::ws, entry.message);

        logs.push_back(entry);
    }

    return logs;
}