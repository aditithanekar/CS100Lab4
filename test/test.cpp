#include "gtest/gtest.h"
#include "../include/Hailstone.h"
#include "../include/Awards.h"
#include <string>
#include "gmock/gmock.h"

using namespace std;
using sequence::satisfiesHailstone;



using awards::RankList;
using awards::AwardCeremonyActions;

class AwardeeList:public RankList
{
    public:
        string peopleList[4] = {"Khushi", "Aditi", "Rose", "Sarah"};


    private:
        int whichPersonIndex=0; 
        string getNext()
        {
            if(whichPersonIndex<=3)
            {
                return peopleList[whichPersonIndex];
                whichPersonIndex++;
            }
            return "";
        }
        

};
//mock class for award ceremony
class MockAwardCeremonyActions:public AwardCeremonyActions
{
    public: 
        MOCK_METHOD(void, playAnthem, (), (override));
        MOCK_METHOD(void, turnOffTheLightsAndGoHome, (), (override));
        MOCK_METHOD(void, awardBronze, (std::string recipient), (override));
        MOCK_METHOD(void, awardSilver, (std::string recipient), (override));
        MOCK_METHOD(void, awardGold, (std::string recipient), (override));
};


