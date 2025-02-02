#ifndef EQUATIONS_H
#define EQUATIONS_H

#include <initializer_list>
#include <iostream>
#include <vector>
#include <stdexcept>

class Equation {
private:
    int agmGrade;
    double *factors;
public:
    class NotInitialized : public std::exception{};
    Equation(int grade = 1);
    Equation(std::initializer_list<double>f);
    Equation(const Equation& other);
    Equation(Equation&& other);
    ~Equation();

    Equation operator=(const Equation& other) noexcept;
    Equation operator=(Equation&& other) noexcept;

    bool operator==(const Equation& comp) noexcept;
    bool operator!=(const Equation& comp) noexcept;
    bool operator>=(const Equation& comp) noexcept;
    bool operator<=(const Equation& comp) noexcept;
    bool operator>(const Equation& comp) noexcept;
    bool operator<(const Equation& comp) noexcept;
};

#endif