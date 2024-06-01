#ifndef LINEARLIST_H
#define LINEARLIST_H

#include <iostream>
#include <string>
#include <list>
#include "Polinom.h"

using namespace std;

class LinearList {
private:
    list<pair<string, Polinom>> table;
public:
    void addPolinom(const string& name, const Polinom& poly);
    void removePolinom(const string& name);
    Polinom* findPolinom(const string& name);
    void printTable() const;
};

#endif
