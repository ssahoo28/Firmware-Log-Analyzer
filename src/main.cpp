#include <iostream>

#include "LogAnalyzer.h"
#include "LogParser.h"

int main()
{
    LogParser parser;
    LogAnalyzer analyzer;

    std::vector<LogEntry> logs =
        parser.parseFile("../logs/sample_log.txt");

    int choice;

    do
    {
        std::cout << "\n=========================================\n";
        std::cout << "       Firmware Log Analyzer\n";
        std::cout << "=========================================\n";

        std::cout << "1. Show Summary\n";
        std::cout << "2. Show ERROR Logs\n";
        std::cout << "3. Search Module\n";
        std::cout << "4. Search Keyword\n";
        std::cout << "5. Export Report\n";
        std::cout << "6. Exit\n";

        std::cout << "\nEnter Choice : ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            analyzer.analyze(logs);
            break;

        case 2:
            analyzer.showErrorLogs(logs);
            break;

        case 3:
        {
            std::string module;

            std::cout << "Enter Module : ";
            std::cin >> module;

            analyzer.searchModule(logs, module);
            break;
        }

        case 4:
        {
            std::string keyword;

            std::cout << "Enter Keyword : ";

            std::cin.ignore();
            std::getline(std::cin, keyword);

            analyzer.searchKeyword(logs, keyword);
            break;
        }

        case 5:
            analyzer.exportReport(logs);
            break;

        case 6:
            std::cout << "\nExiting...\n";
            break;

        default:
            std::cout << "Invalid Choice\n";
        }

    } while (choice != 6);

    return 0;
}