#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <string>
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(uint8_t player);
	Move getMove(GameState& gameState);

private:
	uint8_t _player;

	uint8_t _getInput(const std::string& prompt, uint8_t min, uint8_t max);
};

#endif
