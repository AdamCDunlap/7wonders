CXX = clang++
CXXFLAGS = --std=c++11 -g


7wonders: 7wonders.o Game.h Game.o Produce.o Player.o Deck.o Card.o AllCards.o
	$(CXX) 7wonders.o Game.o Produce.o Player.o Deck.o Card.o AllCards.o -o 7wonders

7wonders.o: 7wonders.cpp Game.h Game.o

Game.o: Game.cpp Game.h Player.h Produce.h Deck.h

Produce.o: Produce.cpp Produce.h

Player.o: Player.cpp Player.h Card.h Produce.h

Deck.o: Deck.cpp Deck.h Card.h AllCards.h

Card.o: Card.cpp Card.h Player.h Produce.h Pay.h

AllCards.o: AllCards.h Card.h

clean:
	rm -f 7wonders *.o
