//Trisha Andres                                                     
//CPSC 1070: Section 2                                                  
//Group B6: C --                                                            
//03/11/2023 

#include "DeckOfCards.h"
#include "Card.h"

#include <iostream>
#include <ctime>

int main(void) {

  srand(time(0)); //for random number generator for shuffling cards
  
  Card firstCard(1, 1); //gets card at face 1, suit 1
  cout << firstCard.toString() << endl; //should output Ace of Hearts

  Card secondCard(2, 1); //gets card at face 2, suit 2
  cout << secondCard.toString() << endl; //should output Deuce of Hearts

  DeckOfCards deck; //generates ordered deck of cards (52 cards) 

  if (deck.moreCards()) //if there are more coods output statement 
    {
      cout<< "more cards good\n";
    }

  Card card1 = deck.dealCard(); //should return Ace of Hearts
  cout<< card1.toString() << endl; //should output above

  Card card2 = deck.dealCard(); //should return Deuce of Hearts 
  cout<< card2.toString() << endl; //should output above

  Card card3 = deck.dealCard(); //should return Three of Hearts
  cout<< card3.toString() << endl; //should output above

  deck.shuffle();//shuffles deck of cards

  Card cardShuffle = deck.dealCard(); //should return a random card
  cout<< cardShuffle.toString() << endl; //should print above

  deck.shuffle();//shuffle deck again
  
  Card shuffle2 = deck.dealCard();//should return new random card
  cout<< cardShuffle.toString() << endl; //should output above
  
  return 0;
}
