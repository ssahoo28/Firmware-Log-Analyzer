#include "Analyzer.h"

#include <iostream>

void Analyzer::analyze(const std::vector<LogEntry>& logs)
{
    infoCount = 0;
    warningCount = 0;
    errorCount = 0;

    moduleCount.clear();

    for (const auto& log : logs)
    {
        if (log.level == "INFO")
            infoCount++;
        else if (log.level == "WARNING")
            warningCount++;
        else if (log.level == "ERROR")
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