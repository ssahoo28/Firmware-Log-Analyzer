#ifndef ANALYZER_H
#define ANALYZER_H

#include <map>
#include <string>
#include <vector>

#include "LogEntry.h"

class Analyzer
{
public:

    void analyze(const std::vector<LogEntry>& logs);

    void showErrorLogs(const std::vector<LogEntry>& logs);

    void searchModule(const std::vector<LogEntry>& logs,
                      const std::string& module);

    void searchKeyword(const std::vector<LogEntry>& logs,
                       const std::string& keyword);

    void exportReport(const std::vector<LogEntry>& logs);

private:

    int infoCount = 0;
    int warningCount = 0;
    int errorCount = 0;

    std::map<std::string, int> moduleCount;
};

#endif