//Trisha Andres                                                                
//CPSC 1070: Section 2                                                         
//Group B6: C --                                                               
//03/11/2023   


#ifndef DECKOFCARD_H
#define DECKOFCARDS_H

#include "Card.h"

#include <iostream>
#include <vector>
#include <cstdlib>

class DeckOfCards {
 public:
  DeckOfCards();
  
  //void startCard();
  void shuffle();

  Card dealCard();

  bool moreCards();

 private:
  vector <Card> deck;
  int currentCard;
};

#endif
