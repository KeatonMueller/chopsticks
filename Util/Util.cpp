#include <stdexcept>

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