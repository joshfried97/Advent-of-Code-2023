#include "Day2.h";

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// These are the maximum number of each colour allowed
#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int DayTwo::ParseGameInfo(const std::string& line_)
{
    return 0;
}

int DayTwo::ReadFile(const std::string& filename_)
{
    // Open the file
    std::ifstream file(filename_);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename_);
    }

    // Read and process each line one at a time
    std::string line;
    int total = 0;
    bool possible = false;
    while (std::getline(file, line)) {
        // Skip empty lines
        if (!line.empty()) {
            // Call the function to return the sum of the IDs which match the criteria
            int val = ParseGameInfo(line);

            if (possible)
            {
                cout << line << " - Possible => Total = " << total << endl;
            }
            else
            {
                cout << line << " - Not possible" << endl;
            }
        }
    }
}

void DayTwo::Main()
{
    cout << "Day 2 Challenge started.." << endl;

    try {
        string filename = "DayTwoTestInput.txt";
        int total = ReadFile(filename);
        cout << "Sum of ID values is: " << total << endl;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    cout << "Day 2 Challenge finished.." << endl;
}