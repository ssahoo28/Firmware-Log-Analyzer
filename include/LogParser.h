#ifndef LOGPARSER_H
#define LOGPARSER_H

#include <vector>
#include <string>

#include "LogEntry.h"

class LogParser
{
public:
    std::vector<LogEntry> parseFile(const std::string& filename);
};

#endif