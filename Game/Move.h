#ifndef MOVE_H
#define MOVE_H

#include <stdint.h>

/**
* Types of moves in chopsticks.
*
* Attacking moves are when you touch another player's hand with your own.
* Redistributing moves are when you redistribute your fingers across
* your hands.
*/
enum class TYPE : uint8_t { ATTACK, REDISTRIBUTE };

/**
* Struct storing a single move.
*
* player stores the index of what player is making the move.
*
* type stores whether it's an attacking or redistributing move.
*
* If type == ATTACK:
*		hand0 stores the index of your own hand to attack with
*		hand1 stores the index of your opponent's hand to be attacked
* If type == REDISTRIBUTE:
*		hand0 stores the value for the right hand
*		hand1 stores the value for the left hand
*/
struct Move
{
	uint8_t player;
	TYPE type;
	uint8_t hand0;
	uint8_t hand1;
};


#endif
