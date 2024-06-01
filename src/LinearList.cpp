#include "LinearList.h"

void LinearList::addPolinom(const string& name, const Polinom& poly) {
    table.push_back(make_pair(name, poly));
}

void LinearList::removePolinom(const string& name) {
    table.remove_if([&name](const pair<string, Polinom>& p) {
        return p.first == name;
        });
}

Polinom* LinearList::findPolinom(const string& name) {
    for (auto& item : table) {
        if (item.first == name) {
            return &item.second;
        }
    }
    return nullptr;
}

void LinearList::printTable() const {
    for (const auto& item : table) {
        cout << item.first << " = ";
        item.second.print();
        cout << endl;
    }
}
