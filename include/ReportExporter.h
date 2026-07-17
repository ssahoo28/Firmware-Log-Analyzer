#ifndef REPORTEXPORTER_H
#define REPORTEXPORTER_H

#include <string>

class Statistics;

class ReportExporter
{
public:

    void exportText(const Statistics& stats,
                    int totalLogs,
                    const std::string& filename);
};

#endif