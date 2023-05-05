#include "gtest/gtest.h"
#include "../include/Awards.h"
#include <vector>
#include <string>

using awards::RankList;
using awards::AwardCeremonyActions;

class AwardeeList:public RankList
{
    public:
        string peopleList["Khushi", "Aditi", "Rose", "Sarah"];


    private:
        std::string getNext();
        int whichPersonIndex=0; 

}
string awards::AwardeeList::getNext()
{
    if(whichPersonIndex<=3)
    {
        return peopleList[whichPersonIndex];
        whichPersonIndex++;
    }
    return "";
   
}