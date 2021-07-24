#ifndef ALFALFAFIELD_H
#define ALFALFAFIELD_H
#include <fstream>
#include <stdbool.h>
class alfalfaField{ // opens in level 3

int area;
bool isPlowed;
unsigned int plowStartTime;
unsigned int upgradeStartTime;
unsigned int plantStartTime;
unsigned int buildStartTime;
bool isBeingUpgraded;
bool isBeingPlowed;
bool isBeingPlanted;
bool isBuilt;
bool isBeingBuilt;
int shenaseP;
int plantedArea;
public:
//constructor
alfalfaField(int _shenaseP=1);
//functions
int getArea();
void update_file();

friend class storage;
friend class silo;
friend class DialogAlfalfaField;
};

#endif // ALFALFAFIELD_H
