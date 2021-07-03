# chopsticks

This is a basic AI to play the game chopsticks, because my friend asked me to make it.

The true purpose is to try making ascii art (I think I did ok!)

The program is written in C++.

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

## How to Play

If you're on Windows, you can run this program using Visual Studio.

If you're on Mac, you can run the `chopsticks` executable found at the root level of the repository.

When you start the program, you will be prompted to choose if you want each player to be a human or a computer.
Please note that due to the simple nature of this game, two computers playing will just run in an infinite loop, with neither being victorious.
