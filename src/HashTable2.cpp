#include "HashTable2.h"

int HashTable2::hashFunction(const string& key) const {
    int hash = 0;
    for (char c : key) {
        hash = (hash * 31 + c) % TABLE_SIZE;
    }
    return hash;
}

void HashTable2::addPolinom(const string& name, const Polinom& poly) {
    int hash = hashFunction(name);
    table[hash].push_back(make_pair(name, poly));
}

void HashTable2::removePolinom(const string& name) {
    int hash = hashFunction(name);
    auto& cell = table[hash];
    cell.erase(remove_if(cell.begin(), cell.end(), [&name](const pair<string, Polinom>& p) {
        return p.first == name;
        }), cell.end());
}

Polinom* HashTable2::findPolinom(const string& name) {
    int hash = hashFunction(name);
    auto& cell = table[hash];
    for (auto& item : cell) {
        if (item.first == name) {
            return &item.second;
        }
    }
    return nullptr;
}

void HashTable2::printTable() const {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        for (const auto& item : table[i]) {
            cout << item.first << " = ";
            item.second.print();
            cout << endl;
        }
    }
}
