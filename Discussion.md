# Efficient Log Retrieval from a Large File

## Problem Statement
You need to extract logs from a massive 1TB log file efficiently. Each log entry starts with a timestamp, followed by a log level and a message. The script should take a specific date as an argument and retrieve all matching log entries.

## Solutions Considered

### 1. Reading the Entire File into Memory
- This method loads the complete file into memory and filters log entries based on the date.
- **Why Rejected?** Since the file is around 1TB, this approach is impractical due to excessive memory usage.

### 2. Streaming Approach (Line-by-Line Processing)
- The file is read sequentially, checking each line for the target date.
- **Why Chosen?** It is memory-efficient, scalable, and ensures optimal performance by processing only the required data.

## Final Solution Summary
The implemented solution reads the log file line by line, extracting only the relevant log entries based on the provided date. This ensures minimal resource usage while effectively retrieving logs.

## Steps to Run

### 1. Compile the Code
Use a C++ compiler to compile the program:

```bash
g++ -o extract_logs src/extract_logs.cpp
