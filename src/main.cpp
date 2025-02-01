#include <iostream>
#include "Algebra.h"        //Import the header
using namespace Algebra;    //Use the namespace
using std::cout;

int main() {
    cout << "ALGEBRA HEADER:\n\n";
    cout << "Sum of two Matrixes:\n";

    Matrix A(3,3,{2,3,4,9,8,7,4,5,6});
    Matrix B(3,3,{3,4,5,1,2,3,7,5,2});

    cout << "A:\n" << A << "B:\n" << B << "Sum:\n" << A+B;


    return 0;
}