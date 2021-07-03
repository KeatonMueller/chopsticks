#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <stdint.h>

/**
* Attempt to parse the given input string to an integer.
*/
bool attemptParse(std::string& input, uint8_t& output);

/**
* Repeatedly issue prompt until an integer falling within the given
* range (inclusive) is entered.
*/
uint8_t getInput(const std::string& prompt, uint8_t min, uint8_t max);
#endif
