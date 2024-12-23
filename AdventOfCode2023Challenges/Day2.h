#pragma once

#include <string>
#include <unordered_map>

namespace DayTwo
{
	int ParseGameInfo(const std::string& line_);

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
