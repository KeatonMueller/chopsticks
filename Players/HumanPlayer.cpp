#include <iostream>
#include <string>
#include <algorithm>

#include "HumanPlayer.h"
#include "Util.h"

HumanPlayer::HumanPlayer(uint8_t player)
	: _player(player)
{
}

Move HumanPlayer::getMove(GameState& gameState)
{
	Move move = { _player, (TYPE)0, 0, 0 };

	uint8_t input = getInput("Do you want to [1] Attack, or [2] Redistribute? ", 1, 2);

	if (input == 1)
	{
		move.type = TYPE::ATTACK;
		input = 3;
		while (input == 3 || gameState.getHand(_player, input % 2) == 0)
			input = getInput("Attack with hand [1] or hand [2]? ", 1, 2);
		move.hand0 = input % 2;

		input = 3;
		while (input == 3 || gameState.getHand(1 - _player, input % 2) == 0)
			input = getInput("Attack opponent's hand [1] or hand [2]? ", 1, 2);
		move.hand1 = input % 2;
	}
	else if (input == 2)
	{
		move.type = TYPE::REDISTRIBUTE;

		input = gameState.getHand(_player, 0);
		while (!gameState.canRedistribute(_player, input))
			input = getInput("Enter new value for left hand: ", 0, 4);

		uint8_t newRight = gameState.getHand(_player, 0) + gameState.getHand(_player, 1) - input;
		move.hand0 = newRight;
		move.hand1 = input;
	}
	return move;
}
