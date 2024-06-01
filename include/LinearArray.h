#ifndef LINEARARRAY_H
#define LINEARARRAY_H

#include <iostream>
#include <string>
#include <vector>
#include "Polinom.h"

using namespace std;

class LinearArray {
private:
    vector<pair<string, Polinom>> table;
public:
    void addPolinom(const string& name, const Polinom& poly);
    void removePolinom(const string& name);
    Polinom* findPolinom(const string& name);
    void printTable() const;
};

#endif
