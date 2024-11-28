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
    std::vector<int> winNums, drawnNums, scoresPerCard;
    std::string line;
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

            // Build the scores per card look up table
            scoresPerCard.push_back(FindPairs(winNums, drawnNums));
        }
        winNums.clear();
        drawnNums.clear();
    }

    // Close the file
    file.close();

    int scoreCardNum, itr, tempCardNum, tempPairNum;
    scoreCardNum = itr = tempCardNum = tempPairNum = 0;
    std::vector<int> cardBuffer;

    // Initially fill buffer
    std::cout << "Round 1:" << std::endl;
    for (size_t i = 1; i <= scoresPerCard.size(); i++)
    {
        // Add original cards
        cardBuffer.push_back(i);
        std::cout << i << ": ";

        // Find the score for these original cards
        tempPairNum = scoresPerCard[i-1];
        if (!tempPairNum)
        {
            std::cout << std::endl;
            continue;
        }

        for (size_t j = 1; j <= tempPairNum; j++)
        {
            // Add first layer of card results
            cardBuffer.push_back(i + j);
            std::cout << i + j << " ";
        }
        std::cout << std::endl;
    }

    // Now continue to fill the buffer with the subsequent card results
    for (size_t i = scoresPerCard.size(); i < cardBuffer.size(); i++)
    {
        tempCardNum = cardBuffer[i];
        tempPairNum = scoresPerCard[tempCardNum];

        if (!tempPairNum)
        {
            continue;
        }

        for (size_t j = 1; j <= tempPairNum; j++)
        {
            std::cout << i << " " << j;
            cardBuffer.push_back(cardBuffer[i] + j);
        }
        std::cout << std::endl;
    }

    // Return the final value
    return cardBuffer.size();
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