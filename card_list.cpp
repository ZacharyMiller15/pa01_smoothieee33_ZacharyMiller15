// card_list.cpp
// Author: Smrethi Shunmuga and Zach Miller
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include <iostream>
#include <vector>

using namespace std;

hand::hand() : root(nullptr) {}

hand::~hand() {
    destroyTree(root);
}

void hand::insert(Card* card) {
    insert(root, card);
}

void hand::insert(Node*& node, Card* card) {
    if (node == nullptr) {
        node = new Node(card);
    } else if (*card < *(node->card)) {
        insert(node->left, card);
    } else if (*card > *(node->card)) {
        insert(node->right, card);
    }
}

Card* hand::search(const Card& card) const {
    return search(root, card);
}

Card* hand::search(Node* node, const Card& card) const {
    if (node == nullptr) 
        return nullptr;

    if (card == *(node->card)) {
        return node->card;
    } else if (card < *(node->card)) {
        return search(node->left, card);
    } else {
        return search(node->right, card);
    }
}

void hand::printHand() const {
    inorderPrint(root);
}

void hand::inorderPrint(Node* node) const {
    if (node != nullptr) {
        inorderPrint(node->left);
        node->card->printCard();
        inorderPrint(node->right);
    }
}

void hand::destroyTree(Node* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node->card;
        delete node;
    }
}

void hand::flattened_hand_s2l(Node* n, vector<Card*>& v){
    if (!n) return;
    flattened_hand_s2l(n->left, v);
    v.push_back(n->card);
    flattened_hand_s2l(n->right, v);
}

vector<Card*> hand::flatten_s2l(){
    vector<Card*> v;
    flatten_hand_s2l(root, v);
    return v;
}

void hand::flattened_hand_l2s(Node* n, vector<Card*>& v){
    if (!n) return;
    flattened_hand_l2s(n->right, v);
    v.push_back(n->card);
    flattened_hand_l2s(n->left, v);
}

vector<Card*> hand::flatten_l2s(){
    vector<Card*> v;
    flatten_hand_l2s(root, v);
    return v;}

Node* hand::remove(Node* node, const Card& card){
    // vector<Card*> v = this.flatten_l2s();
    // for(Card* c : v){
    //     if (*c == card){
    //         v.erase(c);
    //         break;
    //     }     
    // }
    // destroyTree(root);
    // hand new_one = hand();
    // for (Card* c : v){
    //     new_one.insert(c);
    // }
    // root = new_one.get_root();

    if (!node) return nullptr;

    if (card < *(node->card))
        node->left = remove(node->left, card);
    else if (card > *(node->card))
        node->right = remove(node->right, card);
    else{
        if(!node->left && !node->right){
            delete node->card;
            delete node;
            return nullptr;
        }
        else if (node->left && !node->right) {
            Node* temp = node->left;
            delete node->card;
            delete node;
            return temp;
        }
        else if (node->right && !node->left) {
            Node* temp = node->right;
            delete node->card;
            delete node;
            return temp;
        }
        else{
            Node* succ = node->right;
            while (succ->left)
                succ = succ->left;
            node->card = succ->card;
            node->right = remove(node->right, *(succ->card));
        }
    }
    return node;
}
void hand::remove(const Card& card){
    root = remove(root, card);
}
