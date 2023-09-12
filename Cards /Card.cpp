//Trisha Andres                                                             
//CPSC 1070: Section 2                                                    
//Group B6: C --                                                          
//03/11/2023 


#include <iostream>
#include <string>
#include <iomanip>

#include "Card.h"

using namespace std;

//initializing arrays for faces and suits 
string Card::face[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
string Card::suit[] = {"Hearts", "Diamonds", "Clubs", "Spades"};

//initializes data members
Card::Card(int faceVar, int suitVar){
  --faceVar; 
  --suitVar;

  //validates range for face of card
  if ((faceVar > -1) && (faceVar < 13))
    {
      thisFaceCard = static_cast<Face>(faceVar);
    }
  else
    {
      cout<< "INVALID\n";
    }
  //validates range for suit of card
  if ((suitVar > -1) && (suitVar < 4))
    {
      thisSuitCard = static_cast<Suit>(suitVar);
    }
  else
    {
      cout<< "INVALID\n";
    }
}

string Card::toString() {
  //makes card to string (with arrays and the enums)
  faceOfCard = face[thisFaceCard];
  suitOfCard = suit[thisSuitCard];

  //returns string "face of suit"
  return faceOfCard + " of " + suitOfCard;
}
