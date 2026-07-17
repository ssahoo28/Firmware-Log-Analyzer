#ifndef ANALYZER_H
#define ANALYZER_H

#include <map>
#include <string>
#include <vector>

#include "LogEntry.h"
#include "Statistics.h"
#include "ReportExporter.h"

class LogAnalyzer
{
public:

    void analyze(const std::vector<LogEntry>& logs);

    void showErrorLogs(const std::vector<LogEntry>& logs);

    void searchModule(const std::vector<LogEntry>& logs,
                      const std::string& module);

    void searchKeyword(const std::vector<LogEntry>& logs,
                       const std::string& keyword);

    void exportReport(const std::vector<LogEntry>& logs);
    
    void sortByTimestamp(std::vector<LogEntry>& logs);

private:

    Statistics statistics;
    ReportExporter exporter;
    
};

#endif