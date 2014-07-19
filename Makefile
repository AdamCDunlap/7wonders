CXX = clang++
CXXFLAGS = --std=c++11 -g -Wall -Wextra -pedantic

SEVEN_WONDERS_OBJECTS = 7wonders.o AllCards.o AllWonders.o Card.o CardType.o Deck.o Game.o Player.o Produce.o Pay.o

TARGETS = 7wonders
OBJECTS = $(SEVEN_WONDERS_OBJECTS)

all: $(TARGETS);

clean:
	rm -f $(TARGETS) $(OBJECTS)

7wonders: $(SEVEN_WONDERS_OBJECTS)
	$(CXX) $(SEVEN_WONDERS_OBJECTS) -o 7wonders

# compiler generated rules
7wonders.o: 7wonders.cpp Game.hpp Card.hpp Produce.hpp Color.hpp Pay.hpp \
 Player.hpp Wonder.hpp AllWonders.hpp optionparser.hpp Utility.hpp \
 Utility-private.hpp
AllCards.o: AllCards.cpp AllCards.hpp CardType.hpp Card.hpp Produce.hpp \
 Color.hpp Pay.hpp Player.hpp Wonder.hpp Game.hpp AllWonders.hpp
AllWonders.o: AllWonders.cpp AllWonders.hpp Wonder.hpp Produce.hpp \
 Card.hpp Color.hpp Pay.hpp Player.hpp Game.hpp
Card.o: Card.cpp Card.hpp Produce.hpp Color.hpp Pay.hpp Player.hpp \
 Wonder.hpp Game.hpp AllWonders.hpp Utility.hpp Utility-private.hpp
CardType.o: CardType.cpp CardType.hpp Card.hpp Produce.hpp Color.hpp \
 Pay.hpp Player.hpp Wonder.hpp Game.hpp AllWonders.hpp
Deck.o: Deck.cpp Deck.hpp Card.hpp Produce.hpp Color.hpp Pay.hpp \
 CardType.hpp Player.hpp Wonder.hpp Game.hpp AllWonders.hpp AllCards.hpp
Game.o: Game.cpp Game.hpp Card.hpp Produce.hpp Color.hpp Pay.hpp \
 Player.hpp Wonder.hpp AllWonders.hpp Deck.hpp CardType.hpp Utility.hpp \
 Utility-private.hpp
Pay.o: Pay.cpp Pay.hpp
Player.o: Player.cpp Player.hpp Card.hpp Produce.hpp Color.hpp Pay.hpp \
 Wonder.hpp Game.hpp AllWonders.hpp infix_iterator.hpp Utility.hpp \
 Utility-private.hpp
Produce.o: Produce.cpp Produce.hpp
