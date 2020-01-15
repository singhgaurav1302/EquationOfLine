#include <iostream>
#include "LineEquationSolver.h"

int main()
{
    LineEquationSolver<int, int> eq(2, 3, 6, 7);
    std::cout << "Value of Y for X = 8: " << eq.getY(8) << std::endl;
}
