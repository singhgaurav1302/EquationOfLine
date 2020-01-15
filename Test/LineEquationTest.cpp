#include <gtest/gtest.h>

#include "LineEquationSolver.h"

TEST(LineEquationTest, LinePassingThroughAxisGetYForX)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 5);
    EXPECT_DOUBLE_EQ(3, eq.getY(3));
    EXPECT_DOUBLE_EQ(1, eq.getY(1));
    EXPECT_DOUBLE_EQ(5, eq.getY(5));
    EXPECT_DOUBLE_EQ(0, eq.getY(0));
    EXPECT_DOUBLE_EQ(9, eq.getY(9));
    EXPECT_DOUBLE_EQ(-9, eq.getY(-9));
}

TEST(LineEquationTest, LineParallelToXAxisGetY)
{
    LineEquationSolver<int, int> eq(1, 1, 5, 1);
    EXPECT_DOUBLE_EQ(1, eq.getY(-99999999));
}

TEST(LineEquationTest, LineParallelToYAxisGetY)
{
    LineEquationSolver<int, int> eq(2, 1, 2, 6);
    EXPECT_DOUBLE_EQ(std::numeric_limits<long double>::infinity(), eq.getY(2));
}
