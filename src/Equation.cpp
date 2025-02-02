#include "Equation.h"

//! Constructors, move, copy and destructor
Equation::Equation(int grade) : agmGrade{grade}, factors{(grade > 0? new double[grade] : new double)} {
    if (grade <= 0) throw NotInitialized();
}
Equation::Equation(std::initializer_list<double>f) : agmGrade{static_cast<int>(f.size())}, factors{new double[agmGrade]} {
    int i = 0;
    for (auto el : f) {
        factors[i++] = el;
    }
}
Equation::Equation(const Equation& other) {
    agmGrade = other.agmGrade;
    factors = new double[agmGrade];
    for (int i = 0; i < agmGrade; i++) {
        factors[i] = other.factors[i];
    }
}
Equation::Equation(Equation&& other) {
    agmGrade = other.agmGrade;
    factors = new double[agmGrade];
    for (int i = 0; i < agmGrade; i++) {
        factors[i] = other.factors[i];
    }

    other.agmGrade = 0;
    delete[] other.factors;
    other.factors = nullptr;
}
Equation::~Equation() {
    delete[] factors;
    factors = nullptr;
}

//! Override
Equation Equation::operator=(const Equation& other) noexcept {
    if (this == &other) {
        return *this;
    }

    agmGrade = other.agmGrade;
    delete[] factors;
    
    for (int i = 0; i < agmGrade; i++) {
        factors[i] = other.factors[i];
    }

    return *this;
}
Equation Equation::operator=(Equation&& other) noexcept {
    if (this == &other) {
        return *this;
    }

    agmGrade = other.agmGrade;
    delete[] factors;
    factors = other.factors;

    delete[] other.factors;
    other.factors = nullptr;
    other.agmGrade = 0;

    return *this;
}

bool Equation::operator==(const Equation& comp) noexcept {
    if (agmGrade == comp.agmGrade) {
        for (int i = 0; i < agmGrade; i++) {
            if (factors[i] != comp.factors[i]) {
                return false;
            }
        }   
        return true;
    }
    return false;
}
bool Equation::operator!=(const Equation& comp) noexcept {
    if (agmGrade == comp.agmGrade) {
        for (int i = 0; i < agmGrade; i++) {
            if (factors[i] != comp.factors[i]) {
                return true;
            }
        }
        return false;
    }
    return true;
}
bool Equation::operator>=(const Equation& comp) noexcept {
    if (agmGrade == comp.agmGrade) {
        for (int i = 0; i < agmGrade; i++) {
            if (factors[i] < comp.factors[i]) {
                return false;
            }
        }
        return true;
    } else return agmGrade > comp.agmGrade;
}
bool Equation::operator<=(const Equation& comp) noexcept {
    if (agmGrade == comp.agmGrade) {
        for (int i = 0; i < agmGrade; i++) {
            if (factors[i] > comp.factors[i]) {
                return false;
            }
        }
        return true;
    } else return agmGrade > comp.agmGrade;
}
bool Equation::operator>(const Equation& comp) noexcept {
    if (agmGrade == comp.agmGrade) {
        for (int i = 0; i < agmGrade; i++) {
            if (factors[i] < comp.factors[i]) {
                return false;
            } else if (factors[i] > comp.factors[i]) {
                return true;
            }
        }
        return false;
    } else {
        return agmGrade > comp.agmGrade;
    }
}
bool Equation::operator<(const Equation& comp) noexcept {
    if (agmGrade == comp.agmGrade) {
        for (int i = 0; i < agmGrade; i++) {
            if (factors[i] > comp.factors[i]) {
                return false;
            } else if (factors[i] < comp.factors[i]) {
                return true;
            }
        }
        return false;
    } else {
        return agmGrade < comp.agmGrade;
    }
}