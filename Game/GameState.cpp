#include "GameState.h"

GameState::GameState()
{
	// initialize _handAmounts
	for (uint8_t hand = 0; hand < 2; hand++)
		for (uint8_t finger = 0; finger < 5; finger++)
			_handAmounts[hand][finger] = finger << (hand * 4);

	// initialize hand masks
	_handMasks[0] = 0x0f;
	_handMasks[1] = 0xf0;

	// set both players hands to both be 1
	_hands[0] = _handAmounts[0][1] | _handAmounts[1][1];
	_hands[1] = _handAmounts[0][1] | _handAmounts[1][1];
}

uint8_t GameState::getHands(uint8_t player)
{
	return _hands[player];
}

uint8_t GameState::getHand(uint8_t player, uint8_t hand)
{
	return (getHands(player) & _handMasks[hand]) >> (hand * 4);
}

/**
* Check if the game is in a terminal state.
*/
bool GameState::isGameOver()
{
	// game is over if either player's hands are both 0
	return getHands(0) == 0 || getHands(1) == 0;
}

/**
* Execute the given move.
*
* The move is assumed to be legal.
*/
void GameState::makeMove(Move move)
{
	if (move.type == TYPE::ATTACK)
	{
		// increase opponent's hand by player's hand mod 5
		uint8_t srcHand = getHand(move.player, move.hand0);
		uint8_t dstHand = getHand(1 - move.player, move.hand1);
		_setHand(1 - move.player, move.hand1, (srcHand + dstHand) % 5);
	}
	else if (move.type == TYPE::REDISTRIBUTE)
	{
		// update player's hand values
		_setHand(move.player, 0, move.hand0);
		_setHand(move.player, 1, move.hand1);
	}
}


void GameState::_setHand(uint8_t player, uint8_t hand, uint8_t amount)
{
	// empty out the old hand value
	_hands[player] &= ~_handMasks[hand];
	// set new value
	_hands[player] |= _handAmounts[hand][amount];
}
