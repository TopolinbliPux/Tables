#include "Polinom.h"

// Конструктор по умолчанию
Polinom::Polinom() : head(nullptr) {}

// Деструктор
Polinom::~Polinom() {
    while (head) {
        Monom* temp = head;
        head = head->next;
        delete temp;
    }
}

// Конструктор копирования
Polinom::Polinom(const Polinom& other) : head(nullptr) {
    Monom* current = other.head;
    Monom* prev = nullptr;
    while (current) {
        Monom* newMonom = new Monom(current->koef, current->step);
        if (prev) {
            prev->next = newMonom;
        }
        else {
            head = newMonom;
        }
        prev = newMonom;
        current = current->next;
    }
}

// Оператор присваивания
Polinom& Polinom::operator=(const Polinom& other) {
    if (this == &other) {
        return *this;
    }

    Monom* current = head;
    while (current) {
        Monom* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;

    current = other.head;
    Monom* prev = nullptr;
    while (current) {
        Monom* newMonom = new Monom(current->koef, current->step);
        if (prev) {
            prev->next = newMonom;
        }
        else {
            head = newMonom;
        }
        prev = newMonom;
        current = current->next;
    }
    return *this;
}

void Polinom::addMonom(int koef, int step) {
    Monom* newMonom = new Monom(koef, step);
    if (!head || step > head->step) {
        newMonom->next = head;
        head = newMonom;
    }
    else {
        Monom* curr = head;
        Monom* prev = nullptr;
        while (curr && curr->step > step) {
            prev = curr;
            curr = curr->next;
        }
        if (curr && curr->step == step) {
            curr->koef += koef;
            if (curr->koef == 0) {
                if (prev) prev->next = curr->next;
                else head = curr->next;
                delete curr;
            }
            delete newMonom;
        }
        else {
            newMonom->next = curr;
            if (prev) prev->next = newMonom;
            else head = newMonom;
        }
    }
}

Polinom Polinom::operator+(const Polinom& other) const {
    Polinom result;
    Monom* monom1 = head;
    Monom* monom2 = other.head;
    while (monom1 || monom2) {
        if (!monom1) {
            result.addMonom(monom2->koef, monom2->step);
            monom2 = monom2->next;
        }
        else if (!monom2) {
            result.addMonom(monom1->koef, monom1->step);
            monom1 = monom1->next;
        }
        else if (monom1->step == monom2->step) {
            int newKoef = monom1->koef + monom2->koef;
            if (newKoef != 0) result.addMonom(newKoef, monom1->step);
            monom1 = monom1->next;
            monom2 = monom2->next;
        }
        else if (monom1->step > monom2->step) {
            result.addMonom(monom1->koef, monom1->step);
            monom1 = monom1->next;
        }
        else {
            result.addMonom(monom2->koef, monom2->step);
            monom2 = monom2->next;
        }
    }
    return result;
}

Polinom Polinom::operator*(int k) const {
    Polinom result;
    if (k == 0) return result;
    for (Monom* curr = head; curr; curr = curr->next) {
        result.addMonom(curr->koef * k, curr->step);
    }
    return result;
}

Polinom Polinom::operator*(const Polinom& other) const {
    Polinom result;
    for (Monom* monom1 = head; monom1; monom1 = monom1->next) {
        for (Monom* monom2 = other.head; monom2; monom2 = monom2->next) {
            result.addMonom(monom1->koef * monom2->koef, monom1->step + monom2->step);
        }
    }
    return result;
}

Polinom Polinom::operator-(const Polinom& other) const {
    return *this + (other * -1);
}

bool Polinom::operator==(const Polinom& other) const {
    Monom* monom1 = head;
    Monom* monom2 = other.head;
    while (monom1 && monom2) {
        if (monom1->step != monom2->step || monom1->koef != monom2->koef) return false;
        monom1 = monom1->next;
        monom2 = monom2->next;
    }
    return !monom1 && !monom2;
}

double Polinom::calculate(double x, double y, double z) const {
    double result = 0;
    for (Monom* curr = head; curr; curr = curr->next) {
        double termValue = curr->koef;
        int step = curr->step;
        termValue *= pow(x, step / 100);
        termValue *= pow(y, (step % 100) / 10);
        termValue *= pow(z, step % 10);
        result += termValue;
    }
    return result;
}

void Polinom::print() const {
    if (!head) {
        cout << "0";
        return;
    }
    for (Monom* curr = head; curr; curr = curr->next) {
        if (curr != head && curr->koef > 0) cout << "+";
        if (curr->koef != 1 || curr->step == 0) cout << curr->koef;
        int step = curr->step;
        int stepX = step / 100;
        int stepY = (step % 100) / 10;
        int stepZ = step % 10;
        if (stepX > 0) cout << "x";
        if (stepX > 1) cout << "^" << stepX;
        if (stepY > 0) cout << "y";
        if (stepY > 1) cout << "^" << stepY;
        if (stepZ > 0) cout << "z";
        if (stepZ > 1) cout << "^" << stepZ;
    }
}
