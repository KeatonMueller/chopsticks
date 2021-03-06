CC = g++
OBJ = Main.o Util.o Game.o GameState.o HumanPlayer.o MinimaxPlayer.o Art.o
HEADER = Headers/Game.h Headers/GameState.h Headers/HumanPlayer.h Headers/Move.h Headers/Player.h Headers/Util.h Headers/Move.h Headers/MinimaxPlayer.h Headers/Art.h
CFLAGS = -std=c++14 -c -Wall -O3 -IHeaders

ifeq ($(OS),Windows_NT)
	RM = cmd \/C del
	TARGET = chopsticks.exe
else
	RM = rm
	TARGET = chopsticks
endif

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

MinimaxPlayer.o: Players/MinimaxPlayer.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

Util.o: Util/Util.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

Art.o: Game/Art.cpp $(HEADER)
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) *.o $(TARGET)
