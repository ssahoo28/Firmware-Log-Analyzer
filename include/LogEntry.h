#ifndef LOGENTRY_H
#define LOGENTRY_H

#include <string>

struct LogEntry
{
    std::string timestamp;
    std::string level;
    std::string module;
    std::string message;
};

#endif