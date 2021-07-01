#ifndef MINIMAX_PLAYER_H
#define MINIMAX_PLAYER_H

#include <stdint.h>
#include "Player.h"

class MinimaxPlayer : public Player
{
public:
	MinimaxPlayer(uint8_t player);
	Move getMove(GameState& gameState);

private:
	uint8_t _player;
};

#endif
