#ifndef MATRIX_H
#define MATRIX_H

#include <initializer_list>
#include <iostream>
#include <cmath>
#include "MatrixExcepts.h"

namespace Algebra {
    class Matrix {
    private:
        int rows, cols;
        double **data;
        Matrix subMatrix(int rCut, int cCut) const;
        //TODO switch lines for Gauss

    public:
        Matrix (int rows = 0, int cols = 0);
        Matrix (int rows, int cols, std::initializer_list<double> list);

        Matrix (const Matrix& other);
        Matrix (Matrix&& other);
        Matrix& operator= (const Matrix& other);
        Matrix& operator= (Matrix&& other);
        ~Matrix();

        int getCols() const {return cols;}
        int getRows() const {return rows;}

        void set(int r, int c, double val);
        double& get(int r, int c) const;

        double determinant() const;
        Matrix invert() const;
        Matrix transpose() const;
        //TODO rank

        Matrix operator+(const Matrix& other);
        Matrix operator-(const Matrix& other);
        Matrix operator*(const Matrix& other);
        Matrix operator*(double scalar) noexcept;

        bool operator==(const Matrix& other) const;
        
        friend std::ostream& operator<<(std::ostream& os, const Matrix& M);
    };
}

#endif