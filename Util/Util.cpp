#include <stdexcept>
#include <iostream>

#include "Util.h"

/**
* Attempt to parse the given input string to an integer.
* Return true if successful, else return false.
*/
bool attemptParse(std::string& input, uint8_t& output)
{
	try
	{
		output = std::stoi(input);
	}
	catch (std::invalid_argument const&)
	{
		return false;
	}
	return true;
}

/**
* Repeatedly issue prompt until an integer falling within the given
* range (inclusive) is entered.
*/
uint8_t getInput(const std::string& prompt, uint8_t min, uint8_t max)
{
	std::string input;
	uint8_t output;

	// loop until you return a value
	while (true)
	{
		// loop until a proper integer is input
		while (!attemptParse(input, output))
		{
			std::cout << prompt;
			getline(std::cin, input);
		}
		// ensure integer is within bounds
		if (min <= output && output <= max)
			return output;
		// otherwise attempt parse again
		else
			input = "";
	}
}