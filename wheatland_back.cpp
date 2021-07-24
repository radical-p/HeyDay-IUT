#include "wheatland_back.h"

int tmpIdWh = 1, tmpAreaWh = 5, tmpIsKeshtingWh = 0, tmpAmountKeshtingWh = 0, tmpdayWh = 0, startDayFarmingWh = 0, tmpisUpGrading = 0, tmpStartDayUpgrading = 0;

wheatland_back::wheatland_back(int _id)
{

    //seting id of wheatland
    id = _id;


    int flag = 0;


    std::ifstream wheat("wheat.txt");
    std::ofstream wheat2("wheat2.txt");
   /* if ( wheat.peek() == std::ifstream::traits_type::eof() )
    {
         //file is empty
         flag = 1;
         wheat2 << id << ' ' << tmpAreaWh << ' ' << tmpIsKeshtingWh<< ' ' << tmpAmountKeshtingWh<< ' ' << startDayFarmingWh << ' ' << tmpisUpGrading << ' ' << tmpStartDayUpgrading <<'\n';
         area = tmpAreaWh;
         isKeshting = true;
         keshtAmount = 0;
         startDayFarmingWh = 0;
         wheat2.close();
         wheat.close();
         remove("wheat.txt");
         rename("wheat2.txt", "wheat.txt");
    }
    else {*/
       //file is not empty
       while (wheat >> tmpIdWh >> tmpAreaWh >> tmpIsKeshtingWh >> tmpAmountKeshtingWh >> startDayFarmingWh >> tmpisUpGrading >> tmpStartDayUpgrading )
        {
            if (tmpIdWh == id)
            {
                flag = 1;
                area = tmpAreaWh;
                isKeshting = tmpIsKeshtingWh;
                keshtAmount = tmpAmountKeshtingWh;
                startDay = startDayFarmingWh;
                isUpgrading = tmpisUpGrading;
                startDayUpgrading = tmpStartDayUpgrading;
                break;
            }
       }
       wheat.close();
       wheat2.close();
       remove("wheat2.txt");
    //}


    //Add new user
    if(flag == 0){
        std::ifstream wheatAddUser("wheat.txt");
        std::ofstream wheatAddUserTmp("wheat2.txt");
        while (wheatAddUser >> tmpIdWh >> tmpAreaWh >> tmpIsKeshtingWh >> tmpAmountKeshtingWh >> startDayFarmingWh >> tmpisUpGrading >> tmpStartDayUpgrading)
         {
             wheatAddUserTmp << tmpIdWh << ' ' << tmpAreaWh << ' '  << tmpIsKeshtingWh << ' ' << tmpAmountKeshtingWh << ' ' << startDayFarmingWh << ' ' << tmpisUpGrading << ' ' << tmpStartDayUpgrading <<'\n';
         }
        wheatAddUserTmp << _id << ' ' << 5 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 0 << '\n';
        area = 5;
        isKeshting = 0;
        keshtAmount = 0;
        startDay = 0;
        isUpgrading = 0;
        startDayUpgrading = 0;
        wheatAddUser.close();
        wheatAddUserTmp.close();
        remove("wheat.txt");
        rename("wheat2.txt", "wheat.txt");
    }

}

int wheatland_back::upGrade(int _startDay)
{

    int flag = 0;

    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheat.txt");
    int tmpId2 = 1, tmpArea2 = 5, tmpIsKeshting2 = 0, tmpAmountKeshting2 = 0 ,startDayFarming2 = 0, tmpIsUpgarding2 = 0, tmpStartDayUpgrading2 = 0;
   /* if ( wheat.peek() == std::ifstream::traits_type::eof() )
    {
         //file is empty
           flag = 1;
           isUpgrading = 1;
           startDayUpgrading = _startDay;
           temp << id << ' ' << area << ' ' << isUpgrading << ' ' << _startDay << '\n';
           temp.close();
           wheat.close();
           remove("wheatlandUpgrade.txt");
           rename("temp.txt", "wheatlandUpgrade.txt");
    }
    else
    {*/
    while (wheat >> tmpId2 >> tmpArea2 >> tmpIsKeshting2 >> tmpAmountKeshting2 >> startDayFarming2 >> tmpIsUpgarding2 >> tmpStartDayUpgrading2 )
    {
        if (id == tmpId2)
        {
            flag = 1;
            if(isUpgrading == 1)
                return 0;
            tmpIsUpgarding2 = true;
            isUpgrading = true;
            tmpStartDayUpgrading2 = _startDay;
            startDayUpgrading = _startDay;
        }
        temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsKeshting2 << ' ' << tmpAmountKeshting2 << ' ' << startDayFarming2 << ' ' <<tmpIsUpgarding2 << ' ' << tmpStartDayUpgrading2 << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheat.txt");
    rename("temp.txt", "wheat.txt");
   // }

    //add new upgrade
    if( flag == 0 ){
        std::ifstream wheatAddUpgrade("wheat.txt");
        std::ofstream wheat2AddUpgrade("temp.txt");
        while (wheat >> tmpId2 >> tmpArea2 >> tmpIsKeshting2 >> tmpAmountKeshting2 >> startDayFarming2 >> tmpIsUpgarding2 >> tmpStartDayUpgrading2  )
         {
             temp << tmpId2 << ' ' << tmpArea2 << ' ' << tmpIsKeshting2 << ' ' << tmpAmountKeshting2 << ' ' << startDayFarming2 << ' ' <<tmpIsUpgarding2 << ' ' << tmpStartDayUpgrading2 << '\n';
         }
        wheat2AddUpgrade << id << ' ' << 5 << ' ' << 0 << ' ' << 0 << ' ' << 0 << ' ' << 1 << ' ' << _startDay << '\n';
        wheatAddUpgrade.close();
        wheat2AddUpgrade.close();
        remove("wheat.txt");
        rename("temp.txt", "wheat.txt");

        isUpgrading = true;
        startDayUpgrading = _startDay;

    }


    isUpgrading = true;
    startDayUpgrading = _startDay;
    return 1;


}

void wheatland_back::upDateFile()
{
    std::ofstream temp("temp.txt");
    std::ifstream wheat("wheat.txt");
    int tmpId3 = 1, tmpArea3 = 5, tmpIsKeshting3 = 0, tmpAmountKeshting3 = 0 ,startDayFarming3 = 0, tmpIsUpgarding3 = 0, tmpStartDayUpgrading3 = 0;
    while (wheat >> tmpId3 >> tmpArea3 >> tmpIsKeshting3 >> tmpAmountKeshting3 >> startDayFarming3 >> tmpIsUpgarding3 >> tmpStartDayUpgrading3)
    {
        if (id == tmpId3)
        {
            tmpArea3 = area;
            tmpIsKeshting3 = isKeshting;
            tmpAmountKeshting3 = keshtAmount;
            startDayFarming3 = startDay;
            tmpIsUpgarding3 = isUpgrading;
            tmpStartDayUpgrading3 = startDayUpgrading;
        }
        temp << tmpId3 << ' ' << tmpArea3 << ' ' << tmpIsKeshting3 << ' ' << tmpAmountKeshting3 << ' ' << startDayFarming3 << ' ' <<tmpIsUpgarding3 << ' ' << tmpStartDayUpgrading3 << '\n';
    }
    temp.close();
    wheat.close();
    remove("wheat.txt");
    rename("temp.txt", "wheat.txt");
}
