#ifndef SPACE_H
#define SPACE_H

#include <initializer_list>
//#include "Equation.h"

namespace Algebra {
    class Space {
    private:
        int dim;
    public:
        Space(int dimension) : dim{dimension} {}

        int getDimension() const;
    };
}
#endif