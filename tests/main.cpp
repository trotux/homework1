#include "QuadraticEquation.h"

#include <gtest/gtest.h>

#include <cmath>
#include <string>

TEST(QE, Case_1_0_1)
{
    auto roots = QuadraticEquation::solve(1, 0, 1);

    EXPECT_EQ(roots.size(), 0);
}

TEST(QE, Case_1_0_n1)
{
    auto roots = QuadraticEquation::solve(1, 0, -1);

    EXPECT_EQ(roots.size(), 2);
    EXPECT_DOUBLE_EQ(roots[0], 1);
    EXPECT_DOUBLE_EQ(roots[1], -1);
}

TEST(QE, Case_1_2_1)
{
    auto roots = QuadraticEquation::solve(1, 2, 1);

    EXPECT_EQ(roots.size(), 2);
    EXPECT_DOUBLE_EQ(roots[0], roots[1]);
    EXPECT_DOUBLE_EQ(roots[1], -1);
}

TEST(QE, Case_0_2_1)
{
    EXPECT_ANY_THROW(auto roots = QuadraticEquation::solve(0, 2, 1));
}

TEST(QE, Case_1_2_09999)
{
    auto roots = QuadraticEquation::solve(1, 2, 0.9999);

    EXPECT_EQ(roots.size(), 2);
    EXPECT_DOUBLE_EQ(roots[0], roots[1]);
    EXPECT_DOUBLE_EQ(roots[1], -1);
}

TEST(QE, Case_Bad_values)
{
    double a{1};
    double b{2};
    double c{1};

    a = std::numeric_limits<double>::infinity();
    EXPECT_ANY_THROW(auto roots = QuadraticEquation::solve(a, b, c));
    a = std::nan("NaN");
    EXPECT_ANY_THROW(auto roots = QuadraticEquation::solve(a, b, c));

    a = 1;
    b = std::numeric_limits<double>::infinity();
    EXPECT_ANY_THROW(auto roots = QuadraticEquation::solve(a, b, c));
    b = std::nan("NaN");
    EXPECT_ANY_THROW(auto roots = QuadraticEquation::solve(a, b, c));

    b = 1;
    c = std::numeric_limits<double>::infinity();
    EXPECT_ANY_THROW(auto roots = QuadraticEquation::solve(a, b, c));
    c = std::nan("NaN");
    EXPECT_ANY_THROW(auto roots = QuadraticEquation::solve(a, b, c));
}



int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    auto result = RUN_ALL_TESTS();

    return result;
}
