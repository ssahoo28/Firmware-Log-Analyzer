#include "Statistics.h"

void Statistics::calculate(const std::vector<LogEntry>& logs)
{
    infoCount = 0;
    warningCount = 0;
    errorCount = 0;

    moduleCount.clear();

    for(const auto& log : logs)
    {
        switch(log.level)
        {
            case LogLevel::INFO:
                infoCount++;
                break;

            case LogLevel::WARNING:
                warningCount++;
                break;

            case LogLevel::ERROR:
                errorCount++;
                break;

            default:
                break;
        }

        moduleCount[log.module]++;
    }
}

int Statistics::getInfoCount() const
{
    return infoCount;
}

int Statistics::getWarningCount() const
{
    return warningCount;
}

int Statistics::getErrorCount() const
{
    return errorCount;
}

const std::map<std::string,int>& Statistics::getModuleCount() const
{
    return moduleCount;
}