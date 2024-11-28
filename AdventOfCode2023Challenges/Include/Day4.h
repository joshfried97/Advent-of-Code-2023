#pragma once

#include <string>
#include <vector>

namespace DayFour
{
	int FindPairs(const std::vector<int>& winningNumbers_, const std::vector<int>& drawnNumbers_);

	/// <summary>
	/// Takes the filename and reads line by line
	/// </summary>
	/// <param name="filename"> Filename to read </param>
	/// <returns> Total for the sum of the values</returns>
	int ReadFile(const std::string& filename_);

	/// <summary>
	/// Main function
	/// </summary>
	void Main();
}
