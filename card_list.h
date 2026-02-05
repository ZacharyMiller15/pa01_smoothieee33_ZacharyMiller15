// card_list.h
// Author: Smrethi Shunmuga and Zach Miller`
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include <iostream>
#include <vector>

using namespace std;

class hand{
    private:
        struct Node {
            Card* card;
            Node* left;
            Node* right;
            Node(Card* c) : card(c), left(nullptr), right(nullptr) {}
        };
        Node* root;

        void insert(Node*& node, Card* card);
        bool search(Node* node, const Card& card) const;
        void destroyTree(Node* node);
        void remove(Node*& node, const Card* card);
        vector<Card*> flatten_s2l(Node* n);
        vector<Card*> flatten_l2s(Node* n);
    public:
        hand();
        ~hand();
        void insert(Card* card);
        bool search(const Card& card) const;
        void remove(const Card& card);
        vector<Card*> flattened_hand_s2l();
        vector<Card*> flattened_hand_l2s();

 
}

#endif
