#ifndef STATISTICS_H
#define STATISTICS_H

#include <map>
#include <string>
#include <vector>

#include "LogEntry.h"

class Statistics
{
public:

    void calculate(const std::vector<LogEntry>& logs);

    int getInfoCount() const;

    int getWarningCount() const;

    int getErrorCount() const;

    const std::map<std::string,int>& getModuleCount() const;

private:

    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;

    std::map<std::string,int> moduleCount;
};

#endif