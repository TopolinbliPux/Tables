#include "LinearArray.h"

void LinearArray::addPolinom(const string& name, const Polinom& poly) {
    table.push_back(make_pair(name, poly));
}

void LinearArray::removePolinom(const string& name) {
    table.erase(remove_if(table.begin(), table.end(), [&name](const pair<string, Polinom>& p) {
        return p.first == name;
        }), table.end());
}

Polinom* LinearArray::findPolinom(const string& name) {
    for (auto& item : table) {
        if (item.first == name) {
            return &item.second;
        }
    }
    return nullptr;
}

void LinearArray::printTable() const {
    for (const auto& item : table) {
        cout << item.first << " = ";
        item.second.print();
        cout << endl;
    }
}
