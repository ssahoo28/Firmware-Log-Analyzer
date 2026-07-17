#ifndef SORTER_H
#define SORTER_H

#include <vector>

#include "LogEntry.h"

class Sorter
{
public:

    static void byTimestamp(
        std::vector<LogEntry>& logs);

    static void byModule(
        std::vector<LogEntry>& logs);

    static void bySeverity(
        std::vector<LogEntry>& logs);
};

#endif