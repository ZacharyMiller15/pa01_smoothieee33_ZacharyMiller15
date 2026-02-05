// card_list.cpp
// Author: Smrethi Shunmuga and Zach Miller
// Implementation of the classes defined in card_list.h

#include "card_list.h"
#include <iostream>

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

bool hand::search(const Card& card) const {
    return search(root, card);
}

bool hand::search(Node* node, const Card& card) const {
    if (node == nullptr) {
        return false;
    } else if (card == *(node->card)) {
        return true;
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
        delete node;
    }
}