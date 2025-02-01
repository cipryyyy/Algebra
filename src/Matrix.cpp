#include "Matrix.h"

//! PRIVATE
Algebra::Matrix Algebra::Matrix::subMatrix(int rCut, int cCut) const {
    if (rCut < 0 || rCut >= rows) throw MatrixIndexOutOfBound();
    if (cCut < 0 || cCut >= cols) throw MatrixIndexOutOfBound();
    Matrix sub(rows-1, cols-1);
    for (int r = 0; r < rows-1; r++) {
        for (int c = 0; c < cols-1; c++) {
            if (r < rCut) {
                if (c < cCut) {
                    sub.set(r,c, get(r,c));
                } else {
                    sub.set(r,c, get(r,c+1));
                }
            } else {
                if (c < cCut) {
                    sub.set(r,c, get(r+1,c));
                } else {
                    sub.set(r,c, get(r+1,c+1));
                }
            }
        }
    }
    return sub;
}

//! CONSTRUCTORS, MOVE, COPY AND DESTROYER
Algebra::Matrix::Matrix(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this -> data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        this -> data[i] = new double [cols];
    }
}
Algebra::Matrix::Matrix(int rows, int cols, std::initializer_list<double> list) {
    this->rows = rows;
    this->cols = cols;
    this->data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        this->data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            this->data[i][j] = *(list.begin() + i * cols + j);
        }
    }
}
Algebra::Matrix::Matrix(const Matrix& other) {
    rows = other.rows;
    cols = other.cols;
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }
}
Algebra::Matrix::Matrix(Matrix&& other) {
    rows = other.rows;
    cols = other.cols;
    for (int i = 0; i < rows; i++) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; j++) {
            data[i][j] = other.data[i][j];
        }
    }

    other.rows = 0;
    other.cols = 0;
    for (int i = 0; i < rows; i++) {
        delete[] other.data[i];
        other.data[i] = nullptr;
    }
    delete[] other.data;
    other.data = nullptr;
}
Algebra::Matrix& Algebra::Matrix::operator= (const Matrix& other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }

    return *this;
}
Algebra::Matrix& Algebra::Matrix::operator= (Matrix&& other) {
    if (this == &other) {
        return *this;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] data[i];
    }
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = new double*[rows];
    for (int i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
    
    other.data = nullptr;
    other.rows = 0;
    other.cols = 0;

    return *this;
}
Algebra::Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
        data[i] = nullptr;
    }
    delete[] data;
    data = nullptr;
}

//! SETTER AND GETTER
void Algebra::Matrix::set(int r, int c, double val) {
    if (r < 0 || r >= rows) throw MatrixIndexOutOfBound();
    if (c < 0 || c >= cols) throw MatrixIndexOutOfBound();
    data[r][c] = val;
}
double& Algebra::Matrix::get(int r, int c) const {
    if (r < 0 || r >= rows) throw MatrixIndexOutOfBound();
    if (c < 0 || c >= cols) throw MatrixIndexOutOfBound();
    return data[r][c];
}

//! OPERATIONS
double Algebra::Matrix::determinant() const {
    if (rows != cols) throw MatrixNotSquare();
    if (rows == 0) throw NullMatrix();
    if (rows == 2) {
        return (data[0][0] * data[1][1] - data[1][0] * data[0][1]);
    }
    double val = 0;
    for (int i = 0; i < cols; i++) {
        val += (std::pow(-1, i) * data[0][i] * subMatrix(0, i).determinant());
    }
    return val;
}
Algebra::Matrix Algebra::Matrix::invert() const {
    if (rows != cols) throw MatrixNotSquare();
    if (rows == 0) throw NullMatrix();
    double det = determinant();
    if (det == 0) throw NullDeterminant();

    Matrix I(rows, cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            I.set(r,c, (std::pow(-1, r+c) * subMatrix(r,c).determinant())/det);
        }
    }
    I = I.transpose();
    return I;
}
Algebra::Matrix Algebra::Matrix::transpose() const {
    Matrix T(rows, cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            T.set(r,c, data[c][r]);
        }
    }
    return T;
}

//! OVERRIDES
Algebra::Matrix Algebra::Matrix::operator+(const Matrix& other) {
    if ((rows != other.rows) || (cols != other.cols)) throw NonCompatibleMatrixes();
    Matrix add(rows, cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            add.set(r, c, data[r][c] + other.data[r][c]);
        }
    }
    return add;
}
Algebra::Matrix Algebra::Matrix::operator-(const Matrix& other) {
    if ((rows != other.rows) || (cols != other.cols)) throw NonCompatibleMatrixes();
    Matrix sub(rows, cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            sub.set(r, c, data[r][c] - other.data[r][c]);
        }
    }
    return sub;
}
Algebra::Matrix Algebra::Matrix::operator*(const Matrix& other) {
    if (cols != other.rows) throw NonCompatibleMatrixes();
    Matrix Product(rows, other.cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < other.cols; c++) {
            double val = 0;
            for (int t = 0; t < cols; t++) {
                val += (data[r][t] * other.data[t][c]);
            }
            Product.set(r,c,val);
        }
    }
    return Product;
}
Algebra::Matrix Algebra::Matrix::operator*(double scalar) noexcept {
    Matrix Scalar(rows, cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            Scalar.set(r, c, data[r][c] * scalar);
        }
    }
    return Scalar;
}
bool Algebra::Matrix::operator==(const Matrix& other) const {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (data[r][c] != other.data[r][c]) return false;
        }
    }
    return true;
}

//! FRIENDS
namespace Algebra {
    std::ostream& operator<< (std::ostream& os, const Algebra::Matrix& M) {
        for (int i = 0; i < M.rows; i++) {
            for (int j = 0; j < M.cols; j++) {
                os << M.data[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }
}