#include "../Include/Day3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int DayThree::FindAdjSymbol(const std::vector<std::vector<char>>& schContents_)
{
    int digitCtr = 0;
    for (int i = 0; i < schContents_.size(); i++)
    {
        int num = 0;
        for (int j = 0; j < schContents_[i].size(); j++)
        {
            const char c = schContents_[i][j];
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else
            {
                if (num > 0)
                {
                    std::cout << num << std::endl;
                }
                num = 0;
            }
        }
    }

    return 0;
}

int DayThree::ReadFile(const std::string& filename_)
{
    // Open the file
    std::ifstream file(filename_);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename_);
    }

    // Build the vector of data first
    std::vector<std::vector<char>> schematicContents;
    std::string line;
    int itr = 0;
    while (std::getline(file, line)) {
        // Skip empty lines
        if (!line.empty()) {
            // Add new row to vector
            schematicContents.resize(schematicContents.size() + 1);

            // Add column entries to the new row as we know the line length and populate
            schematicContents[itr].resize(line.size());

            for (char c : line) {
                schematicContents[itr].push_back(c);
            }
            
        }
        itr++;
    }

    // Close the file
    file.close();

    int total = FindAdjSymbol(schematicContents);

    // Return the final value
    return total;
}

void DayThree::Main()
{
    std::cout << "Day 3 Challenge started.." << std::endl;

    try {
        std::string filename = "TestInput/DayThreeTestInput.txt";
        int total = ReadFile(filename);
        std::cout << "Sum of numerical values in engine schematic is: " << total << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "Day 3 Challenge finished.." << std::endl;
}