#include "Day2.h";

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// These are the maximum number of each colour allowed
#define MAX_RED 12
#define MAX_GREEN 13
#define MAX_BLUE 14

int DayTwo::ParseGameInfo(const std::string& line_)
{
    std::istringstream iss(line_);
    std::string temp;

    // Initialize the max values for green, blue, and red
    int maxValues[3];
    maxValues[0] = maxValues[1] = maxValues[2] = 0;

    // Ignore "Game <ID>:"
    std::getline(iss, temp, ':');

    // Process rounds
    std::string roundsPart;
    while (std::getline(iss, roundsPart, ';')) {
        std::istringstream roundStream(roundsPart);
        while (roundStream >> temp) {
            // Read the count
            int count = std::stoi(temp);

            // Read the color
            std::string color;
            roundStream >> color;

            // Remove any trailing comma
            if (color.back() == ',') {
                color.pop_back();
            }

            // Update max values for each color
            if (color == "green") {
                maxValues[0] = std::max(maxValues[0], count);
            }
            else if (color == "blue") {
                maxValues[1] = std::max(maxValues[1], count);
            }
            else if (color == "red") {
                maxValues[2] = std::max(maxValues[2], count);
            }
        }
    }

    // Return the power of the minimum set of cubes
    return maxValues[0] * maxValues[1] * maxValues[2];
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
    while (std::getline(file, line)) {
        // Skip empty lines
        if (!line.empty()) {
            total += ParseGameInfo(line);
        }
    }

    return total;
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