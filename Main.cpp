#include <iostream>

#include "Util.h"
#include "Game.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "MinimaxPlayer.h"

int main()
{
	// ask user for player types
	uint8_t input = getInput("Is Player 1 a [1] Human, or [2] Computer: ", 1, 2);
	Player* p0 = input == 1 ? (Player*)new HumanPlayer(0) : (Player*)new MinimaxPlayer(0);
	input = getInput("Is Player 2 a [1] Human, or [2] Computer: ", 1, 2);
	Player* p1 = input == 1 ? (Player*) new HumanPlayer(1) : (Player*)new MinimaxPlayer(1);

	Game game(p0, p1);
	game.runGameLoop();

	return 0;
}