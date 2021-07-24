#include "Sheepcote.h"
#define SHEEPCOTE "C:/HeydayLogo/Sheepcote_logo/1665662.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Sheepcote_logo/3382344.png"
#define REMOVAL "C:/HeydayLogo/Sheepcote_logo/5332241.png"
#define UPGRADING "C:/HeydayLogo/Aviculture_logo/6154580.png"
#define DRAHALSAKHT "C:/HeydayLogo/Aviculture_logo/1958813.png"
#define SAKHTAN "C:/HeydayLogo/Aviculture_logo/5250128.png"

Sheepcote::Sheepcote(QWidget* parent, Farm* _Myfarm)
    : QWidget(parent)
{
    myFarm = _Myfarm;
    QDialog* wdg = new QDialog(this);
    QVBoxLayout* Layout = new QVBoxLayout();
    QLabel* lbl = new QLabel();
    QPushButton* btn1 = new QPushButton();
    btn1->setIcon(QIcon(STATUS));
    btn1->setIconSize(QSize(65, 65));
    btn1->setToolTip("status");
    QPushButton* btn2 = new QPushButton();
    btn2->setIcon(QIcon(FEEDING));
    btn2->setIconSize(QSize(65, 65));
    btn2->setToolTip("feeding");
    QPushButton* btn3 = new QPushButton();
    btn3->setIcon(QIcon(REMOVAL));
    btn3->setIconSize(QSize(65, 65));
    btn3->setToolTip("removal");
    QPushButton* btn4 = new QPushButton();
    btn4->setIcon(QIcon(UPGRADING));
    btn4->setIconSize(QSize(65, 65));
    btn4->setToolTip("upgrading");
    QPushButton* btn5 = new QPushButton();
    btn5->setIcon(QIcon(DRAHALSAKHT));
    btn5->setIconSize(QSize(65, 65));
    btn5->setToolTip("under constraction");
    QPushButton* btn6 = new QPushButton();
    btn6->setIcon(QIcon(SAKHTAN));
    btn6->setIconSize(QSize(65, 65));
    btn6->setToolTip("make building");

     if (!myFarm->myShe.getisbuildingmade() && myFarm->myShe.getisbuildingmaking()) {
        Layout->addWidget(btn5);
        QString str = QString("%1 days pass it takes 10 days").arg(myFarm->owner.getDay() - myFarm->myShe.get_start_day_of_building());
        lbl->setText(str);
        Layout->addWidget(lbl);
    }

    if (!myFarm->myShe.getisbuildingmaking() && !myFarm->myShe.getisbuildingmade()) {
        Layout->addWidget(btn6);
        lbl->setText("if you wanna build your Sheepcote click the butten (you should be atleast level 6 and need 4 nail and 50 coin,2 shovel)");
        Layout->addWidget(lbl);
    }

    else if (myFarm->myShe.getisbuildingmade()) {

        Layout->addWidget(btn1);
        Layout->addWidget(btn2);
        Layout->addWidget(btn3);
        Layout->addWidget(btn4);
    }

    wdg->setLayout(Layout);
    wdg->show();
    //setLayout(Layout);

    connect(btn1, SIGNAL(clicked()), this, SLOT(status()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(feeding()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(removal()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(starting_upgrade()));
    connect(btn5, SIGNAL(clicked()), wdg, SLOT(close()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(sakhtan()));
    connect(btn6, SIGNAL(clicked()), wdg, SLOT(close()));

    // ui.setupUi(this);
}

void Sheepcote::status() {
    
    QString str = QString("current number of sheeps: %1\ncapacity of Sheepcote: %2\nlevel of Sheepcote: %3").arg(myFarm->myShe.getcurrent()).arg(myFarm->myShe.getcapacity()).arg(myFarm->myShe.getlevel());

    QMessageBox::information(this, "status", str);
}

void Sheepcote::feeding() {
    QString str;

  

    if (myFarm->myShe.getcurrent() == 0)
        str = "there is no sheep for feeding";
    else if (myFarm->myShe.getisfed())
        str = "sheeps have been fed already you should wait until their fleece grow";
    else if (myFarm->myShe.gethavecrop())
        str = "sheeps have fleece you should harvest your crops first";
    else if (myFarm->mySto.getAlfalfa() < myFarm->myShe.getcurrent())
        str = "not enough Alfalfa";
    else {
        myFarm->myShe.set_start_day_of_produce(myFarm->owner.getDay());
        myFarm->myShe.setisfed(true);
        myFarm->mySto.addAlfalfa(myFarm->myShe.getcurrent() * -1);
        myFarm->owner.setExp(myFarm->owner.getExp() + 7);
        str = "sheeps fed successfully";
    }
    QMessageBox::information(this, "feeding", str);

}

void Sheepcote::removal() {
    QString str;
   

    if (myFarm->myShe.getisfed() && !myFarm->myShe.gethavecrop())
        str = "sheeps have been fed but their fleece have not grown already";
    else if (!myFarm->myShe.gethavecrop())
        str = "there is no fleece for croping";
    else if (myFarm->mySto.getCapacity() < myFarm->myShe.getcurrent())
        str = "garner has no place";
    else if (myFarm->owner.getCoin() < myFarm->myShe.getcurrent())
        str = QString("At least %1 coin is required!").arg(myFarm->myShe.getcurrent());
    else {
        myFarm->mySto.addFleece(myFarm->myShe.getcurrent());
        myFarm->owner.setExp(myFarm->owner.getExp() + 9);
        myFarm->myShe.sethavecrop(false);
        myFarm->owner.setCoin(myFarm->owner.getCoin() - myFarm->myShe.getcurrent());
        str = "done successfully";
    }
    QMessageBox::information(this, "removal", str);
}

void Sheepcote::starting_upgrade() {
    QString str;

    if (myFarm->myShe.getupgrading())
        str = "upgrading. you should wait 9 days";
    else if (myFarm->owner.getLevel() < 7)
        str = "At least level 7 is required!";
    else if (myFarm->mySto.getNail() < 3)
        str = "At least 3 nail is required!";
    else if (myFarm->owner.getCoin() < 50)
        str = "At least 50 coin is required!";
    else if (myFarm->mySto.getShovel() < 1)
        str = "At least 1 shovel is required!"; 
    else {
        myFarm->myShe.set_start_day_of_upgrading(myFarm->owner.getDay());
        myFarm->myShe.setupgrading(true);
        myFarm->owner.setCoin(myFarm->owner.getCoin() - 50);
        myFarm->mySto.addNail(-3);
        myFarm->mySto.addShovel(-1);

        str = "start upgrading. It takes nine days";
    }
    QMessageBox::information(this, "upgrading", str);

}

void Sheepcote::sakhtan() {
    QString str;

    if (myFarm->owner.getLevel() < 6)
        str = "At least level 6 is required!";
    else if (myFarm->mySto.getNail() < 4)
        str = "At least 4 nail is required!";
    else if (myFarm->owner.getCoin() < 50)
        str = "At least 50 coin is required!";
    else if (myFarm->mySto.getShovel() < 2)
        str = "At least 2 shovel is required!";
    else {
        myFarm->myShe.setisbuildingmaking(true);
        myFarm->myShe.set_start_day_of_building(myFarm->owner.getDay());
        myFarm->owner.setCoin(myFarm->owner.getCoin() - 50);
        myFarm->owner.setExp(myFarm->owner.getExp() + 20);
        myFarm->mySto.addNail(-4);
        myFarm->mySto.addShovel(-2);

        str = "start building. It takes 10 days";
    }
    QMessageBox::information(this, "building", str);
}