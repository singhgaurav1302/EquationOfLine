#include <gtest/gtest.h>

#include "LineEquationSolver.h"

TEST(LineEquationTest, GoogleTestSetup)
{
}

TEST(LineEquationTest, LineEquationSolver)
{
    LineEquationSolver<int, int> eq(1, 2, 3, 4);
}

TEST(LineEquationTest, LineEquationSolverGetY)
{
    LineEquationSolver<int, int> eq(1, 2, 5, 6);
    eq.getY(3);
}
