#include "gtest/gtest.h"
#include "../include/Hailstone.h"


using sequence::satisfiesHailstone;

TEST(HailstoneTests, satisfyHailstoneZeroFalse)
{
    bool result = sequence::satisfiesHailstone(0);
    EXPECT_FALSE(result);
}
TEST(HailstoneTests, satisfyHailstoneOne)
{
    bool result = sequence::satisfiesHailstone(1);
    EXPECT_TRUE(result);
}
TEST(HailstoneTests, satisfyHailstoneEven)
{
    bool result = sequence::satisfiesHailstone(28);
    EXPECT_TRUE(result);
}
TEST(HailstoneTests, satisfyHailstoneOdd)
{
    bool result = sequence::satisfiesHailstone(7);
    EXPECT_TRUE(result);
}
