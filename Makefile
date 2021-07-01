CC=g++
OBJ=Main.o Util.o Game.o GameState.o HumanPlayer.o
HEADER=Headers/Game.h Headers/GameState.h Headers/HumanPlayer.h Headers/Move.h Headers/Player.h Headers/Util.h Headers/Move.h
CFLAGS=-std=c++14 -c -Wall -O3 -IHeaders

all: chopsticks

chopsticks: $(OBJ)
	$(CC) $(OBJ) -o $@

Main.o: Main.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

Game.o: Game/Game.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

GameState.o: Game/GameState.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

HumanPlayer.o: Players/HumanPlayer.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

Util.o: Util/Util.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@