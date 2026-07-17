#include "LogLevelUtils.h"

LogLevel stringToLogLevel(const std::string& level)
{
    if(level=="INFO")
        return LogLevel::INFO;

    if(level=="WARNING")
        return LogLevel::WARNING;

    if(level=="ERROR")
        return LogLevel::ERROR;

    return LogLevel::UNKNOWN;
}

std::string logLevelToString(LogLevel level)
{
    switch(level)
    {
        case LogLevel::INFO:
            return "INFO";

        case LogLevel::WARNING:
            return "WARNING";

        case LogLevel::ERROR:
            return "ERROR";

        default:
            return "UNKNOWN";
    }
}