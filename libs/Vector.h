#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include <cmath>
#include <ostream>
#include "Space.h"
#include "VectorExcepts.h"

namespace Algebra {
    class Vector {
    private:
        double *c;
        Space space;
    public:
        Vector(int dimension = 0);
        Vector(std::initializer_list<double> comps);
        Vector(const Vector& other) noexcept;
        Vector(Vector&& other) noexcept;
        Vector& operator=(const Vector& other);
        Vector& operator=(Vector&& other) noexcept;
        ~Vector();

        int getDimension();
        double mod();
        double scalar(Vector vec);

        double& operator[](int index);
        const double& operator[](int index) const;
        Vector operator+(const Vector& vec);
        Vector operator-(const Vector& vec);
        Vector operator*(int scalar);

        friend std::ostream& operator<<(std::ostream& os, const Vector& V);
    };
}
#endif