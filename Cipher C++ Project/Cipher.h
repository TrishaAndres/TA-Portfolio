/*Trisha Andres                                                     
CPSC 1070: Section 2                                              
04/9/23                                                             
B6: C--*/

#ifndef CIPHER_H
#define CIPHER_H

#include <iostream>
#include <string>

#include "Queue.h"

using namespace std;

class Cipher {
 public:
  int sizeOfCipher;
  
  Cipher(); //defaultConstructor
  void setCipher(int, int[]); //setter for the cipher key
  int* getCipher(); //getter for the cipher key 
  string encodeMessage(string); //function to encode the given message 
  string decodeMessage(string); //function to decode the encoded message

  Queue q;
  
 private:
  int* cipherKey;
  int* cipherKeyPtr;
  string messageToEncode, encodedMessage, decodedMessage;


};
#endif

