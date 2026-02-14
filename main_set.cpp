// This file should implement the game using the std::set container class
// Do not include card_list.h in this file
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include "card.h"

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

  set<Card> alice;
  while (getline (cardFile1, line) && (line.length() > 0)){
    char suit;
    string number;
    suit = line[0];
    number = line.substr(2);
    Card card = Card(suit, number);
    alice.insert(card);
  }
  cardFile1.close();

  set<Card> bob;
  while (getline (cardFile2, line) && (line.length() > 0)){
    char suit;
    string number;
    suit = line[0];
    number = line.substr(2);
    Card card = Card(suit, number);
    bob.insert(card);
  }
  cardFile2.close();

  bool turn = true;
  bool stall_bob = false;
  bool stall_alice = false;

  while (true){
    if (turn){
      bool found = false;
      for(auto it = alice.begin(); it != alice.end(); ++it){
        auto bob_it = bob.find(*it);
        if(bob_it != bob.end()){
            cout << "Alice picked matching card ";
            (*it).printCard();
            bob.erase(bob_it);
            alice.erase(it);
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
      for(auto it = bob.rbegin(); it!=bob.rend(); ++it){
        auto alice_it = alice.find(*it);
        if(alice_it != alice.end()){
            cout << "Bob picked matching card ";
            (*it).printCard();
            alice.erase(alice_it);
            auto erase_it = prev(it.base());
            bob.erase(erase_it);
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
  for (auto it = alice.begin(); it != alice.end(); it++){
    (*it).printCard();
  }

    cout << "Bob's Cards:" << endl;
  for (auto it = bob.begin(); it != bob.end(); it++){
    (*it).printCard();
  }

  return 0;
}
