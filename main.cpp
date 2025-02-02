#include <iostream>
#include "Algebra.h"        //Import the header
#include "Equation.h"
using namespace Algebra;    //Use the namespace
using std::cout;

int main() {
    Equation e1 = {2,2,2};
    Equation e2 = {2,2,2,2};
    cout << "Equal " << (e1 == e2? "True" : "False") << "\n";
    cout << "Ineq " << (e1 != e2? "True" : "False") << "\n";
    cout << "Mag " << (e1 > e2? "True" : "False") << "\n";
    cout << "Min " << (e1 < e2? "True" : "False") << "\n";
    cout << "Meq " << (e1 >= e2? "True" : "False") << "\n";
    cout << "meq " << (e1 <= e2? "True" : "False") << "\n";
}