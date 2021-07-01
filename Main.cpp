#include "Game.h"
#include "HumanPlayer.h"

int main()
{
	Game game(new HumanPlayer(0), new HumanPlayer(1));
	game.runGameLoop();

	return 0;
}