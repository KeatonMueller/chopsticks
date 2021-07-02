#include <iostream>
#include <string>
#include "Game.h"

Game::Game(Player* p0, Player* p1)
	: _turn(0),
	_players{ p0, p1 },
	_gameState()
{
}

std::string interpretMove(Move& move)
{
	std::string str = "Player " + std::to_string((int)move.player);
	if (move.type == TYPE::ATTACK)
		str += " attack from " + std::to_string((int)move.hand0) + " to " + std::to_string((int)move.hand1);
	else
		str += " redistribute to " + std::to_string((int)move.hand1) + " and " + std::to_string((int)move.hand0);
	return str;
}

void Game::runGameLoop()
{
	Move move;
	// until game is over
	while (!_gameState.isGameOver())
	{
		// make a move
		move = _players[_turn]->getMove(_gameState);
		std::cout << "Selected move: " << interpretMove(move) << std::endl;
		_gameState.makeMove(move);

		// update turn indicator
		_turn = 1 - _turn;
	}
	std::cout << "Game Over!" << std::endl;
}
