#include "../Include/Day4.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>

int DayFour::ReadCard(const std::vector<int>& winningNumbers_, const std::vector<int>& drawnNumbers_)
{
    int total = 0;

    std::cout << "Winning Numbers :";
    for (size_t i = 0; i < winningNumbers_.size(); i++)
    {
        std::cout << winningNumbers_[i] << " ";
    }

    std::cout << std::endl;

    std::cout << "Drawn Numbers :";
    for (size_t i = 0; i < drawnNumbers_.size(); i++)
    {
        std::cout << drawnNumbers_[i] << " ";
    }

    std::cout << std::endl;

    return total;
}

int DayFour::ReadFile(const std::string& filename_)
{
    // Open the file
    std::ifstream file(filename_);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename_);
    }

    // Build the vector of data first
    std::vector<int> winNums, drawnNums;
    std::string line;
    int total = 0;
    while (std::getline(file, line)) {
        // Skip empty lines
        if (!line.empty()) {
            // Remove 'Card #:' from the string
            size_t pos = line.find(":");
            line.erase(0, pos + 1);

            // Split string into winning and drawn based on '|'
            pos = line.find("|");
            std::string winStr = line.substr(0, pos);
            std::string drawnStr = line.substr(pos + 1, line.length());
            
            // Parse winning numbers string
            std::stringstream issW(winStr);
            int num;
            while (issW >> num)
            {
                winNums.push_back(num);
            }

            // Parse drawn numbers string
            std::stringstream issD(drawnStr);
            while (issD >> num)
            {
                drawnNums.push_back(num);
            }

            // Read card values and return card score
            total += ReadCard(winNums, drawnNums);
        }

        // Clear the vectors ahead of the next line
        winNums.clear();
        drawnNums.clear();
    }

    // Close the file
    file.close();

    // Return the final value
    return total;
}

void DayFour::Main()
{
    std::cout << "Day 4 Challenge started.." << std::endl;

    try {
        std::string filename = "TestInput/DayFourTestInput.txt";
        int total = ReadFile(filename);
        std::cout << "Sum of numerical values in engine schematic is: " << total << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "Day 3 Challenge finished.." << std::endl;
}