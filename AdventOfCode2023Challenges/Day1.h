#pragma once

#include <string>
#include <vector>

namespace DayOne
{
	int WordToNumber(const std::string& word_);

	std::vector<int> ExtractNumbers(const std::string& input_);

	std::vector<int> ExtractNumbers(const std::string& line_);

	int ConstructNumber(const std::string& line_);

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
