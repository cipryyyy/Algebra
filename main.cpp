#include <iostream>
#include "Algebra.h"        //Import the header
using namespace Algebra;    //Use the namespace
using std::cout;

int main() {
    Vector v = {1,2,3};
    Matrix F(3,3, {0,0,1,0,1,0,1,0,0});
    cout << (F*v);
}