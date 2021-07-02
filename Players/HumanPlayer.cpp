#include <iostream>
#include <string>
#include <algorithm>

#include "HumanPlayer.h"
#include "Util.h"

HumanPlayer::HumanPlayer(uint8_t player)
	: _player(player)
{
}

uint8_t HumanPlayer::_getInput(const std::string& prompt, uint8_t min, uint8_t max)
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

Move HumanPlayer::getMove(GameState& gameState)
{
	Move move = { _player, (TYPE)0, 0, 0 };

	std::cout << "Opponent's hands: " << (int)gameState.getHand(1 - _player, 1)
		<< " " << (int)gameState.getHand(1 - _player, 0) << "\n\n";

	std::cout << "Your hands: " << (int)gameState.getHand(_player, 1)
		<< " " << (int)gameState.getHand(_player, 0) << "\n\n";

	uint8_t input = _getInput("Choose move type:\n\t[1] Attack\n\t[2] Redistribute\n", 1, 2);

	if (input == 1)
	{
		move.type = TYPE::ATTACK;
		input = _getInput("Pick your hand to attack with:\n\t[1] Left\n\t[2] Right\n", 1, 2);
		if (input == 1)
			move.hand0 = 1;
		else if (input == 2)
			move.hand0 = 0;

		input = _getInput("Pick opponent's hand to attack:\n\t[1] Left\n\t[2] Right\n", 1, 2);
		if (input == 1)
			move.hand1 = 1;
		else if (input == 2)
			move.hand1 = 0;
	}
	else if (input == 2)
	{
		move.type = TYPE::REDISTRIBUTE;

		input = gameState.getHand(_player, 0);
		while (!gameState.canRedistribute(_player, input))
			input = _getInput("Enter new value for left hand: ", 0, 4);

		uint8_t newRight = gameState.getHand(_player, 0) + gameState.getHand(_player, 1) - input;
		move.hand0 = newRight;
		move.hand1 = input;
	}
	return move;
}
