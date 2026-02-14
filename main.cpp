// This file should implement the game using a custom implementation of a BST (based on your earlier BST implementation)
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "card_list.h"
//Do not include set in this file

using namespace std;

int main(int argv, char** argc){
  if(argv < 3){
    cout << "Please provide 2 file names" << endl;
    return 1;
  }
  
  ifstream cardFile1 (argc[1]);
  ifstream cardFile2 (argc[2]);
  string line;

  if (cardFile1.fail() || cardFile2.fail() ){
    cout << "Could not open file " << argc[2];
    return 1;
  }

  // //Read each file
  // while (getline (cardFile1, line) && (line.length() > 0)){

  // }
  // cardFile1.close();


  // while (getline (cardFile2, line) && (line.length() > 0)){

  // }
  // cardFile2.close();
  
  
  // return 0;


  hand alice;
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit;
    string number;
    suit = line[0];
    number = line.substr(2);
    alice.insert(suit, number);
  }
  cardFile1.close();

  hand bob;
  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit;
    string number;
    suit = line[0];
    number = line.substr(2);
    bob.insert(suit, number);
  }
  cardFile2.close();

  bool turn = true;
  bool stall_bob = false;
  bool stall_alice = false;

  while (true){
    if (turn){
      bool found = false;
      for(auto it = alice.begin(); it != alice.end(); ++it){
        Card* bob_card = bob.search(*it);
        if(bob_card != nullptr){
            cout << "Alice picked matching card ";
            (*it).printCard();
            bob.remove(bob_card->getSuit(), bob_card->getNumber());
            alice.remove(it->getSuit(), it->getNumber());
            found = true;
            stall_alice = false;
            turn = false;
            break;
        }
      }
      if(!found){
        stall_alice = true;
        turn = false;
      }
    }
    else{
      bool found = false;
      for(auto it = bob.rbegin(); it!=bob.end(); --it){
        Card* alice_card = alice.search(*it);
        if (alice_card != nullptr){
            cout << "Bob picked matching card ";
            (*it).printCard();
            bob.remove(it->getSuit(), it->getNumber());
            alice.remove(alice_card->getSuit(), alice_card->getNumber());
            found = true;
            turn = true;
            stall_bob = false;
            break;
        }
      }
      if(!found){
        stall_bob = true;
        turn = true;
      }
    }

    if (stall_alice && stall_bob)
      break;
  }

  cout << "Alice's Cards:" << endl;
  for (auto it = alice.begin(); it != alice.end(); ++it){
    (*it).printCard();
  }

    cout << "Bob's Cards:" << endl;
  for (auto it = bob.begin(); it != bob.end(); ++it){
    (*it).printCard();
  }

  return 0;
}



