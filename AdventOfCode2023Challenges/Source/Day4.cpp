#include "../Include/Day4.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>

int DayFour::FindPairs(const std::vector<int>& winningNumbers_, const std::vector<int>& drawnNumbers_)
{
    int numPairs = 0;

    // Loop through all drawn numbers to search for them in the winning pile
    for (size_t i = 0; i < drawnNumbers_.size(); i++)
    {
        if (std::find(winningNumbers_.begin(), winningNumbers_.end(), drawnNumbers_[i]) != winningNumbers_.end())
        {
            numPairs++;
        }
    }

    return numPairs;
}

int DayFour::ReadFile(const std::string& filename_)
{
    // Open the file
    std::ifstream file(filename_);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename_);
    }

    // Build the vector of data first
    std::vector<std::vector<int>> winNums, drawnNums;
    std::string line;
    int total, cardNum;
    total = cardNum = 0;
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

            // Rescale the vectors
            winNums.resize(winNums.size() + 1);
            drawnNums.resize(drawnNums.size() + 1);
            
            // Parse winning numbers string
            std::stringstream issW(winStr);
            int num;
            while (issW >> num)
            {
                winNums[cardNum].push_back(num);
            }

            // Parse drawn numbers string
            std::stringstream issD(drawnStr);
            while (issD >> num)
            {
                drawnNums[cardNum].push_back(num);
            }

            cardNum++;
        }
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
        std::cout << "Total score for all the cards: " << total << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "Day 3 Challenge finished.." << std::endl;
}