CXX = clang++
CXXFLAGS = --std=c++11 -g -Wall -Wextra -pedantic

SEVEN_WONDERS_OBJECTS = 7wonders.o AllCards.o Card.o CardType.o Deck.o Game.o Player.o Produce.o Pay.o

TARGETS = 7wonders
OBJECTS = $(SEVEN_WONDERS_OBJECTS)

all: $(TARGETS);

clean:
	rm -f $(TARGETS) $(OBJECTS)

7wonders: $(SEVEN_WONDERS_OBJECTS)
	$(CXX) $(SEVEN_WONDERS_OBJECTS) -o 7wonders

# compiler generated rules

7wonders.o: 7wonders.cpp Game.h Card.h Player.h Produce.h Color.h Pay.h
AllCards.o: AllCards.cpp AllCards.h CardType.h Card.h Player.h Produce.h \
 Color.h Pay.h
Card.o: Card.cpp Card.h Player.h Produce.h Color.h Pay.h
CardType.o: CardType.cpp CardType.h Card.h Player.h Produce.h Color.h \
 Pay.h
Deck.o: Deck.cpp Deck.h Card.h Player.h Produce.h Color.h Pay.h \
 CardType.h AllCards.h
Game.o: Game.cpp Game.h Card.h Player.h Produce.h Color.h Pay.h Deck.h \
 CardType.h
Pay.o: Pay.cpp Pay.h
Player.o: Player.cpp Player.h Card.h Produce.h Color.h Pay.h \
 infix_iterator.h
Produce.o: Produce.cpp Produce.h
