#ifndef WHEATLAND_BACK_H
#define WHEATLAND_BACK_H
#include <fstream>


class wheatland_back
{
public:
    wheatland_back(int _id = 1);
    ~wheatland_back(){};
    void keshtUpDate(int);
    int kesht(int);
    int bardasht();
    int upGrade(int);
    int getIsKeshting(){return isKeshting;};
    int getKeshtStartDay(){return startDay;};
    int getArea(){return area;};
    int getAmount(){return keshtAmount;};
    int getIsUpgrading(){return isUpgrading;};
    int getStartDayUpgrading(){return startDayUpgrading;};
    void setIsKeshting(int _isKeshting){isKeshting = _isKeshting;};
    void setKeshtAmount(int _keshtAmount){keshtAmount = _keshtAmount;};
    void setArea(int _area){area = _area;};
    void setStartDay(int _startDay){startDay = _startDay;};
    void setIsUpgrading(int _setIsUpgrading){isUpgrading = _setIsUpgrading;};
    void setStartDayUpgrading(int _startDayUpgrading){ startDayUpgrading = _startDayUpgrading;};
    void upDateFile();

private:
    int area;
    bool isKeshting;
    int keshtAmount;
    int startDay;
    int id;
    bool isUpgrading;
    int startDayUpgrading;
};

#endif // WHEATLAND_BACK_H
