#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include "Polinom.h"

using namespace std;

class AVLTree {
private:
    struct Node {
        string key;
        Polinom value;
        int height;
        Node* left;
        Node* right;
        Node(const string& k, const Polinom& v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    int height(Node* n);
    int balanceFactor(Node* n);
    void fixHeight(Node* n);
    Node* rotateRight(Node* p);
    Node* rotateLeft(Node* q);
    Node* balance(Node* n);
    Node* insert(Node* n, const string& key, const Polinom& value);
    Node* findMin(Node* n);
    Node* removeMin(Node* n);
    Node* remove(Node* n, const string& key);
    Node* find(Node* n, const string& key);
    void inOrderPrint(Node* n) const;

public:
    AVLTree();
    ~AVLTree();
    void addPolinom(const string& name, const Polinom& poly);
    void removePolinom(const string& name);
    Polinom* findPolinom(const string& name);
    void printTable() const;
};

#endif
