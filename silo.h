#ifndef SILO_H
#define SILO_H
#include "iostream"
#include "fstream"
class silo{
int capacity;
int numWheat;
int level;
unsigned int upgradeStartTime;
bool isBeingUpgraded;
int shenaseP;
public:
    //constructor
    silo(int shenaseP=1);
    int getCapaticy();
    int getNumWheat();
    int getLevel();
    int addWheat(int addedWheatNumber);
//    void checkForUpgrade();
    bool isFull();
    friend class storage;
    friend class alfalfaField;
    friend class DialogSilo;
    void update_file();

};

#endif // SILO_H
