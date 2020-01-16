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

TEST(LineEquationTest, LineEquationGetYForXChar)
{
    LineEquationSolver<int, int> eq(1, 4, 5, 10);
    EXPECT_DOUBLE_EQ(148, eq.getY('a'));
}

TEST(LineEquationTest, LineEquationGetYForXAsString)
{
    LineEquationSolver<int, int> eq(1, 4, 5, 10);
    eq.getY("string");
}

TEST(LineEquationTest, LineEquationInstantiationWithNonArithmeticType)
{
    std::string y1 = "5";
    std::string y2 = "10";
    LineEquationSolver<int, std::string> eq(1, y1, 5, y2);
}


