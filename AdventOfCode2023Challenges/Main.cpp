// This is my attempt at the Advent of Code 2023 Coding Challenges
#include <iostream>
#include <string>

#include "Day1.h"

using namespace std;

int main()
{
    std::cout << "Welcome to my attempt at Advent of Code 2023 Challenges! \n";

    // Main loop
    int choice;
    do
    {
        string promptStr = "Enter challenge to run between 1-24 (enter -1 to exit): \n";
        std::cout << promptStr;
        while (!(std::cin >> choice) || (choice > -1 && choice < 1 || choice > 24))
        {
            // Enter here if the user entered value incorrect
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::cout << "Invalid input!\n\n" << promptStr;
        }

        // Switch statement calling the different challenges
        // No need for a default case as the input handling is done above
        switch (choice)
        {
        case 1:
            DayOne::Test();
            break;
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
            std::cout << "Your choice was " << choice << '\n';
            break;
        } 

    } while (choice != -1);

    std::cout << "Thank you for running my challenges, exiting the program now.. \n";
}
