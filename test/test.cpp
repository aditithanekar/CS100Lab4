#include "gtest/gtest.h"
#include "../include/Hailstone.h"
#include "../include/Triangle.h"
using sequence::satisfiesHailstone;
using namespace shapes;

// not working
TEST(TriangleTests, testPerimeter) {
    Triangle *aTriangle = new Triangle(4,3,4);
    EXPECT_EQ (aTriangle->getPerimeter(),11);
}

TEST(TriangleTests, testArea){
    Triangle *newTriangle = new Triangle(7,6,7);
    EXPECT_NEAR(newTriangle->getArea(), 18.97, 0.01);
}

TEST(TriangleTests, testTypes){
    Triangle *newTriangle = new Triangle(6,6,6);
    EXPECT_EQ(newTriangle->getKind(), Triangle::Kind::EQUILATERAL);
}

// expect death
TEST(TriangleTests, invalidInput){
    EXPECT_DEATH(new Triangle(2,1,5), "First side is not the longest");
}

//working
TEST(TriangleTests, validInput){
    Triangle *newTriangle = new Triangle(4,3,2);
    EXPECT_NO_THROW(newTriangle);
}

TEST(TriangleTests, perimeterCheck){
    Triangle *newTriangle = new Triangle(3,3,3);
    EXPECT_EQ(newTriangle->getPerimeter(), 9);
}

TEST(TriangleTests, areaCheck){
    Triangle *newTriangle = new Triangle(4,4,4);
    EXPECT_NEAR(newTriangle->getArea(), 6.93, 0.01);
}

TEST(TriangleTests, typeCheck){
    Triangle *newTriangle = new Triangle(5,5,3);
    EXPECT_EQ(newTriangle->getKind(), Triangle::Kind::ISOSCELES);
}


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
