#include "LogFile.h"
#include "LogParser.h"

bool LogFile::load(const std::string& filename)
{
    LogParser parser;

    logs = parser.parseFile(filename);

    return !logs.empty();
}

const std::vector<LogEntry>& LogFile::getLogs() const
{
    return logs;
}