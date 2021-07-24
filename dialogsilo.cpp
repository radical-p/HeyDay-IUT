#include "dialogsilo.h"
#include "ui_dialogsilo.h"
#include <iostream>
#include <string.h>
#include <math.h>
#include "QMessageBox"
#include <QString>

int tmpId1=1,tmpCapacity1=10,tmpNumWheat1=1,tmpLevel1=1,tmpUpgradeStartTime1=0;
        bool tmpIsBeingUpgraded1=0;

using namespace std;
DialogSilo::DialogSilo(QWidget *parent,Farm *_myfarm) :
    QDialog(parent),
    ui(new Ui::DialogSilo)
{

    ui->setupUi(this);

    //for getting day of player
    myfarm = _myfarm;
    if(checkForUpgrade()){
        QMessageBox::information(this,"good News !","silo upgraded suucessfully");
    }
    this->setWindowTitle("silo");

    //"C:\HeydayLogo\Logo\silo.jpg"

    QPixmap bkgndSil("C:/HeydayLogo/Logo/silo.jpg");
    bkgndSil = bkgndSil.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette paletteSil;
    paletteSil.setBrush(QPalette::Window/*Background*/, bkgndSil);
    this->setPalette(paletteSil);


        ui->label_2->setText(QString::number(myfarm->mySil.level));
        ui->label_4->setText(QString::number(myfarm->mySil.capacity - myfarm->mySil.getNumWheat()));
        ui->label_6->setText(QString::number(myfarm->mySil.numWheat));


}

DialogSilo::~DialogSilo()
{
    delete ui;
}

void DialogSilo::on_pushButton_clicked()// upgrade
{
if(myfarm->mySil.isBeingUpgraded==false)
    {
    if(myfarm->mySto.getShovel()>=myfarm->mySil.getLevel()-2){
    if(myfarm->mySto.getNail()>=myfarm->mySil.getLevel()*2){
     if(myfarm->owner.getCoin()>=pow(myfarm->mySil.getLevel()*2,2)*100){
         myfarm->mySil.isBeingUpgraded=true;
         QMessageBox::information(this,"OK","silo is upgrading!\nit will take 4 days to complete");
          myfarm->mySil.upgradeStartTime= myfarm->owner.getDay();
          myfarm->mySto.addShovel(-1*myfarm->mySil.getLevel()-2);
          myfarm->mySto.addNail(-1*myfarm->mySil.getLevel()*2);
     myfarm->owner.changeCoin(-1*pow(myfarm->mySil.getLevel()*2,2)*100);


     }

 else{
         QMessageBox::critical(this,"ERROR","can't upgrade silo!\n more coin is required:"+QString::number(pow(myfarm->mySil.getLevel()*2,2)*100 - myfarm->owner.getCoin()));

     }

 }


 //
 else
     QMessageBox::critical(this,"ERROR","can't upgrade silo!\n more nail is required:"+QString::number(myfarm->mySil.getLevel()*2 - myfarm->mySto.getNail()));
    }
    else{
        QMessageBox::critical(this,"ERROR","can't upgrade silo!\n more shovel is required:"+QString::number(myfarm->mySil.getLevel()-2 - myfarm->mySto.getShovel()));

    }
}
else{
    QMessageBox::critical(this,"ERROR","upgrade is in process\nremaining days:"+QString::number(myfarm->mySil.upgradeStartTime+4 - myfarm->owner.getDay()));

}
}





int DialogSilo::checkForUpgrade(){

    if(myfarm->mySil.isBeingUpgraded){
       if( myfarm->owner.getDay()-myfarm->mySil.upgradeStartTime>=4){

         myfarm->mySil.capacity*=2;
         myfarm->mySil.level=myfarm->mySil.getLevel()+1;
         myfarm->owner.setExp(myfarm->owner.getExp()+(myfarm->mySil.getLevel())*2);
         myfarm->mySil.isBeingUpgraded=false;
         QMessageBox::information(this,"ERROR","silo fully upgraded!");

         return 1;
   }
    }
    return 0;

}
