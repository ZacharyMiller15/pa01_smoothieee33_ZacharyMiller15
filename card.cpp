// card.cpp
// Author: Smrethi Shunmuga and Zach Miller
// Implementation of the classes defined in card.h

#include "card.h"
#include <iostream>
#include <string>

using namespace std;
Card::Card(char s, string n) : suit(s), number(n) {}
Card::~Card() {}
char Card::getSuit() const {
    return suit;
}
string Card::getNumber() const {
    return number;
}
void Card::printCard() const {
    cout << suit << " " << number << endl;
}
bool Card::operator==(const Card &other) const {
    return (suit == other.suit) && (number == other.number);
}

