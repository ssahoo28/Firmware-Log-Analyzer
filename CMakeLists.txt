cmake_minimum_required(VERSION 3.15)

project(FirmwareLogAnalyzer)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(
    FirmwareLogAnalyzer

    src/main.cpp
    src/LogParser.cpp
    src/LogAnalyzer.cpp
    src/LogLevelUtils.cpp
    src/LogFile.cpp
    src/Filter.cpp
    src/ReportExporter.cpp
    src/Sorter.cpp
)