#include "LogAnalyzer.h"

#include <iostream>
#include <fstream>
#include <LogLevelUtils.h>

void LogAnalyzer::analyze(const std::vector<LogEntry>& logs)
{
    infoCount = 0;
    warningCount = 0;
    errorCount = 0;

    moduleCount.clear();

    for (const auto& log : logs)
    {
        if(log.level==LogLevel::INFO)
            infoCount++;
        else if(log.level==LogLevel::WARNING)
            warningCount++;
        else if (log.level == LogLevel::ERROR)
            errorCount++;

        moduleCount[log.module]++;
    }

    std::cout << "\n";
    std::cout << "=========== Firmware Log Report ===========" << std::endl;

    std::cout << "Total Logs   : " << logs.size() << std::endl;
    std::cout << "INFO         : " << infoCount << std::endl;
    std::cout << "WARNING      : " << warningCount << std::endl;
    std::cout << "ERROR        : " << errorCount << std::endl;

    std::cout << "\nModule Statistics\n";
    std::cout << "-----------------\n";

    for (const auto& module : moduleCount)
    {
        std::cout << module.first
                  << " : "
                  << module.second
                  << std::endl;
    }

    std::cout << "===========================================" << std::endl;
}

void LogAnalyzer::showErrorLogs(const std::vector<LogEntry>& logs)
{
    std::cout << "\n========== ERROR LOGS ==========\n\n";

    int count = 0;

    for (const auto& log : logs)
    {
        if (log.level == LogLevel::ERROR)
        {
            count++;

            std::cout << "Timestamp : "
                      << log.timestamp << std::endl;

            std::cout << "Module    : "
                      << log.module << std::endl;

            std::cout << "Message   : "
                      << log.message << std::endl;

            std::cout
                << "--------------------------------------\n";
        }
    }

    std::cout << "Total ERROR Logs : "
              << count
              << std::endl;
}

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
                      << log.level << std::endl;

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
                      << logLevelToString(log.level) << std::endl;

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
    std::ofstream report("../output/report.txt");

    if (!report)
    {
        std::cout << "Unable to create report file.\n";
        return;
    }

    report << "=========== Firmware Log Report ===========" << std::endl;
    report << "Total Logs : " << logs.size() << std::endl;
    report << "INFO : " << infoCount << std::endl;
    report << "WARNING : " << warningCount << std::endl;
    report << "ERROR : " << errorCount << std::endl;

    report << "\nModule Statistics\n";
    report << "-----------------\n";

    for (const auto& module : moduleCount)
    {
        report << module.first
               << " : "
               << module.second
               << std::endl;
    }

    report << "===========================================" << std::endl;

    report.close();

    std::cout << "Report exported successfully!\n";
}