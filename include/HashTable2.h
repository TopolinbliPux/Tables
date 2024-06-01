#ifndef HASHTABLE2_H
#define HASHTABLE2_H

#include <iostream>
#include <string>
#include <vector>
#include "Polinom.h"

using namespace std;

class HashTable2 {
private:
    static const int TABLE_SIZE = 10;
    vector<pair<string, Polinom>> table[TABLE_SIZE];

    int hashFunction(const string& key) const;

public:
    void addPolinom(const string& name, const Polinom& poly);
    void removePolinom(const string& name);
    Polinom* findPolinom(const string& name);
    void printTable() const;
};

#endif
