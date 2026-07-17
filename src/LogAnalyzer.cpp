#include "LogAnalyzer.h"
#include "Filter.h"

#include <iostream>
#include <fstream>
#include <LogLevelUtils.h>

void LogAnalyzer::analyze(const std::vector<LogEntry>& logs)
{
   statistics.calculate(logs);

    std::cout << "\n";
    std::cout << "=========== Firmware Log Report ===========" << std::endl;

    std::cout << "Total Logs   : " << logs.size() << std::endl;
    std::cout << "INFO         : " << statistics.getInfoCount() << std::endl;
    std::cout << "WARNING      : " << statistics.getWarningCount() << std::endl;
    std::cout << "ERROR        : " << statistics.getErrorCount() << std::endl;

    std::cout << "\nModule Statistics\n";
    std::cout << "-----------------\n";

    for (const auto& module : statistics.getModuleCount())
    {
        std::cout << module.first
                  << " : "
                  << module.second
                  << std::endl;
    }

    std::cout << "===========================================" << std::endl;
}

auto errors =
    Filter::byLevel(logs, LogLevel::ERROR);

void LogAnalyzer::searchModule(const std::vector<LogEntry>& logs,
                            const std::string& module)
{
    int count = 0;

    std::cout << "\n====== MODULE : "
              << module
              << " ======\n\n";

    for (const auto& log : logs)
    {
        if (log.module == module)
        {
            count++;

            std::cout << "Timestamp : "
                      << log.timestamp << std::endl;

            std::cout << "Level     : "
                      <<  logLevelToString(log.level) << std::endl;

            std::cout << "Message   : "
                      << log.message << std::endl;

            std::cout
                << "--------------------------------------\n";
        }
    }

    if (count == 0)
    {
        std::cout << "No logs found.\n";
    }
    else
    {
        std::cout << "Total Matching Logs : "
                  << count
                  << std::endl;
    }
}

void LogAnalyzer::searchKeyword(const std::vector<LogEntry>& logs,
                             const std::string& keyword)
{
    int count = 0;

    std::cout << "\n========== SEARCH RESULTS ==========\n\n";

    for (const auto& log : logs)
    {
        if (log.message.find(keyword) != std::string::npos)
        {
            count++;

            std::cout << "Timestamp : "
                      << log.timestamp << std::endl;

            std::cout << "Level     : "
                      <<  logLevelToString(log.level) << std::endl;

            std::cout << "Module    : "
                      << log.module << std::endl;

            std::cout << "Message   : "
                      << log.message << std::endl;

            std::cout
                << "--------------------------------------\n";
        }
    }

    if (count == 0)
    {
        std::cout << "No matching logs found.\n";
    }
    else
    {
        std::cout << "Total Matching Logs : "
                  << count
                  << std::endl;
    }
}

void LogAnalyzer::exportReport(const std::vector<LogEntry>& logs)
{
    statistics.calculate(logs);

    exporter.exportText(
            statistics,
            logs.size(),
            "../output/report.txt");
}

void LogAnalyzer::sortByTimestamp(std::vector<LogEntry> &logs)
{
    std::sort(logs.begin(),
          logs.end(),
          [](const LogEntry& a,
             const LogEntry& b)
    {
        return a.timestamp < b.timestamp;
    });

}
