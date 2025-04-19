#include "QuadraticEquation.h"

#include <gtest/gtest.h>

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


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    auto result = RUN_ALL_TESTS();

    return result;
}
