#include <iostream>
#include <string>

#include "Game.h"
#include "Art.h"

/**
* Initialize a new game.
*/
Game::Game(Player* p0, Player* p1)
	: _turn(0),
	_players{ p0, p1 },
	_gameState()
{
}

/**
* Display the hand values of each player.
*/
void Game::_displayHands()
{
	std::cout << "\n       [1]                          [2]\n\n";
	for (int player = 1; player >= 0; player--)
	{
		uint8_t leftHand = _gameState.getHand(player, 1);
		uint8_t rightHand = _gameState.getHand(player, 0);

		for (uint8_t i = 0; i < 12; i++)
		{

			std::cout << asciiArt[player][1][leftHand][i]
				<< "        "
				<< asciiArt[player][0][rightHand][i]
				<< std::endl;
		}
		if (player == 1)
			std::cout << "\n\n\n";
	}
	std::cout << "\n       [1]                          [2]\n\n";
}

/**
* Return a human-readable string describing the given move.
*/
std::string Game::_interpretMove(Move& move)
{
	std::string str = "Player " + std::to_string((int)move.player + 1);
	if (move.type == TYPE::ATTACK)
	{
		std::string from = move.hand0 == 0 ? "2" : "1";
		std::string to = move.hand1 == 0 ? "2" : "1";
		str += ": attack from " + from + " to " + to;
	}
	else
		str += ": redistribute to " + std::to_string((int)move.hand1) + " and " + std::to_string((int)move.hand0);
	return str;
}

/**
* Initiate the game loop.
*/
void Game::runGameLoop()
{
	Move move;
	// until game is over
	while (!_gameState.isGameOver())
	{
		// show game state
		_displayHands();
		std::cout << "Player " << (_turn + 1) << "'s turn" << std::endl;
		// make a move
		move = _players[_turn]->getMove(_gameState);
		std::cout << "Selected move: " << _interpretMove(move) << std::endl;
		_gameState.makeMove(move);

		// update turn indicator
		_turn = 1 - _turn;
	}
	_displayHands();
	uint8_t winner = _gameState.getWinner();
	std::cout << "Player " << (winner + 1) << " won!" << std::endl;
}
