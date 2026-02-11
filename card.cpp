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
bool Card::operator<(const Card &other) const{
    int this_one;
    int that_one;
    int this_num;
    int that_num;

    if (this.suit == 'h'){
        this_one = 4;
    }
    if (this.suit == 's'){
        this_one = 3;
    }
    if (this.suit == 'd'){
        this_one = 2;
    }
    if (this.suit == 'c'){
        this_one = 1;
    }

    if (other.getsuit() == 'h'){
        this_one = 4;
    }
    if (other.getsuit() == 's'){
        this_one = 3;
    }
    if (other.getsuit() == 'd'){
        this_one = 2;
    }
    if (other.getsuit() == 'c'){
        this_one = 1;
    }

    if (this.number == "k"){
        this_num = "13";
    }
    else if (this.number == "q"){
        this_num = "12";
    }
    else if (this.number == "j"){
        this_num = "11";
    }
    else if (this.number == "a"){
        this_num = "1";
    }
    else{
        this_num = this.number;
    }

    if (other.getNumber() == "k"){
        that_num = "13";
    }
    else if (other.getNumber() == "q"){
        that_num = "12";
    }
    else if (other.getNumber()== "j"){
        that_num = "11";
    }
    else if (other.getNumber() == "a"){
        that_num = "1";
    }
    else{
        that_num = other.getNumber();
    }


    if (this_one != that_one)
        return (this_one < that_one);
    else
        return (stoi(this_num) < stoi(that_num));

}

