//Trisha Andres                                                                          
//CPSC 1070: Section 2                                                                   
//Group B6: C --                                                                         
//03/11/2023  

#include "DeckOfCards.h"
#include <iostream>

using namespace std;

DeckOfCards::DeckOfCards() {
  //creates a vector of card objects with all cards in it 
  currentCard = 0;

  
  for(int i =  4; i > 0; i--)//suits
    {
      for(int b = 13; b > 0; b--)//faces
        {
	  Card card(b,i);
          deck.push_back(card);
          ++currentCard; //in the end will be 52
        }
    }
}

//shuffles vector (deck of cards) by going through and getting random cardsand swapping them with temp
void DeckOfCards::shuffle() {
  
  int randCard = 0;
  Card temp(1,1);
  
  //range to currentCard to accoutn for cards dealt
  for (int c = 0; c < currentCard; c++) {
    randCard = (rand() % currentCard);
    
    temp = deck.at(c);
    deck.at(c) = deck.at(randCard);
    deck.at(randCard) = temp;
    
  }
  temp = deck.at(0);
    
    }

//creates a card to be returned, removes it after it is dealt
Card DeckOfCards::dealCard() {
  
  Card cardThatIsDealt = deck.at(currentCard - 1);
  --currentCard;
  deck.pop_back();

  return cardThatIsDealt;
}

//checks if deck is empty and sets boolean accordingly
bool DeckOfCards::moreCards() {
  bool stillCards;

  if(deck.empty())
    {
      stillCards = false;
    }
  else
    {
      stillCards = true;
    }
  
  return stillCards;
}
