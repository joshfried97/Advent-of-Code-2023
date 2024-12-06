#pragma once

#include <string>
#include <vector>

namespace DayThree
{
	// PART 1 FUNCTIONS

	bool SymbolNeigh(const std::vector<std::vector<char>>& schContents_, 
		const int startRow_, const int startCol_, const int digitLen_, const int rowNum_);
	
	int FindAdjSymbol(const std::vector<std::vector<char>> &schContents_);

	// PART 2 FUNCTIONS



	/// <summary>
	/// Takes the filename and reads line by line
	/// </summary>
	/// <param name="filename"> Filename to read </param>
	/// <returns> Total for the sum of the values in the list of strings</returns>
	int ReadFile(const std::string& filename_);

	/// <summary>
	/// Main function
	/// </summary>
	void Main();
}
