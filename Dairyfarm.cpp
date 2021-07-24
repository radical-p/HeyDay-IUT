#include "Dairyfarm.h"
#define DAIRYFARM "C:/HeydayLogo/Dairyfarm_logo/cow.png"
#define STATUS "C:/HeydayLogo/Aviculture_logo/2230690.png"
#define FEEDING "C:/HeydayLogo/Dairyfarm_logo/2644051.png"
#define REMOVAL "C:/HeydayLogo/Dairyfarm_logo/6571245.png"
#define UPGRADING "C:/HeydayLogo/Aviculture_logo/6154580.png"
#define DRAHALSAKHT "C:/HeydayLogo/Aviculture_logo/1958813.png"
#define SAKHTAN "C:/HeydayLogo/Aviculture_logo/5250128.png"

Dairyfarm::Dairyfarm(QWidget* parent, Farm* _Myfarm)
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

   
    if (!myFarm->myDai.getisbuildingmade() && myFarm->myDai.getisbuildingmaking()) {
        Layout->addWidget(btn5);
        QString str = QString("%1 days pass it takes 5 days").arg(myFarm->owner.getDay() - myFarm->myDai.get_start_day_of_building());
        lbl->setText(str);
        Layout->addWidget(lbl);
    }

    if (!myFarm->myDai.getisbuildingmaking() && !myFarm->myDai.getisbuildingmade()) {
        Layout->addWidget(btn6);
        lbl->setText("if you wanna build your Dairyfarm click the butten (you should be atleast level 4 and need 3 nail and 10 coin,1 shovel)");
        Layout->addWidget(lbl);
    }
    else if (myFarm->myDai.getisbuildingmade()) {

        Layout->addWidget(btn1);
        Layout->addWidget(btn2);
        Layout->addWidget(btn3);
        Layout->addWidget(btn4);
    }

    wdg->setLayout(Layout);
    wdg->show();

   // setLayout(Layout);

    connect(btn1, SIGNAL(clicked()), this, SLOT(status()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(feeding()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(removal()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(starting_upgrade()));
    connect(btn5, SIGNAL(clicked()), wdg, SLOT(close()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(sakhtan()));
    connect(btn6, SIGNAL(clicked()), wdg, SLOT(close()));

    // ui.setupUi(this);
}

void Dairyfarm::status() {
    QString str = QString("current number of cows: %1\ncapacity of Dairyfarm: %2\nlevel of Dairyfarm: %3").arg(myFarm->myDai.getcurrent()).arg(myFarm->myDai.getcapacity()).arg(myFarm->myDai.getlevel());

    QMessageBox::information(this, "status", str);
}

void Dairyfarm::feeding() {
    QString str;

    if (myFarm->myDai.getcurrent() == 0)
        str = "there is no cow for feeding";
    else if (myFarm->myDai.getisfed())
        str = "hens have been fed already you should wait until they make milk";
    else if (myFarm->myDai.gethavecrop())
        str = "cows have milk you should harvest your crops first";
    else if (myFarm->mySto.getAlfalfa() < myFarm->myDai.getcurrent() * 2)
        str = "not enough Alfalfa";
    else {
        myFarm->myDai.set_start_day_of_produce(myFarm->owner.getDay());
        myFarm->myDai.setisfed(true);
        myFarm->mySto.addAlfalfa(myFarm->myDai.getcurrent() * -2);
        myFarm->owner.setExp(myFarm->owner.getExp() + 3);
        str = "cows fed successfully";
    }
    QMessageBox::information(this, "feeding", str);
}

void Dairyfarm::removal() {
    QString str;

    if (myFarm->myDai.getisfed() && !myFarm->myDai.gethavecrop())
        str = "cows have been fed but they have not made milk already";
    else if (!myFarm->myDai.gethavecrop())
        str = "there is no milk for milching";
    else if (myFarm->mySto.getCapacity() < myFarm->myDai.getcurrent())
        str = "garner has no place";
    else {
        myFarm->mySto.addMilk(myFarm->myDai.getcurrent());
        myFarm->write_milk(myFarm->owner.getShenaseP(), myFarm->myDai.getcurrent(), myFarm->owner.getDay());
        myFarm->owner.setExp(myFarm->owner.getExp() + 5);
        myFarm->myDai.sethavecrop(false);
        str = "done successfully";
    }
    QMessageBox::information(this, "removal", str);
}

void Dairyfarm::starting_upgrade() {
    QString str;

    if (myFarm->myDai.getupgrading())
        str = "upgrading. you should wait 5 days";
    else  if (myFarm->owner.getLevel() < 5)
        str = "At least level 5 is required!";
    else if (myFarm->mySto.getNail() < 2)
        str = "At least 2 nail is required!";
    else if (myFarm->owner.getCoin() < 15)
        str = "At least 15 coin is required!";
    else {
        myFarm->myDai.set_start_day_of_upgrading(myFarm->owner.getDay());
        myFarm->myDai.setupgrading(true);
        myFarm->owner.setCoin(myFarm->owner.getCoin() - 15);
        myFarm->owner.setExp(myFarm->owner.getExp() + 6);
        myFarm->mySto.addNail(-2);
        str = "start upgrading. It takes five days";
    }
    QMessageBox::information(this, "upgrading", str);
}

void Dairyfarm::sakhtan() {
    QString str;

    if (myFarm->owner.getLevel() < 4)
        str = "At least level 4 is required!";
    else if (myFarm->mySto.getNail() < 3)
        str = "At least 3 nail is required!";
    else if (myFarm->owner.getCoin() < 20)
        str = "At least 20 coin is required!";
    else if (myFarm->mySto.getShovel() < 1)
        str = "At least 1 shovel is required!";
    else {
        myFarm->myDai.setisbuildingmaking(true);
        myFarm->myDai.set_start_day_of_building(myFarm->owner.getDay());
        myFarm->owner.setCoin(myFarm->owner.getCoin() - 20);
        myFarm->owner.setExp(myFarm->owner.getExp() + 10);
        myFarm->mySto.addNail(-3);
        myFarm->mySto.addShovel(-1);

        str = "start building. It takes five days";
    }
    QMessageBox::information(this, "building", str);
}