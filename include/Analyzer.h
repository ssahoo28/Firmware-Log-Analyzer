#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>
#include <string>
#include <map>

#include "LogEntry.h"

class Analyzer
{
public:

    void analyze(const std::vector<LogEntry>& logs);

private:

    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;

    std::map<std::string, int> moduleCount;
};

#endif