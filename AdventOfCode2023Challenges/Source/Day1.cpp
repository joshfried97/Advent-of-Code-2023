#include "../Include/Day1.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int DayOne::ParseNumber(const std::string& line_)
{
    // Initialise values
    int n = 1;
    int tens = 0;
    int units = 0;
    int finVal = 0;

    for (char c : line_) {
        if (std::isdigit(c)) {
            if (n == 1)
            {
                // Convert char to num with nice hack: https://sentry.io/answers/char-to-int-in-c-and-cpp/
                tens = c - '0';
                finVal += tens * pow(10, n--);
            }
            else
            {
                // Store subsequent numbers found as units, we'll use the last stored value for the units
                units = c - '0';
                n--;
            }
        }
    }

    if (n > -1)
    {
        // This is the case if there is only one number in the string
        finVal += tens;
    }
    else
    {
        // Use the last stored units value
        finVal += units;
    }
    
    return finVal;
}

int DayOne::ReadFile(const std::string& filename_)
{
    // Open the file
    std::ifstream file(filename_);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename_);
    }

    // Read and process each line one at a time
    std::string line;
    int total = 0;
    while (std::getline(file, line)) {
        // Skip empty lines
        if (!line.empty()) {
            // Ensure each line contains a valid string
            bool valid = true;
            for (char c : line) {
                if (!std::isalnum(c)) {
                    valid = false;
                    break;
                }
            }

            // Call the function to return the value hidden in the string
            int val = ParseNumber(line);

            if (valid) {
                std::cout << "Valid alphanumeric line: " << line << ". Numerical value: " << val << "\n";
                total += val;
            }
            else {
                std::cout << "Invalid line (contains non-alphanumeric characters): " << line << "\n";
            }
        }
    }

    // Close the file
    file.close();

    // Return the final value
    return total;
}

void DayOne::Main()
{
	cout << "Day 1 Challenge started.." << endl;

    try {
        string filename = "TestInput/DayOneTestInput.txt";
        int total = ReadFile(filename);
        cout << "Sum of calibration values is: " << total << endl;
    }
    catch (const std::exception& e) {
        cerr << "Error: " << e.what() << "\n";
    }

    cout << "Day 1 Challenge finished.." << endl;
}