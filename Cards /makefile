#Trisha Andres
#CPSC 1071: Section 2
#Group B6: C--
#03/11/2023

compile:
	#g++ Card.o DeckOfCards.o Driver.cpp -std=c++98 -Wall -o CardDealer.out
	g++ Card.h Card.cpp -std=c++98 -Wall  -c
	g++ DeckOfCards.h DeckOfCards.cpp -std=c++98 -Wall -c       
	g++ Card.o DeckOfCards.o Driver.cpp -std=c++98 -Wall -o CardDealer.out 
card:
	g++ -std=c++98 -Wall Card.h Card.cpp -c

deck:
	g++ -std=c++98 -Wall DeckOfCards.h DeckOfCards.cpp -c

run:
	./CardDealer.out

clean: 
	rm *.out
no:
	rm *.o
