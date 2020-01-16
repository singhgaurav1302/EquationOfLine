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

TEST(LineEquationTest, LineEquationGetYForXAsChar)
{
    LineEquationSolver<int, int> eq(1, 4, 5, 10);
    EXPECT_DOUBLE_EQ(148, eq.getY('a'));
}

TEST(LineEquationTest, LineEquationGetYForXAsString)
{
    LineEquationSolver<int, int> eq(1, 4, 5, 10);
//    eq.getY("string");
}

TEST(LineEquationTest, LineEquationInstantiationWithNonArithmeticType)
{
    std::string y1 = "5";
    std::string y2 = "10";
//    LineEquationSolver<int, std::string> eq(1, y1, 5, y2);
}

TEST(LineEquationTest, LineEquationGetYForX_DataTypeDouble)
{
    LineEquationSolver<double, double> eq(1.4, 4.3, 5.23, 1000.6);
    EXPECT_NEAR(9108.86, eq.getY(36.4), 0.01);
}

TEST(LineEquationTest, LineEquationGetYForX_DataTypeShort)
{
    LineEquationSolver<short, short> eq(1, 4, 5, 10);
    EXPECT_DOUBLE_EQ(146.5, eq.getY(96));
}

TEST(LineEquationTest, LineEquationGetYForX_DataTypeLong)
{
    LineEquationSolver<long, long> eq(1L, 4L, 5L, 10L);
    EXPECT_DOUBLE_EQ(146.5, eq.getY(96));
}

TEST(LineEquationTest, LineEquationGetYForX_DataTypeBool)
{
    LineEquationSolver<bool, bool> eq(false, false, true, true);
    EXPECT_DOUBLE_EQ(6, eq.getY(6));
}

TEST(LineEquationTest, LineEquationGetYForX_DataTypeRandom)
{
    LineEquationSolver<unsigned int, long long> eq(1, 8, 3, -9L);
    EXPECT_DOUBLE_EQ(-34.5, eq.getY(6));
}
