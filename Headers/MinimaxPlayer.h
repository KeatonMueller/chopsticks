#ifndef MINIMAX_PLAYER_H
#define MINIMAX_PLAYER_H

#include <stdint.h>
#include <utility>

#include "Player.h"

class MinimaxPlayer : public Player
{
public:
	MinimaxPlayer(uint8_t player);
	Move getMove(GameState &gameState);

private:
	uint8_t _player;
	int _playerWeight[2];
	float _heuristic(GameState &gameState, uint8_t turn);
	std::pair<Move, float> _minimax(GameState &gameState, uint8_t depth, uint8_t turn, float alpha, float beta);
};

#endif
