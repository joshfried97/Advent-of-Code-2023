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

	/// @brief Using a hash map to store the game values as this can scale in runtime
	/// Each element is ID, [maxRed, maxGreen, maxBlue]
	//std::unordered_map<int, int[3]> cubesPerGame;
}
