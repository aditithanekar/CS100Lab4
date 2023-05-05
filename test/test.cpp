using namespace std;
#include <vector>
#include "gtest/gtest.h"
#include "../include/Hailstone.h"
#include "../include/Awards.h"
#include <string>
#include "gmock/gmock.h"
#include <iostream>
using ::testing::AtLeast;

using sequence::satisfiesHailstone;
using std::vector;
using sequence::satisfiesHailstone;

using awards::RankList;
using awards::AwardCeremonyActions;

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

class AwardeeList:public RankList
{
    public:
        unsigned int whichPersonIndex=0;
        string peopleList[5] = {" ", "Khushi", "Aditi", "Rose", "Sarah"}; 

        string getNext()
        {
            whichPersonIndex++;
            if(whichPersonIndex<=3)
            {
                return peopleList[whichPersonIndex];
                
            }
            return "";
        }
};

//mock class for award ceremony
class MockAwardCeremonyActions:public AwardCeremonyActions
{
    public: 
        //void performAwardCeremony(RankList& recipients, AwardCeremonyActions& actions);
        MOCK_METHOD(void, playAnthem, (), (override));
        MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
        MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
        MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
        MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};

TEST(AwardsTests, TestPerformAwardsCeremony)
{
    MockAwardCeremonyActions actionToDo;
    AwardeeList awardRecipients;

    EXPECT_CALL(actionToDo, playAnthem())
        .Times(1);

    EXPECT_CALL(actionToDo, awardBronze("Khushi"))
        .Times(1);
    EXPECT_CALL(actionToDo, awardSilver("Aditi"))
        .Times(1);

    EXPECT_CALL(actionToDo, awardGold("Rose"))
        .Times(1);
    
    EXPECT_CALL(actionToDo, turnOffTheLightsAndGoHome())
        .Times(1);    

    performAwardCeremony(awardRecipients, actionToDo);
}

