#ifndef PLAYER_H
#define PLAYER_H

#include <stdint.h>

#include "GameState.h"
#include "Move.h"

class Player
{
public:
	virtual Move getMove(GameState& gameState) = 0;
};

#endif
