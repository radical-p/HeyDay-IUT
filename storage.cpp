#include "storage.h"
storage1::~storage1()
{

}

            struct temp {
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

};

int storage1::getLevel(){return level;}
int storage1::getCapacity(){return capacity;}
int storage1::allMerchandises(){
return (numNail+numFleece+numEgg+numMilk+numShovel+numAlfalfa);
}
int storage1::addNail(int numAddedNail){
        if(numAddedNail+allMerchandises()<=capacity){
           numNail+=numAddedNail;


           return 1;

        }

       return 0;
    }
int storage1::addAlfalfa(int numAddedAlfalfa){
        if(numAddedAlfalfa+allMerchandises()<=capacity){

    numAlfalfa+=numAddedAlfalfa;


    return 1;

        }
return 0;

    }
int storage1::addShovel(int numAddedShovel){
      if(numAddedShovel+allMerchandises()<=capacity){
            numShovel+=numAddedShovel;
      

return 1;

}
return 0;
    }
int storage1::addEgg(int numAddedEgg){
    if(numAddedEgg+allMerchandises()<=capacity){
//    if(level>=2){
    numEgg+=numAddedEgg;


    return 1;
//    }
    }
return 0;



    }
int storage1::addMilk(int numAddedMilk){
      if(numAddedMilk+allMerchandises()<=capacity){

//  if(level>=4){
    numMilk+=numAddedMilk;
   

    return 1;
//  }

      }
return 0;
}
int storage1::addFleece(int numAddedFleece){
      if(numAddedFleece+allMerchandises()<=capacity){

//  if(level>=6){
    numFleece+=numAddedFleece;

    return 1;
//  }

      }
return 0;
}


storage1::storage1(int _shenaseP){

 temp A;

  std::ifstream fin;
  std::ofstream fout;
  fin.open("storage.txt");
    if (!fin) { // if fin is empty
    fin.close();
    fout.open("storage.txt");
    fout.close();
//    fin.open("storage.txt", std::ios::app);
    fin.open("storage.txt", std::ios::in);

    }
  bool isFirst = 1;
////////////////////////////////////////
  fin.seekg(0,std::ios::end);
    int size=fin.tellg();
    fin.seekg(0,std::ios::beg);
   while (size>fin.tellg()) {
 ///////////////////////////////////////
// while (!fin.eof()) {
    fin.read((char*)&A, sizeof(temp));
    if (A.shenaseP == _shenaseP) {
            //////////////
            capacity=A.capacity;
            level=A.level;
            numNail=A.numNail;
            numAlfalfa=A.numAlfalfa;
            numShovel=A.numShovel;
            numEgg=A.numEgg;
            numMilk=A.numMilk;
            numFleece=A.numFleece;
            upgradeStartTime=A.upgradeStartTime;
            isBeingUpgraded=A.isBeingUpgraded;
            shenaseP=A.shenaseP;
            isFirst=0;
      break;
    }
  }

 if (isFirst) {    //first login
    capacity=5;
    level=1;
    numNail=1;
    numAlfalfa=1 ;
    numShovel=0;
    numEgg=0; // level 2
    numMilk=0; // level 4
    numFleece=0; // level 6
    upgradeStartTime=0;
    isBeingUpgraded=0;
    shenaseP=_shenaseP;
//....................................
    A.capacity=5;
    A.level=1;
    A.numNail=1;
    A.numAlfalfa=1 ;
    A.numShovel=0;
    A.numEgg=0; // level 2
    A.numMilk=0; // level 4
    A.numFleece=0; // level 6
    A.upgradeStartTime=0;
    A.isBeingUpgraded=0;
    A.shenaseP=_shenaseP;

    fout.open("storage.txt",std::ios::app);
    fout.write((char*)&A, sizeof(temp));
    fout.close();

  }


}


void storage1::update_file() {

    temp p;

    std::ofstream outfile;//for writing in new file.
    std::ifstream infile;//for reading.

    infile.open("storage.txt", std::ios::in);
    if (infile.is_open()) {
        outfile.open("storage-temp.txt", std::ios::out);//make file.
        infile.seekg(0, std::ios::end);
        int size = infile.tellg();
        infile.seekg(0, std::ios_base::beg);
        while (infile.tellg() < size) {
            infile.read((char*)&p, sizeof(p));
            if (shenaseP == p.shenaseP) {
p.capacity=capacity;
p.level=level;
     p.numNail=numNail;
    p.numAlfalfa=numAlfalfa ;
    p.numShovel=numShovel ;
    p.numEgg=numEgg; // level 2
     p.numMilk=numMilk; // level 4
     p.numFleece=numFleece; // level 6
    p.upgradeStartTime=upgradeStartTime;
     p.isBeingUpgraded=isBeingUpgraded;
    p.shenaseP=shenaseP;
            }
            outfile.write((char*)&p, sizeof(p));
        }
        outfile.close();
        infile.close();
        remove("storage.txt");
        rename("storage-temp.txt", "storage.txt");
    }
}


    int storage1::getNail(){return numNail;}
    int storage1::getAlfalfa(){return numAlfalfa;}
    int storage1::getShovel(){return numShovel;}
    int storage1::getEgg(){return numEgg;}
    int storage1::getMilk(){return numMilk;}
    int storage1::getFleece(){return numFleece;}
