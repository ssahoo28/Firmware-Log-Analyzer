#include "LogParser.h"

int main()
{
    LogParser parser;

    parser.parseFile("../logs/sample_log.txt");

    return 0;
}