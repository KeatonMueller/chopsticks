#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <stdint.h>

#include "Move.h"

class GameState
{
public:
	GameState();

	uint8_t getHands(uint8_t player);
	uint8_t getHand(uint8_t player, uint8_t hand);

	bool isGameOver();

	void makeMove(Move move);

private:
	uint8_t _hands[2];

	void _setHand(uint8_t player, uint8_t hand, uint8_t value);

	/**
	* Array storing values corresponding to every value a hand can have.
	*
	* _handAmounts[0] stores values for the right hand and _handAmounts[1]
	* stores values for the left hand.
	*
	* _handAmounts[x][n] stores the value for having n fingers on hand x.
	*/
	uint8_t _handAmounts[2][5];

	/**
	* Bit masks to select one hand or the other.
	*
	* _handMasks[0] selects the right hand and _handMasks[1]
	* selects the left hand.
	*/
	uint8_t _handMasks[2];
};

#endif
