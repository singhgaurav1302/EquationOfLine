#include <gtest/gtest.h>

#include "LineEquationSolver.h"

TEST(LineEquationTest, LineEquationSolverGetY)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(3, eq.getY(3));
}
