#include "Day1.h";

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>

// Function to convert a word-number to its integer equivalent (limited to zero through nine)
int DayOne::WordToNumber(const std::string& word_) {
    static std::map<std::string, int> wordMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };


    std::map<std::string, int>::iterator it;
    for (it = wordMap.begin(); it != wordMap.end(); it++)
    {
        if (word_.find(it->first) != std::string::npos)
        {
            // Once a successful hit has been made then return the numerical value
            return it->second;
        }
    }

    // If nothing found return -1
    return -1;
}

// Helper function to extract single-digit numbers from a string
std::vector<int> DayOne::ExtractNumbers(const std::string& input_) {
    std::vector<int> numbers;
    std::string temp;

    for (size_t i = 0; i < input_.size(); ++i) {
        // Store number
        if (std::isdigit(input_[i]) && input_[i] >= '0' && input_[i] <= '9') {
            numbers.push_back(input_[i] - '0'); // Convert single-digit char to int
            continue;
        }
        else if (std::isalpha(input_[i])) {
            // Build strings char by char
            temp.push_back(input_[i]);
        } 
        
        if (!temp.empty()) {
            // Process the temporary string
            int num = WordToNumber(temp); // Convert word to number
            if (num != -1)
            {
                // Add number to the vector
                numbers.push_back(num);

                // Only clear the built string when a number is found
                temp.clear();
            }
        }
    }

    // Process any leftover string
    if (!temp.empty()) {
        int num = WordToNumber(temp);
        if (num != -1) numbers.push_back(num);
    }

    return numbers;
}

int DayOne::ConstructNumber(const std::string& line_)
{
    std::vector<int> numbers = ExtractNumbers(line_);
    return numbers.front() * 10 + numbers.back();
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
            int val = ConstructNumber(line);

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
	std::cout << "Day 1 Challenge started.." << std::endl;

    try {
        std::string filename = "DayOneTestInput.txt";
        int total = ReadFile(filename);
        std::cout << "Sum of calibration values is: " << total << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    std::cout << "Day 1 Challenge finished.." << std::endl;
}