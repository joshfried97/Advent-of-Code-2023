#include "../Include/Day4.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

bool DayFour::SymbolNeigh(const std::vector<std::vector<char>>& schContents_, const int startRow_, const int startCol_, const int digitLen_,
    const int rowNum_)
{
    for (int i = startRow_ - 1; i <= startRow_ + 1; i++)
    {
        if (i < 0 || i > rowNum_ - 1)
        {
            // Skip this row if it lies outside structure size
            continue;
        }

        for (int j = startCol_ - 1; j <= startCol_ + digitLen_ + 1; j++)
        {
            int rowLen = schContents_[i].size();
            if (j < 0 || j > rowLen - 1)
            {
                // Skip this element if it lies outside structure size
                continue;
            }

            char query = schContents_[i][j];
            if (!isdigit(query) && query != '.')
            {
                return true;
            }
        }
    }

    return false;
}

int DayFour::FindAdjSymbol(const std::vector<std::vector<char>>& schContents_)
{
    int digitCtr, total, startR, startC;
    digitCtr = total = startR = startC = 0;
    for (int i = 0; i < schContents_.size(); i++)
    {
        int num = 0;
        for (int j = 0; j < schContents_[i].size(); j++)
        {
            const char c = schContents_[i][j];
            if (isdigit(c))
            {
                // Store coords of first digit
                if (!digitCtr)
                {
                    startR = i;
                    startC = j;
                }

                // Build the number as we find new digits
                num = num * 10 + (c - '0');
                digitCtr++;
            }
            else
            {
                // At this point we have found the symbol after the last digit so have the full number
                if (num > 0)
                {
                    if (SymbolNeigh(schContents_, startR, startC, digitCtr, schContents_[i].size()))
                    {
                        total += num;
                    }
                    else
                    {
                        std::cout << num << std::endl;
                    }
                }

                // Reset values ahead of the next incoming number
                num = 0;
                digitCtr = 0;
            }
        }
    }

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

    // Remove leading 10 null characters - ** Might not be needed for test case
    for (size_t i = 0; i < schematicContents.size(); i++)
    {
        schematicContents[i].erase(schematicContents[i].begin(), schematicContents[i].begin() + 10);
    }

    // Close the file
    file.close();

    int total = FindAdjSymbol(schematicContents);

    // Return the final value
    return total;
}

void DayFour::Main()
{
    std::cout << "Day 4 Challenge started.." << std::endl;

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