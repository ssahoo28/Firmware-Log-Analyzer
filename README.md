# Firmware-Log-Analyzer
# Firmware Log Analyzer

A modular **C++ Firmware Log Analyzer** that parses firmware diagnostic logs, analyzes log data, generates statistics, and exports reports. The project demonstrates object-oriented design, STL usage, file handling, and CMake-based project organization.

---

## Features

- Parse firmware log files
- Classify logs by severity
  - INFO
  - WARNING
  - ERROR
- Display log summary statistics
- Search logs by module
- Search logs by keyword
- Display only ERROR logs
- Export analysis report to a text file
- Modular object-oriented architecture
- CMake build support

---

## Project Structure

```
Firmware-Log-Analyzer
│
├── include/
│   ├── Filter.h
│   ├── LogAnalyzer.h
│   ├── LogEntry.h
│   ├── LogFile.h
│   ├── LogLevelUtils.h
│   ├── LogParser.h
│   ├── ReportExporter.h
│   ├── Sorter.h
│   ├── Statistics.h
│   └── Timestamp.h
│
├── src/
│   ├── Filter.cpp
│   ├── LogAnalyzer.cpp
│   ├── LogFile.cpp
│   ├── LogLevelUtils.cpp
│   ├── LogParser.cpp
│   ├── ReportExporter.cpp
│   ├── Sorter.cpp
│   ├── Statistics.cpp
│   ├── Timestamp.cpp
│   └── main.cpp
│
├── logs/
│   └── sample.log
│
├── output/
│   └── report.txt
│
├── CMakeLists.txt
└── README.md
```

---

## Software Design

The application is organized into reusable modules.

```
                 +----------------+
                 |    main.cpp    |
                 +-------+--------+
                         |
                         |
                  +------+------+
                  |   LogFile    |
                  +------+------+
                         |
                  +------+------+
                  |  LogParser   |
                  +------+------+
                         |
                  vector<LogEntry>
                         |
                  +------+------+
                  | LogAnalyzer |
                  +------+------+
                         |
        +----------------+----------------+
        |                |                |
   Statistics        Filter        ReportExporter
```

Each class has a single responsibility, making the project modular and easy to extend.

---

## Sample Log Format

```
[2026-07-17 10:00:01] INFO PM Power initialization completed
[2026-07-17 10:00:03] WARNING SPDM Certificate mismatch
[2026-07-17 10:00:04] ERROR PM Timeout waiting for VR
```

---

## Sample Output

```
=========== Firmware Log Report ===========

Total Logs : 10

INFO : 4
WARNING : 2
ERROR : 4

Module Statistics

BMC : 1
PM : 3
RESET : 1
SECURITY : 1
SPDM : 2
TELEMETRY : 2
```

---

## Technologies Used

- C++17
- Object-Oriented Programming (OOP)
- STL
  - vector
  - map
  - string
- File Handling
- CMake
- Git

---

## Concepts Demonstrated

- Object-Oriented Design
- Separation of Concerns
- Single Responsibility Principle
- Modular Architecture
- File Parsing
- Data Processing
- STL Containers
- Report Generation

---

## Build Instructions

### Clone Repository

```bash
git clone https://github.com/<your-username>/Firmware-Log-Analyzer.git
```

### Create Build Directory

```bash
mkdir build
cd build
```

### Configure

```bash
cmake ..
```

### Build

```bash
cmake --build .
```

### Run

```bash
./FirmwareLogAnalyzer
```

---

## Future Enhancements

- CSV report export
- JSON report export
- Case-insensitive search
- Regular expression search
- Timestamp range filtering
- Configuration file support
- Unit testing using GoogleTest
- Multithreaded log processing
- Interactive command-line arguments

---

## Author

**Sonali Sahoo**

Firmware Engineer | C++ | Firmware | Embedded Systems | Intel Xeon Platform
