#include <algorithm>

#include "GameState.h"

GameState::GameState()
	: _handMasks{0x0f, 0xf0}
{
	// initialize _handAmounts
	for (uint8_t hand = 0; hand < 2; hand++)
		for (uint8_t finger = 0; finger < 5; finger++)
			_handAmounts[hand][finger] = finger << (hand * 4);

	// set both players hands to both be 1
	_hands[0] = _handAmounts[0][1] | _handAmounts[1][1];
	_hands[1] = _handAmounts[0][1] | _handAmounts[1][1];
}

void GameState::readFrom(GameState &gameState)
{
	_hands[0] = gameState._hands[0];
	_hands[1] = gameState._hands[1];
}

/**
* Get the value of the given hand for the given player.
*/
uint8_t GameState::getHand(uint8_t player, uint8_t hand)
{
	return (_hands[player] & _handMasks[hand]) >> (hand * 4);
}

/**
* Generate all legal moves for the given player
* based on the current board state.
*/
std::vector<Move> GameState::getPossibleMoves(uint8_t player)
{
	std::vector<Move> moves;

	// get player's hands
	uint8_t hands[2] = {getHand(player, 0), getHand(player, 1)};

	// generate all legal attacking moves
	for (uint8_t myIdx = 0; myIdx < 2; myIdx++)
	{
		// can't attack with a hand of zero
		if (hands[myIdx] == 0)
			continue;

		for (uint8_t oppIdx = 0; oppIdx < 2; oppIdx++)
		{
			// can't target a hand of zero
			if (getHand(1 - player, oppIdx) == 0)
				continue;

			moves.push_back({player, TYPE::ATTACK, myIdx, oppIdx});
		}
	}

	// generate all legal redistributing moves
	uint8_t handsSum = hands[0] + hands[1];
	if (1 < handsSum && handsSum < 7)
		for (uint8_t newRight = 0; newRight <= std::min((uint8_t)4, handsSum); newRight++)
			if (newRight != hands[0] && newRight != hands[1])
				moves.push_back({player, TYPE::REDISTRIBUTE, newRight, (uint8_t)(handsSum - newRight)});

	return moves;
}

bool GameState::canRedistribute(uint8_t player)
{
	uint8_t handsSum = getHand(player, 0) + getHand(player, 1);
	// can't redistribute if finger total is 1, 7, or 8
	return handsSum != 1 && handsSum < 7;
}
bool GameState::canRedistribute(uint8_t player, uint8_t newLeft)
{
	// you cannot pick an existing value
	uint8_t rightHand = getHand(player, 0);
	uint8_t leftHand = getHand(player, 1);
	if (newLeft == rightHand || newLeft == leftHand)
		return false;
	// you cannot allot more fingers than your total
	if (newLeft > rightHand + leftHand)
		return false;
	// redistribution is valid
	return true;
}

/**
* Check if the game is in a terminal state.
*/
bool GameState::isGameOver()
{
	// game is over if either player's hands are both 0
	return _hands[0] == 0 || _hands[1] == 0;
}

/**
* Get the winner (0 or 1) of the game.
* 
* If no winner, return 2.
*/
uint8_t GameState::getWinner()
{
	if (_hands[0] == 0)
		return 1;
	if (_hands[1] == 0)
		return 0;
	return 2;
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
