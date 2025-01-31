#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <filesystem>
#include <regex>

void extractLogs(const std::string& date, const std::string& inputFile, const std::string& outputDir) {
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << inputFile << std::endl;
        return;
    }

    if (!std::filesystem::exists(outputDir)) {
        std::filesystem::create_directories(outputDir);
    }

    std::string outputFile = outputDir + "/output_" + date + ".txt";
    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not create output file " << outputFile << std::endl;
        return;
    }

    std::string line;
    std::regex datePattern("^" + date + ".*"); // Match lines starting with the date
    int count = 0;

    while (std::getline(inFile, line)) {
        if (std::regex_match(line, datePattern)) {
            outFile << line << '\n';
            count++;
        }
    }

    std::cout << "Extracted " << count << " log entries for date " << date << ".\n";
    std::cout << "Output written to: " << outputFile << std::endl;

    inFile.close();
    outFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <YYYY-MM-DD>\n";
        return 1;
    }

    std::string date = argv[1];
    std::regex dateRegex("^\\d{4}-\\d{2}-\\d{2}$");
    if (!std::regex_match(date, dateRegex)) {
        std::cerr << "Error: Invalid date format. Use YYYY-MM-DD.\n";
        return 1;
    }

    const std::string inputFile = "test_logs.log";
    const std::string outputDir = "output";

    extractLogs(date, inputFile, outputDir);

    return 0;
}
