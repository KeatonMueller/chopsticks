#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#include "Player.h"
#include "GameState.h"

class Game
{
public:
	Game(Player* p0, Player* p1);

private:
	uint8_t _turn;
	Player* _players[2];

	GameState _gameState;

	void _runGameLoop();
};

#endif
