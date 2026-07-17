#ifndef FILTER_H
#define FILTER_H

#include <vector>
#include <string>

#include "LogEntry.h"

class Filter
{
public:

    static std::vector<LogEntry> byLevel(
        const std::vector<LogEntry>& logs,
        LogLevel level);

    static std::vector<LogEntry> byModule(
        const std::vector<LogEntry>& logs,
        const std::string& module);

    static std::vector<LogEntry> byKeyword(
        const std::vector<LogEntry>& logs,
        const std::string& keyword);
};

#endif