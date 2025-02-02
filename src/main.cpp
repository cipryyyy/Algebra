#include <iostream>
#include "Algebra.h"        //Import the header
using namespace Algebra;    //Use the namespace
using std::cout;

int main() {
    cout << "ALGEBRA HEADER:\n\n";
    cout << "Sum of two Matrixes:\n";

    Matrix A(3,3,{1,2,3,1,2,3,4,9,6});

    cout << A;
    cout << "\nRANK: " <<A.rank();


    return 0;
}