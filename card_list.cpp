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

void hand::insert(char s, string num) {
    insert(s, num, root, nullptr);
}

void hand::insert(char s, string num, Node* n, Node* parent) {
    // if (node == nullptr) {
    //     node = new Node(card);
    // } else if (*card < *(node->card)) {
    //     insert(node->left, card);
    // } else {
    //     insert(node->right, card);
    // }

    if (!n) {
        if (!parent){
            Card* c = new Card(s, num);
            root = new Node(c);
            root->parent = nullptr;
        } else if (*(parent->card) < Card(s, num)) {
            Card* c = new Card(s, num);
            parent->right = new Node(c);
            parent->right->parent = parent;
        } else {
            Card* c = new Card(s, num);
            parent->left = new Node(c);
            parent->left->parent = parent;
        }

        return;
    }

    if (Card(s, num) < *(n->card)) {
        insert(s, num, n->left, n);
    } else {
        insert(s, num, n->right, n);
    }

    return;
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

// void hand::flattened_hand_s2l(Node* n, vector<Card*>& v){
//     if (!n) return;
//     flattened_hand_s2l(n->left, v);
//     v.push_back(n->card);
//     flattened_hand_s2l(n->right, v);
// }

// vector<Card*> hand::flatten_s2l(){
//     vector<Card*> v;
//     flatten_hand_s2l(root, v);
//     return v;
// }

// void hand::flattened_hand_l2s(Node* n, vector<Card*>& v){
//     if (!n) return;
//     flattened_hand_l2s(n->right, v);
//     v.push_back(n->card);
//     flattened_hand_l2s(n->left, v);
// }

// vector<Card*> hand::flatten_l2s(){
//     vector<Card*> v;
//     flatten_hand_l2s(root, v);
//     return v;}

hand::Node* hand::getNodeFor(char s, string num, Node* n) const{
    if (!n) return nullptr;

    if (s == n->card->getSuit() && num == n->card->getNumber()) return n;

    if (Card(s, num) < *(n->card)) {
        return getNodeFor(s, num, n->left);
    } else {
        return getNodeFor(s, num, n->right);
    }
}

void hand::transplant(Node* original, Node* new_node) {
    if (original == root) {
        root = new_node;
    } else if (original == original->parent->left) {
        original->parent->left = new_node;
    } else if (original == original->parent->right) {
        original->parent->right = new_node;
    }

    if (new_node) {
        new_node->parent = original->parent;
    }
}

hand::Node* hand::getPredecessorNode(char s, string num) const{
    Node* n = getNodeFor(s, num, root);
    if (!n) return nullptr;

    if (n->left) {
        Node* curr = n->left;
        while (curr->right) {
            curr = curr->right;
        }
        return curr;
    }

    while (n->parent && n == n->parent->left) {
        n = n->parent;
    }

    if (n->parent) return n->parent;

    return nullptr;
}
hand::Node* hand::minNode(hand::Node* n){
    if(!n) return nullptr;
    while (n->left){
        n = n->left;
    }
    return n;
}
hand::Node* hand::maxNode(hand::Node* n){
    if(!n) return nullptr;
    while (n->right){
        n = n->right;
    }
    return n;
}
hand::Node* hand::predecessor(hand::Node* n){
    if (!n) return nullptr;

    if (n->left) {
        Node* curr = n->left;
        while (curr->right) {
            curr = curr->right;
        }
        return curr;
    }

    while (n->parent && n == n->parent->left) {
        n = n->parent;
    }

    if (n->parent) return n->parent;

    return nullptr;
}

hand::Node* hand::successor(hand::Node* n){
    if (!n) return nullptr;

    if (n->right) {
        Node* curr = n->right;
        while (curr->left) {
            curr = curr->left;
        }
        return curr;
    }

    while (n->parent && n == n->parent->right) {
        n = n->parent;
    }

    if (n->parent) return n->parent;

    return nullptr;
}

bool hand::remove(char s, string num){
    Node* removal = getNodeFor(s, num, root);

    if (!removal) return false;

    if (!removal->left && !removal->right) {
        transplant(removal, nullptr);
        delete removal;
        return true;
    } else if (!removal->left && removal->right) {
        transplant(removal, removal->right);
        delete removal;
        return true;
    } else if (!removal->right && removal->left) {
        transplant(removal, removal->left);
        delete removal;
        return true;
    }

    Node* pred = getPredecessorNode(s, num);

    if (pred->parent != removal) {
        transplant(pred, pred->left);
        pred->left = removal->left;
        pred->left->parent = pred;
    }

    transplant(removal, pred);
    pred->right = removal->right;
    pred->right->parent = pred;

    delete removal;
    return true;
}



