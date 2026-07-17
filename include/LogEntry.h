#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

enum class LogLevel
{
    INFO,
    WARNING,
    ERROR,
    UNKNOWN
};

struct LogEntry
{
    std::string timestamp;
    LogLevel level;
    std::string module;
    std::string message;
};

#endif