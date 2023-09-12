//Trisha Andres                                                       
//CPSC 1070: Section 2                                                    
//Group B6: C --                                                          
//03/11/2023

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

using namespace std;

class Card {
 public:
  Card(int,int);
  string toString();

  static string face[];
  static string suit[];

 private:
  enum Face{ACE = 1, DEUCE, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
  enum Suit{HEARTS = 1, DIAMONDS, CLUBS, SPADES};

  Face thisFaceCard;
  Suit thisSuitCard;
  
  string faceOfCard;
  string suitOfCard;
};

#endif
