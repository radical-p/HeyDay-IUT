#include "alfalfaField.h"

        struct temp {
int area;
int plantedArea;
bool isPlowed;
unsigned int plowStartTime;
unsigned int upgradeStartTime;
unsigned int plantStartTime;
unsigned int buildStartTime;
bool isBuilt;
bool isBeingUpgraded;
bool isBeingPlowed;
bool isBeingPlanted;
bool isBeingBuilt;
int shenaseP;
};

//constructor
alfalfaField::alfalfaField(int _shenaseP){

  temp A;

  std::ifstream fin;
  std::ofstream fout;
  fin.open("alfalfaField.txt");
  if (!fin) { // if fin is empty
    fin.close();
    fout.open("alfalfaField.txt");
    fout.close();
    fin.open("alfalfaField.txt", std::ios::in);
  }
  bool isFirst = 1;
  //////////////////////
  fin.seekg(0,std::ios::end);
    int size=fin.tellg();
    fin.seekg(0,std::ios::beg);
   while (size>fin.tellg()) {
   /////////////////////
       //  while (!fin.eof()) {/////////////////////taghir dar hame
    fin.read((char*)&A, sizeof(temp));
    if (A.shenaseP == _shenaseP) {
area=A.area;
isPlowed=A.isPlowed;
 plowStartTime=A.plowStartTime;
 upgradeStartTime=A.upgradeStartTime;
 plantStartTime=A.plantStartTime;
 isBeingUpgraded=A.isBeingUpgraded;
 isBeingPlowed=A.isBeingPlowed;
 isBeingPlanted=A.isBeingPlanted;
 plantedArea=A.plantedArea;
 isBuilt=A.isBuilt;
 buildStartTime=A.buildStartTime;
 isBeingBuilt=A.isBeingBuilt;
shenaseP=A.shenaseP;
            isFirst=0;
      break;
    }
  }
  fin.close();
  if (isFirst) {    //first login
area=4;
isPlowed=0;
 plowStartTime=0;
 upgradeStartTime=0;
 plantStartTime=0;  //
 isBeingUpgraded=0;
 isBeingPlowed=0;
 isBeingPlanted=0;
 plantedArea=0;
 isBuilt=0;
 buildStartTime=0;
 isBeingBuilt=0;
 shenaseP=_shenaseP;
    //..................
A.area=4;
A.isPlowed=0;
A.plowStartTime=0;
A.upgradeStartTime=0;
A.plantStartTime=0; //
A.isBeingUpgraded=0;
A.isBeingPlowed=0;
A.isBeingPlanted=0;
A.plantedArea=0;
A.isBuilt=0;
A.buildStartTime=0;
A.isBeingBuilt=0;
////////////////////////
A.shenaseP=_shenaseP; //////////
////////////////////////
    fout.open("alfalfaField.txt",std::ios::app);
    fout.write((char*)&A, sizeof(temp));
    fout.close();
  }

    }
//functions
int alfalfaField::getArea(){return area;}

    

void alfalfaField::update_file() {

	temp p;

    std::ofstream outfile;//for writing in new file.
    std::ifstream infile;//for reading.

    infile.open("alfalfaField.txt", std::ios::in);
	if (infile.is_open()) {
        outfile.open("alfalfaField-temp.txt", std::ios::out);//make file.
        infile.seekg(0, std::ios::end);
		int size = infile.tellg();
        infile.seekg(0, std::ios_base::beg);
		while (infile.tellg() < size) {
			infile.read((char*)&p, sizeof(p));
			if (shenaseP == p.shenaseP) {
 p.area=area;
 p.isPlowed=isPlowed;
 p.plowStartTime=plowStartTime;
 p.upgradeStartTime=upgradeStartTime;
 p.plantStartTime=plantStartTime;
 p.isBeingUpgraded=isBeingUpgraded;
 p.isBeingPlowed=isBeingPlowed;
 p.isBeingPlanted=isBeingPlanted;
 p.plantedArea=plantedArea;
 p.isBuilt=isBuilt;
 p.buildStartTime=buildStartTime;
 p.isBeingBuilt=isBeingBuilt;
 p.shenaseP=shenaseP;
			}
			outfile.write((char*)&p, sizeof(p));
		}
		outfile.close();
		infile.close();
		remove("alfalfaField.txt");
		rename("alfalfaField-temp.txt", "alfalfaField.txt");
	}
}






