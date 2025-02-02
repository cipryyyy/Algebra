#include "Vector.h"

//! Helper

//! Private

//! Constructors, move, copy and destroyer
Algebra::Vector::Vector(int dimension) : c{new double[dimension]}, space{Space(dimension)} {}
Algebra::Vector::Vector(std::initializer_list<double> comps) : c{new double[static_cast<int>(comps.size())]}, space{Space(static_cast<int>(comps.size()))} {
    int i = 0;
    for (auto comp : comps) {
        c[i++] = comp;
    }
}
Algebra::Vector::Vector(const Vector& other) noexcept : c{new double[other.space.getDimension()]}, space{other.space} {
    for (int i = 0; i < space.getDimension(); ++i) {
        c[i] = other.c[i];
    }
}
Algebra::Vector::Vector(Vector&& vec) noexcept : c(nullptr), space(vec.space) {
    c = vec.c;
    vec.c = nullptr;
}
Algebra::Vector& Algebra::Vector::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] c;
    space = other.space;
    c = new double[space.getDimension()];
    for (int i = 0; i < space.getDimension(); ++i) {
        c[i] = other.c[i];
    }
    return *this;
}
Algebra::Vector& Algebra::Vector::operator=(Vector&& vec) noexcept {
    if (this != &vec) {
        delete[] c;
        c = vec.c;
        space = vec.space;
        vec.c = nullptr;
    }
    return *this;
}
Algebra::Vector::~Vector() {
    delete[] c;
    c = nullptr;
}

//! Setter and Getter
int Algebra::Vector::getDimension() {
    return space.getDimension();
}

//! Operations
double Algebra::Vector::mod() {
    double mod = 0;
    for (int i = 0; i < space.getDimension(); i++) {
        mod += c[i]*c[i];
    }
    return std::sqrt(mod);
}
double Algebra::Vector::scalar(Vector vec) {
    double sum = 0;
    for (int i = 0; i < space.getDimension(); i++) {
        sum += c[i]*vec[i];
    }
    return sum;
}
void Algebra::Vector::normalize() {
    double m = mod();
    for (int i = 0; i < space.getDimension(); i++) {
        c[i] /= m;
    }
}

//! Overrides
double& Algebra::Vector::operator[](int index) {
    if (index < 0 || index >= space.getDimension()) throw VectorIndexOutOfBound();
    return c[index];
}
const double& Algebra::Vector::operator[](int index) const {
    if (index < 0 || index >= space.getDimension()) throw VectorIndexOutOfBound();
    return c[index];
}
Algebra::Vector Algebra::Vector::operator+(const Vector& vec) {
    if (space.getDimension() != vec.space.getDimension()) throw NonCompatibleVectors();
    Vector add(space.getDimension());
    for (int i = 0; i < space.getDimension(); i++) {
        add[i] = c[i] + vec[i];
    }
    return add;
}
Algebra::Vector Algebra::Vector::operator-(const Vector& vec) {
    if (space.getDimension() != vec.space.getDimension()) throw NonCompatibleVectors();
    Vector sub(space.getDimension());
    for (int i = 0; i < space.getDimension(); i++) {
        sub[i] = c[i] - vec[i];
    }
    return sub;
}
Algebra::Vector Algebra::Vector::operator*(int scalar) {
    Vector Prod(space.getDimension());
    for (int i = 0; i < space.getDimension(); i++) {
        Prod[i] = c[i] * scalar;
    }
    return Prod;
}

//! Friends
namespace Algebra {
    std::ostream& operator<< (std::ostream& os, const Algebra::Vector& V) {
        os << "[";
        for (int i = 0; i < V.space.getDimension(); i++) {
            os << V.c[i];
            if (i < V.space.getDimension()-1) os << ", ";
        }
        os << "]";
        return os;
    }
}