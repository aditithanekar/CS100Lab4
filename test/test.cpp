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


using awards::RankList;
using awards::AwardCeremonyActions;


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

