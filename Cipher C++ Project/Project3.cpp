/*Trisha Andres                                                                
CPSC 1070: Section 2                                                      
04/9/23                                                               
B6: C--*/
#include "Cipher.h"
#include "Queue.h"

#include <iostream>

using namespace std;

int main(void) {
  /*  Queue qYuh;

  cout << "ENQUUQUQ" << endl;
  
  for (int i = 0; i < 5; i ++)
    {
      qYuh.enqueue(i * i);
    }

  cout<< "values in queue were: \n";
  while(!qYuh.isEmpty())
    {
      int val;
      qYuh.dequeue(val);
      cout<< val << " ";
      
    }
    THIS WAS TO HELP DEBUG
    cout << endl;*/
  
  //objects for cipher class
  Cipher cipherYuh;

  //encoding for the message
  string inputMessage;
  inputMessage = "Secret Message!";
  cout<< "Key: [1, 2, 3, 4]"<< endl;

  cout<< "Encoding: " << inputMessage << endl;
  //call on encodeMessage() to encode the message
  cout<< "Encoded: ";
  string encoded;
  encoded = cipherYuh.encodeMessage(inputMessage);
  cout<< encoded << endl << endl;

  //call on decodeMessage() to decode the encoded message
  cout<< "Key: [1, 2, 3, 4]"<< endl;
  cout<< "Decoding: " << encoded << endl;
  cout<< "Decoded: ";
  //string yuh;
  //yuh = "tgfvfvpitudkf";
  string decoded;
  decoded = cipherYuh.decodeMessage(encoded);
  cout<< decoded << endl << endl;
  
  return 0;
}

