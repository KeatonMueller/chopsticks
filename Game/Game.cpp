#include <iostream>
#include "Game.h"

Game::Game(Player* p0, Player* p1)
	: _gameState()
{
	// start off with it being player 0's turn
	_turn = 0;
	// store the player pointers
	_players[0] = p0;
	_players[1] = p1;

	_runGameLoop();
}

void Game::_runGameLoop()
{
	Move move;
	// until game is over
	while (!_gameState.isGameOver())
	{
		// make a move
		move = _players[_turn]->getMove(_gameState);
		_gameState.makeMove(move);

		// update turn indicator
		_turn = 1 - _turn;
	}
	std::cout << "Game Over!" << std::endl;
}
