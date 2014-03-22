CXX = clang++
CXXFLAGS = --std=c++11 -g

SEVEN_WONDERS_OBJECTS = 7wonders.o AllCards.o Card.o CardType.o Deck.o Game.o Player.o Produce.o
TARGETS = 7wonders
OBJECTS = $(SEVEN_WONDERS_OBJECTS)

all: $(TARGETS);

clean:
	rm -f $(TARGETS) $(OBJECTS)

7wonders: $(SEVEN_WONDERS_OBJECTS)
	$(CXX) $(SEVEN_WONDERS_OBJECTS) -o 7wonders
#
#7wonders.o: 7wonders.cpp Game.h Game.o
#
#Game.o: Game.cpp Game.h Player.h Produce.h Deck.h
#
#Produce.o: Produce.cpp Produce.h
#
#Player.o: Player.cpp Player.h Card.h Produce.h
#
#Deck.o: Deck.cpp Deck.h Card.h AllCards.h
#
#Card.o: Card.cpp Card.h Player.h Produce.h Pay.h
#
#AllCards.o: AllCards.h Card.h

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
Player.o: Player.cpp Player.h Card.h Produce.h Color.h Pay.h
Produce.o: Produce.cpp Produce.h
