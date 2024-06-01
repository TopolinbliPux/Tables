#include "AVLTree.h"

int AVLTree::height(Node* n) {
    return n ? n->height : 0;
}

int AVLTree::balanceFactor(Node* n) {
    return height(n->right) - height(n->left);
}

void AVLTree::fixHeight(Node* n) {
    int hl = height(n->left);
    int hr = height(n->right);
    n->height = (hl > hr ? hl : hr) + 1;
}

AVLTree::Node* AVLTree::rotateRight(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixHeight(p);
    fixHeight(q);
    return q;
}

AVLTree::Node* AVLTree::rotateLeft(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixHeight(q);
    fixHeight(p);
    return p;
}

AVLTree::Node* AVLTree::balance(Node* n) {
    fixHeight(n);
    if (balanceFactor(n) == 2) {
        if (balanceFactor(n->right) < 0)
            n->right = rotateRight(n->right);
        return rotateLeft(n);
    }
    if (balanceFactor(n) == -1) {
        if (balanceFactor(n->left) > 0)
            n->left = rotateLeft(n->left);
        return rotateRight(n);
    }
    return n;
}

AVLTree::Node* AVLTree::insert(Node* n, const string& key, const Polinom& value) {
    if (!n) return new Node(key, value);
    if (key < n->key)
        n->left = insert(n->left, key, value);
    else
        n->right = insert(n->right, key, value);
    return balance(n);
}

AVLTree::Node* AVLTree::findMin(Node* n) {
    return n->left ? findMin(n->left) : n;
}

AVLTree::Node* AVLTree::removeMin(Node* n) {
    if (!n->left) return n->right;
    n->left = removeMin(n->left);
    return balance(n);
}

AVLTree::Node* AVLTree::remove(Node* n, const string& key) {
    if (!n) return nullptr;
    if (key < n->key) {
        n->left = remove(n->left, key);
    }
    else if (key > n->key) {
        n->right = remove(n->right, key);
    }
    else {
        Node* left = n->left;
        Node* right = n->right;
        delete n;
        if (!right) return left;
        Node* min = findMin(right);
        min->right = removeMin(right);
        min->left = left;
        return balance(min);
    }
    return balance(n);
}

AVLTree::Node* AVLTree::find(Node* n, const string& key) {
    if (!n) return nullptr;
    if (key == n->key) return n;
    if (key < n->key)
        return find(n->left, key);
    else
        return find(n->right, key);
}

void AVLTree::inOrderPrint(Node* n) const {
    if (!n) return;
    inOrderPrint(n->left);
    cout << n->key << " = ";
    n->value.print();
    cout << endl;
    inOrderPrint(n->right);
}

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    while (root) {
        root = remove(root, root->key);
    }
}

void AVLTree::addPolinom(const string& name, const Polinom& poly) {
    root = insert(root, name, poly);
}

void AVLTree::removePolinom(const string& name) {
    root = remove(root, name);
}

Polinom* AVLTree::findPolinom(const string& name) {
    Node* result = find(root, name);
    return result ? &result->value : nullptr;
}

void AVLTree::printTable() const {
    inOrderPrint(root);
}
