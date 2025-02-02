#include <iostream>
#include "Algebra.h"        //Import the header
using namespace Algebra;    //Use the namespace
using std::cout;

int main() {
    Matrix A(3,3,{2,4,-2,1,3,-2,3,8,-5});

    cout << A;
    cout << "\nRANK: " << A.rank();

    return 0;
}