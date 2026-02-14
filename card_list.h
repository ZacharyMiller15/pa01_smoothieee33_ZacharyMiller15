// card_list.h
// Author: Smrethi Shunmuga and Zach Miller`
// All class declarations related to defining a BST that represents a player's hand

#ifndef CARD_LIST_H
#define CARD_LIST_H
#include <iostream>
#include <vector>
#include "card.h"

using namespace std;

class hand{
        struct Node {
            Card* card;
            Node* parent;
            Node* left;
            Node* right;
            Node(Card* c) : card(c), parent(nullptr), left(nullptr), right(nullptr) {}
        };
        Node* root;

        void insert(char s, string num, Node* n, Node* parent);
        Card* search(Node* node, const Card& card) const;
        void destroyTree(Node* node);
        static Node* minNode(Node* n);
        static Node* maxNode(Node* n);
        static Node* predecessor(Node* n);
        static Node* successor(Node* n);
        //vector<Card*> flatten_s2l(Node* n);
        //vector<Card*> flatten_l2s(Node* n);
        void inorderPrint(Node* n) const;
        void transplant(Node* original, Node* new_node);
        Node* getPredecessorNode(char s, string num) const;
        Node* getNodeFor(char s, string num, Node* n) const;
    public:
        hand();
        ~hand();
        void insert(char s, string num);
        Card* search(const Card& card) const;
        bool remove(char s, string num);
        //vector<Card*> flattened_hand_s2l();
        //vector<Card*> flattened_hand_l2s();
        Node* get_root(){return root;}
        void printHand() const; 
        class iterator{
            private:
            Node* curr;
            public:
            iterator(Node* ptr) : curr(ptr){};
            Card& operator*() const{ return *(curr->card);}
            Card* operator->() const{ return curr->card;}
            iterator& operator++(){
                curr = successor(curr);
                return *this;
            }
            iterator& operator--(){
                curr = predecessor(curr);
                return *this;
            }

            bool operator==(const iterator& other) const {return curr == other.curr;}
            bool operator!=(const iterator& other) const {return curr != other.curr;}
        };
        iterator begin(){return iterator(minNode(root));}
        iterator rbegin(){return iterator(maxNode(root));}
        iterator end(){return iterator(nullptr);}
};

#endif
