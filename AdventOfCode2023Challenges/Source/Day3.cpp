#include "../Include/Day3.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


int DayThree::ReadFile(const std::string& filename_)
{
    // Open the file
    std::ifstream file(filename_);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename_);
    }

    // Read and process each line one at a time
    std::vector<std::vector<char>> schematicContents;
    std::string line;
    int itr = 0;
    int total = 0;
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

    for (int i = 0; i < schematicContents.size(); i++)
    {
        for (int j = 0; j < schematicContents[i].size(); j++)
        {
            std::cout << schematicContents[i][j];
        }
        std::cout << std::endl;
    }

    // Close the file
    file.close();

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