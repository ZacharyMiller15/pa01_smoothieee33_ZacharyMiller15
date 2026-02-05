// card.h
// Author: Smrethi Shunmuga and Zach Miller
// All class declarations related to defining a single card go here

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>

using namespace std;

class Card {
    private:
        char suit;
        string number;
    public:
        Card(char s, char n);
        ~Card();
        char getSuit() const;
        string getNumber() const;
        void printCard() const;
        bool operator==(const Card &other) const;
}
#endif
