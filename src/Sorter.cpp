#include "Sorter.h"

#include <algorithm>

void Sorter::byTimestamp(
        std::vector<LogEntry>& logs)
{
    std::sort(
        logs.begin(),
        logs.end(),
        [](const LogEntry& a,
           const LogEntry& b)
        {
            return a.timestamp < b.timestamp;
        });
}

void Sorter::byModule(
        std::vector<LogEntry>& logs)
{
    std::sort(
        logs.begin(),
        logs.end(),
        [](const LogEntry& a,
           const LogEntry& b)
        {
            return a.module < b.module;
        });
}

int priority(LogLevel level)
{
    switch(level)
    {
        case LogLevel::ERROR:
            return 3;

        case LogLevel::WARNING:
            return 2;

        case LogLevel::INFO:
            return 1;

        default:
            return 0;
    }
}

void Sorter::bySeverity(
        std::vector<LogEntry>& logs)
{
    std::sort(
        logs.begin(),
        logs.end(),
        [](const LogEntry& a,
           const LogEntry& b)
        {
            return priority(a.level)>
                   priority(b.level);
        });
}