#include <time.h>
#include <iostream>
#include <math.h>
#include <stdbool.h>
#include <fstream>
#pragma once
//using namespace std;

class storage1{

private:
    int capacity;
    int level;
    int numNail;
    int numAlfalfa ;
    int numShovel ;
    int numEgg; // level 2
    int numMilk; // level 4
    int numFleece; // level 6
    unsigned int upgradeStartTime;
    bool isBeingUpgraded;
int shenaseP;

public:
storage1(int shenase);
~storage1();
    int getLevel();
    int getCapacity();
    int getNail();
    int getAlfalfa();
    int getShovel();
    int getEgg();
    int getMilk();
    int getFleece();
    int allMerchandises();
    int addNail(int numAddedNail);
    int addAlfalfa(int numAddedAlfalfa);
    int addShovel(int numAddedShovel);
    int addEgg(int numAddedEgg);
    int addMilk(int numAddedMilk);
    int addFleece(int numAddedFleece);
    void setLevel(int _level){level=_level;}
    void setCapacity(int _capacity){capacity=_capacity;}
    void setNail(int _nail){numNail=_nail;}
    void setAlfalfa(int _alfalfa){numAlfalfa=_alfalfa;}
    void setShovel(int _shovel){numShovel=_shovel;}
    void setEgg(int _egg){numEgg=_egg;}
    void setMilk(int _milk){numMilk=_milk;}
    void setFleece(int _fleece){numFleece=_fleece;}
void update_file();

friend class DialogStorage;
};
