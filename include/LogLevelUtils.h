#ifndef LOGLEVELUTILS_H
#define LOGLEVELUTILS_H

#include <string>

#include "LogEntry.h"

LogLevel stringToLogLevel(const std::string& level);

std::string logLevelToString(LogLevel level);

#endif