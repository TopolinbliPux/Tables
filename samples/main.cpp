#include "Polinom.h"
#include "LinearArray.h"
#include "LinearList.h"
#include "AVLTree.h"
#include "HashTable1.h"
#include "HashTable2.h"
#include <iostream>

using namespace std;

void testPolinomFunctions() {
    // Создание полиномов
    Polinom p1;
    p1.addMonom(3, 201);  // 3x^2y
    p1.addMonom(2, 100);  // 2x
    p1.addMonom(1, 0);    // 1

    Polinom p2;
    p2.addMonom(1, 201);  // 1x^2y
    p2.addMonom(4, 0);    // 4

    // Вывод полиномов
    cout << "Polinom p1: ";
    p1.print();
    cout << endl;

    cout << "Polinom p2: ";
    p2.print();
    cout << endl;

    // Оператор +
    Polinom p3 = p1 + p2;
    cout << "p1 + p2: ";
    p3.print();
    cout << endl;

    // Оператор -
    Polinom p4 = p1 - p2;
    cout << "p1 - p2: ";
    p4.print();
    cout << endl;

    // Оператор *
    Polinom p5 = p1 * p2;
    cout << "p1 * p2: ";
    p5.print();
    cout << endl;

    Polinom p6 = p1 * 2;
    cout << "p1 * 2: ";
    p6.print();
    cout << endl;

    // Оператор ==
    bool isEqual = (p1 == p2);
    cout << "p1 == p2: " << (isEqual ? "true" : "false") << endl;

    // Вычисление значения полинома
    double result = p1.calculate(1, 2, 3);
    cout << "p1.calculate(1, 2, 3): " << result << endl;

    // Конструктор копирования
    Polinom p7(p1);
    cout << "Copy of p1 (p7): ";
    p7.print();
    cout << endl;

    // Оператор присваивания
    Polinom p8;
    p8 = p2;
    cout << "Assignment of p2 to p8: ";
    p8.print();
    cout << endl;
}

void testLinearArray() {
    LinearArray la;
    Polinom p1;
    p1.addMonom(3, 201);  // 3x^2y
    la.addPolinom("p1", p1);

    Polinom p2;
    p2.addMonom(1, 100);  // 1x
    la.addPolinom("p2", p2);

    la.printTable();
    la.removePolinom("p1");
    la.printTable();

    Polinom* found = la.findPolinom("p2");
    if (found) {
        cout << "Found p2: ";
        found->print();
        cout << endl;
    }
    else {
        cout << "p2 not found" << endl;
    }
}

void testLinearList() {
    LinearList ll;
    Polinom p1;
    p1.addMonom(3, 201);  // 3x^2y
    ll.addPolinom("p1", p1);

    Polinom p2;
    p2.addMonom(1, 100);  // 1x
    ll.addPolinom("p2", p2);

    ll.printTable();
    ll.removePolinom("p1");
    ll.printTable();

    Polinom* found = ll.findPolinom("p2");
    if (found) {
        cout << "Found p2: ";
        found->print();
        cout << endl;
    }
    else {
        cout << "p2 not found" << endl;
    }
}

void testAVLTree() {
    AVLTree avl;
    Polinom p1;
    p1.addMonom(3, 201);  // 3x^2y
    avl.addPolinom("p1", p1);

    Polinom p2;
    p2.addMonom(1, 100);  // 1x
    avl.addPolinom("p2", p2);

    avl.printTable();
    avl.removePolinom("p1");
    avl.printTable();

    Polinom* found = avl.findPolinom("p2");
    if (found) {
        cout << "Found p2: ";
        found->print();
        cout << endl;
    }
    else {
        cout << "p2 not found" << endl;
    }
}

void testHashTable1() {
    HashTable1 ht1;
    Polinom p1;
    p1.addMonom(3, 201);  // 3x^2y
    ht1.addPolinom("p1", p1);

    Polinom p2;
    p2.addMonom(1, 100);  // 1x
    ht1.addPolinom("p2", p2);

    ht1.printTable();
    ht1.removePolinom("p1");
    ht1.printTable();

    Polinom* found = ht1.findPolinom("p2");
    if (found) {
        cout << "Found p2: ";
        found->print();
        cout << endl;
    }
    else {
        cout << "p2 not found" << endl;
    }
}

void testHashTable2() {
    HashTable2 ht2;
    Polinom p1;
    p1.addMonom(3, 201);  // 3x^2y
    ht2.addPolinom("p1", p1);

    Polinom p2;
    p2.addMonom(1, 100);  // 1x
    ht2.addPolinom("p2", p2);

    ht2.printTable();
    ht2.removePolinom("p1");
    ht2.printTable();

    Polinom* found = ht2.findPolinom("p2");
    if (found) {
        cout << "Found p2: ";
        found->print();
        cout << endl;
    }
    else {
        cout << "p2 not found" << endl;
    }
}

int main() {
    cout << "Testing Polinom functions:" << endl;
    testPolinomFunctions();

    cout << "\nTesting LinearArray:" << endl;
    testLinearArray();

    cout << "\nTesting LinearList:" << endl;
    testLinearList();

    cout << "\nTesting AVLTree:" << endl;
    testAVLTree();

    cout << "\nTesting HashTable1:" << endl;
    testHashTable1();

    cout << "\nTesting HashTable2:" << endl;
    testHashTable2();

    return 0;
}
