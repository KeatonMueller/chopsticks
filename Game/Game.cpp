#include <iostream>
#include "Game.h"

Game::Game(Player *p0, Player *p1)
	: _turn(0),
	  _players{p0, p1},
	  _gameState()
{
}

void Game::runGameLoop()
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
