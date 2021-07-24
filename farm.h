#ifndef FARM_H
#define FARM_H
#include "person.h"
#include "Aviculture_back.h"
#include "Dairyfarm_back.h"
#include "Sheepcote_back.h"
#include "alfalfaField.h"
#include "silo.h"
#include "storage.h"
#include <QMutex>
#include <fstream>
#include <wheatland_back.h>
//using namespace std;
class Farm
{
public:
    Farm(int);
   person0 owner;
   QMutex mymutex;
   Aviculture_back myAvi;
   Dairyfarm_back myDai;
   Sheepcote_back myShe;
   alfalfaField myAlf;
   wheatland_back myWhe;
   silo mySil;
   storage1 mySto;
   void write_milk(int shenase ,int tedad,int day);
   int read_milk(int shenase,int day);
   void sell_milk(int shenase,int tedad);

};

#endif // FARM_H
