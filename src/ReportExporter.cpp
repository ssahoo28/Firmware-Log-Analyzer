#include "ReportExporter.h"

#include "Statistics.h"

#include <fstream>
#include <iostream>

void ReportExporter::exportText(
        const Statistics& stats,
        int totalLogs,
        const std::string& filename)
{
    std::ofstream report(filename);

    if(!report)
    {
        std::cout<<"Unable to create report\n";
        return;
    }

    report<<"=========== Firmware Log Report ==========="<<std::endl;

    report<<"Total Logs : "<<totalLogs<<std::endl;

    report<<"INFO : "<<stats.getInfoCount()<<std::endl;

    report<<"WARNING : "<<stats.getWarningCount()<<std::endl;

    report<<"ERROR : "<<stats.getErrorCount()<<std::endl;

    report<<"\nModule Statistics\n";

    for(const auto& module : stats.getModuleCount())
    {
        report<<module.first
              <<" : "
              <<module.second
              <<std::endl;
    }

    std::cout<<"Report exported successfully!\n";
}