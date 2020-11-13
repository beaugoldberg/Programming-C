myprog.exe : main.o Card.o Deck.o Blackjack.o
	g++ main.o Card.o Deck.o Blackjack.o -o myprog.exe

main.o : main.cpp Blackjack.h
	g++ -Wall -c main.cpp

Blackjack.o : Blackjack.cpp Deck.h
	g++ -Wall -c Blackjack.cpp

Deck.o : Deck.cpp Deck.h
	g++ -Wall -c Deck.cpp

Card.o : Card.cpp Card.h
	g++ -Wall -c Card.cpp

clean: 
	rm *.o myprog.exe 
	ls