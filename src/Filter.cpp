#include "Filter.h"

std::vector<LogEntry> Filter::byLevel(
        const std::vector<LogEntry>& logs,
        LogLevel level)
{
    std::vector<LogEntry> result;

    for(const auto& log : logs)
    {
        if(log.level == level)
            result.push_back(log);
    }

    return result;
}

std::vector<LogEntry> Filter::byModule(
        const std::vector<LogEntry>& logs,
        const std::string& module)
{
    std::vector<LogEntry> result;

    for(const auto& log : logs)
    {
        if(log.module == module)
            result.push_back(log);
    }

    return result;
}

std::vector<LogEntry> Filter::byKeyword(
        const std::vector<LogEntry>& logs,
        const std::string& keyword)
{
    std::vector<LogEntry> result;

    for(const auto& log : logs)
    {
        if(log.message.find(keyword)!=std::string::npos)
            result.push_back(log);
    }

    return result;
}