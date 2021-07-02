#include "Game.h"
#include "HumanPlayer.h"
#include "MinimaxPlayer.h"

int main()
{
	Game game(new HumanPlayer(0), new MinimaxPlayer(1));
	game.runGameLoop();

	return 0;
}