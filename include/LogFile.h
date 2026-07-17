#ifndef LOGFILE_H
#define LOGFILE_H

#include <vector>

#include "LogEntry.h"

class LogFile
{
private:

    std::vector<LogEntry> logs;

public:

    bool load(const std::string& filename);

    const std::vector<LogEntry>& getLogs() const;
};

#endif