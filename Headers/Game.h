#ifndef GAME_H
#define GAME_H

#include <stdint.h>

#include "Player.h"
#include "GameState.h"

class Game
{
public:
	/**
	* Create a new game with the given players.
	*/
	Game(Player* p0, Player* p1);

	/**
	* Initiate the game loop.
	*/
	void runGameLoop();

private:
	/**
	* Turn indicator.
	*/
	uint8_t _turn;
	/**
	* Array of players.
	*/
	Player* _players[2];
	/**
	* Stored game state.
	*/
	GameState _gameState;

	/**
	* Return a human-readable string describing the given move.
	*/
	std::string _interpretMove(Move& move);

	/**
	* Display the hands' current finger values.
	*/
	void _displayHands();
};

#endif
