#ifndef POLINOM_H
#define POLINOM_H

#include <iostream>
#include <cmath>

using namespace std;

class Polinom {
private:
    struct Monom {
        int koef;
        int step;
        Monom* next;
        Monom(int k, int s) : koef(k), step(s), next(nullptr) {}
    };
    Monom* head;

public:
    Polinom();
    ~Polinom();
    Polinom(const Polinom& other); // Конструктор копирования
    Polinom& operator=(const Polinom& other); // Оператор присваивания
    void addMonom(int koef, int step);
    Polinom operator+(const Polinom& other) const;
    Polinom operator*(int k) const;
    Polinom operator*(const Polinom& other) const;
    Polinom operator-(const Polinom& other) const;
    bool operator==(const Polinom& other) const;
    double calculate(double x, double y, double z) const;
    void print() const;
};

#endif
