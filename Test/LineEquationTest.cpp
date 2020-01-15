#include <gtest/gtest.h>

#include "LineEquationSolver.h"

TEST(LineEquationTest, LinePassingThroughAxisGetYForXAs3)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(3, eq.getY(3));
}

TEST(LineEquationTest, LinePassingThroughAxisGetYForXAs1)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(1, eq.getY(1));
}

TEST(LineEquationTest, LinePassingThroughAxisGetYForXAs5)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(5, eq.getY(5));
}

TEST(LineEquationTest, LinePassingThroughAxisGetYForXAs0)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(0, eq.getY(0));
}

TEST(LineEquationTest, LinePassingThroughAxisGetYForXAs9)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(9, eq.getY(9));
}

TEST(LineEquationTest, LinePassingThroughAxisGetYForXAsNeg9)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(-9, eq.getY(-9));
}
