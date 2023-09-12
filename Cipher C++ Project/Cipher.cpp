/*Trisha Andres
CPSC 1070: Section 2
04/9/23
B6: C--*/

#include <iostream>
#include <string>
#include <cctype>

#include "Cipher.h"
#include "Queue.h"

using namespace std;

Cipher::Cipher() { //constructor
  cipherKey = new int[4]{1, 2, 3, 4};
  sizeOfCipher = 4;
}

void Cipher::setCipher(int sizeCipher, int num[]){
  if (sizeCipher < 101) //setter for cipher key 
    {
      sizeOfCipher = sizeCipher; //sets size of the cipher
      cipherKey = num; //sets the num for cipher key 
    }
}

int* Cipher::getCipher(){ //getter for the cipher key 
  int *cipherKeyPtr = cipherKey; 
  return cipherKeyPtr;
}

string Cipher::encodeMessage(string in) { //encodes a message
  string message = "";
  char letter;
  int val, counter = 0, keyNum, back;
  int *cipherPtr = cipherKey;
  long unsigned int ind = 0;

  for (long unsigned int i = 0; i < in.length(); i++) //iterates through the length of the inputted string
    {
      if(isalpha(in.at(i))) //if there is a letter at this spot 
	{
	  letter = in.at(i); 
	  letter = tolower(letter);//make it lower case
	  message = message + letter; //add it to a new string
	}
    }
 
  for (long unsigned int j = 0; j < message.length(); j++) //iteratres through length of inputted string
    {
      letter = message.at(j);
      val = letter;
      q.enqueue(val);//call on enqueue function
    }
  messageToEncode = message; 

  while (ind < message.length()) //while the index is less than the length of the message
    {
      q.dequeue(back);//dequeue
      keyNum = (*cipherPtr % 26);

      //if statements to make sure enqueueing correct amount
      if ((back + keyNum) > 122) 
	{
	  back -= 26;
	}
      if ((back + keyNum) < 97)
	{
	  back += 26;
	}
      back += keyNum;

      q.enqueue(back);

      letter = static_cast<char>(back);

      encodedMessage += letter;
      
      //increment counter and cipherPtr
      ++counter;
      ++cipherPtr;

      //if the counter gets to be the amount of the size of the cipher
      if (counter == sizeOfCipher)
	{
	  //ptr is equal to the cipher
	  cipherPtr = cipherKey;
	  //restart counter
	  counter = 0;
	}
      //increment ind
      ++ind;
    }
  return encodedMessage;
}


string Cipher::decodeMessage(string in) {
 
  int counter = 0, back, keyNum, charNum;
  char newLetter;
  string message = "";
  int *cipherPtr = cipherKey;
  long unsigned int ind = 0;

  //if the queue is empty
  if (q.isEmpty())
    {
      //iterate through the length of the string
      for (long unsigned int i = 0; i < in.length(); i++)
	{
	  if (isalpha(in.at(i)))
	    {
	      //make sure it is only alphabet characters and all lower case
	      newLetter = in.at(i);
	      newLetter = tolower(newLetter);
	      encodedMessage = encodedMessage + newLetter;
	    }
	}

      //iterate through the length of the inputted string
      for (long unsigned int j = 0; j < encodedMessage.length(); j++)
	{
	  newLetter = encodedMessage.at(j);
	  charNum = newLetter;
	  q.enqueue(charNum);//call to enqueue
	}
      message = encodedMessage; //this created the encoded message
    }
  //while loop to keep it less than the length of the encoded message
    while (ind < encodedMessage.length())
      {
	q.dequeue(back);//dequeue
	keyNum = *cipherPtr % 26;

	//find number for how much to enqueue using if statements
	if (back - keyNum < 97)
	  {
	    back += 26;
	  }
	if (back - keyNum > 122)
	  {
	    back -= 26;
	  }
	back -= keyNum;

	q.enqueue(back);//enqueue

	newLetter = static_cast<char>(back);
	decodedMessage += newLetter;

	++counter; //increment counter and ptr
	++cipherPtr;

	//if the counter is the size of the cipher, restart counter, ptr is key 
	if(counter == sizeOfCipher)
	  {
	    cipherPtr = cipherKey;
	    counter = 0;
	  }
	++ind; //increment index
      }
    return decodedMessage;
}
