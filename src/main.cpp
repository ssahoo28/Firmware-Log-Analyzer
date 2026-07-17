#include <iostream>

#include "LogParser.h"
#include "Analyzer.h"

int main()
{
    LogParser parser;

    std::vector<LogEntry> logs =
        parser.parseFile("../logs/sample_log.txt");

    std::cout << "Total Logs : "
              << logs.size()
              << "\n\n";

    Analyzer analyzer;
    analyzer.analyze(logs);

    /*
    for (const auto& log : logs)
    {
        std::cout << "Timestamp : " << log.timestamp << std::endl;
        std::cout << "Level     : " << log.level << std::endl;
        std::cout << "Module    : " << log.module << std::endl;
        std::cout << "Message   : " << log.message << std::endl;

        std::cout
            << "--------------------------------------\n";
    }
    */
   
    return 0;
}