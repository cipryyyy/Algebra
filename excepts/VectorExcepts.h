#ifndef VECTOREXCEPTS_H
#define VECTOREXCEPTS_H

#include <stdexcept>

namespace Algebra {
    class VectorIndexOutOfBound : public std::exception{
    public:
        const char* what() const noexcept override {
            return "Index out of bound";
        }
    };
    class NonCompatibleVectors : public std::exception{
    public:
        const char* what() const noexcept override {
            return "Cannot operate on vectors of different spaces";
        }
    };
}

#endif