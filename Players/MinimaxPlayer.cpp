#include <limits>

#include "MinimaxPlayer.h"

MinimaxPlayer::MinimaxPlayer(uint8_t player)
	: _player(player),
	_playerWeight{ 1, -1 }
{
}

Move MinimaxPlayer::getMove(GameState& gameState)
{
	constexpr float max = std::numeric_limits<float>::max();
	std::pair<Move, float> val = _minimax(gameState, 10, _player, -1 * max, max);
	return val.first;
}

std::pair<Move, float> MinimaxPlayer::_minimax(GameState& gameState, uint8_t depth, uint8_t turn, float alpha, float beta)
{
	if (depth == 0 || gameState.isGameOver())
		return std::make_pair(Move{ 0, (TYPE)0, 0, 0 }, _heuristic(gameState, turn));

	GameState tempState;
	if (turn == 0)
	{
		float bestValue = -1 * std::numeric_limits<float>::max();
		Move bestMove = { 0, (TYPE)0, 0, 0 };
		for (Move& move : gameState.getPossibleMoves(turn))
		{
			tempState.readFrom(gameState);
			tempState.makeMove(move);

			std::pair<Move, float> val = _minimax(tempState, depth - 1, 1 - turn, alpha, beta);

			if (val.second > bestValue)
			{
				bestValue = val.second;
				bestMove = move;
			}

			alpha = std::max(alpha, bestValue);
			if (alpha >= beta)
				break;
		}
		return std::make_pair(bestMove, bestValue);
	}
	else
	{
		float bestValue = std::numeric_limits<float>::max();
		Move bestMove = { 0, (TYPE)0, 0, 0 };
		for (Move& move : gameState.getPossibleMoves(turn))
		{
			tempState.readFrom(gameState);
			tempState.makeMove(move);

			std::pair<Move, float> val = _minimax(tempState, depth - 1, 1 - turn, alpha, beta);

			if (val.second < bestValue)
			{
				bestValue = val.second;
				bestMove = move;
			}

			beta = std::min(beta, bestValue);
			if (alpha >= beta)
				break;
		}
		return std::make_pair(bestMove, bestValue);
	}
}

/**
* Return numeric evaluation of the board state.
*
* Positive values favor player 0, negative values
* favor player 1.
*/
float MinimaxPlayer::_heuristic(GameState& gameState, uint8_t turn)
{
	// first check for winners
	if (gameState.getWinner() == 0)
		return std::numeric_limits<float>::max() - 1;
	if (gameState.getWinner() == 1)
		return -1 * std::numeric_limits<float>::max() + 1;

	float heuristic = 0;
	uint8_t hands[2][2] = {
		{gameState.getHand(0, 0), gameState.getHand(0, 1)},
		{gameState.getHand(1, 0), gameState.getHand(1, 1)} };

	// each non-zero hand is a positive
	for (uint8_t player = 0; player < 2; player++)
	{
		for (uint8_t hand = 0; hand < 2; hand++)
		{
			if (hands[player][hand] != 0)
			{
				heuristic += 10 * _playerWeight[player];
			}
			// it's advantageous if the current player can eliminate an opponent's hand
			if (player == turn)
			{
				if (hands[player][hand] == 5 - hands[1 - player][0] || hands[player][hand] == 5 - hands[1 - player][1])
				{
					heuristic += 30 * _playerWeight[player];
				}
			}
		}
	}
	return heuristic;
}