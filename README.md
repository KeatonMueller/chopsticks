# chopsticks

This is a basic AI to play the game chopsticks, because my friend asked me to make it.

The true purpose is to try making ascii art.

## Rules

This game exists in many varities in many different places.

Therefore this program simply follows the rules that I grew up with.

Basic gameplay aside, here are the rules of interest:

- Redistributing fingers *must* yield a unique combination. In other words, 2 and 3 cannot be redistributed to 3 and 2 -- they are the same.

- You may not attack an opponent's hand that has zero fingers.

- You *may* redistribute all of your fingers onto one hand. In other words, 2 and 2 *may* be redistributed to 4 and 0.

- You may *not* redistribute to a total of 5, eliminating your own hand. In other words, 4 and 2 may *not* redistribute to 5 (=0) and 1.

## How it Works

This program's AI uses the basic minimax algorithm optimized with alpha beta pruning.

Because of the very small branching factor in chopsticks, minimax is able to search to a significant depth.
