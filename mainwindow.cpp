#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <fstream>
#include <string>
#include <QDataStream>
void runthread(QLabel*L1,Farm *myfarm,MainWindow*t){
    L1->setText("day : "+QString::number(myfarm->owner.getDay()));
    while(1){


            myfarm->mymutex.lock();
            //


            L1->setText("day : "+QString::number(myfarm->owner.getDay()));

        myfarm->mySto.addMilk(myfarm->read_milk(myfarm->owner.getShenaseP(),myfarm->owner.getDay()));
            t->showCoin();
           t->showLevel();
            t->showXp();
             //
            myfarm->mymutex.unlock();
            _sleep(1000);

    }
}

void runthread2(Farm *myfarm,MainWindow*t){

    while(1){


            myfarm->mymutex.lock();
            //

            myfarm->owner.setDay(myfarm->owner.getDay()+1);

            myfarm->owner.setCoin(1000);
            myfarm->owner.setLevel(10);

            myfarm->myAvi.checkbuilding(myfarm->owner.getDay());
                       myfarm->myAvi.checkcrop(myfarm->owner.getDay());
                       myfarm->myAvi.checkupdate(myfarm->owner.getDay());

                       myfarm->myShe.checkbuilding(myfarm->owner.getDay());
                       myfarm->myShe.checkcrop(myfarm->owner.getDay());
                       myfarm->myShe.checkupdate(myfarm->owner.getDay());

                       myfarm->myDai.checkbuilding(myfarm->owner.getDay());
                       myfarm->myDai.checkcrop(myfarm->owner.getDay());
                       myfarm->myDai.checkupdate(myfarm->owner.getDay());

            myfarm->owner.changeExp(1);
            if(myfarm->owner.changeLevel()){
                emit t->showmessage();

            }
             //
            myfarm->mymutex.unlock();
            _sleep(10000);

    }
}

MainWindow::MainWindow(QWidget *parent, int shenaseP)
    : QMainWindow(parent),myfarm(shenaseP)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setFixedSize(588,513);

    //menu title
    this->setWindowTitle("HeyDay");

    //background image
    QPixmap bkgnd("C:/HeydayLogo/Logo/menuback.jpg");
           bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Window/*Background*/, bkgnd);
           this->setPalette(palette);

    //main window title icon
    setWindowIcon(QIcon("C:/HeydayLogo/Logo/heyday1.jpg"));

    //level icon
    QPixmap starIcon("C:/HeydayLogo/Logo/star.png");
        ui->label->setPixmap(starIcon.scaled(50,50));

    //coin icon
    QPixmap coinIcon("C:/HeydayLogo/Logo/coin.png");
    ui->label_2->setPixmap(coinIcon.scaled(35,35));

    //next day button icon
    ui->pushButton_2->setIcon(QIcon("C:/HeydayLogo/Logo/images.jpg"));
    ui->pushButton_2->setIconSize(QSize(54, 52));

    //scorebored button icon
        ui->pushButton->setIcon(QIcon("C:/HeydayLogo/Logo/cup2.png"));
        ui->pushButton->setIconSize(QSize(40, 40));

        //shop button icon
        ui->pushButton_3->setIcon(QIcon("C:/HeydayLogo/Logo/shop2.png"));
        ui->pushButton_3->setIconSize(QSize(90, 90));

        //silo button icon
        ui->silo->setIcon(QIcon("C:/HeydayLogo/Logo/silo.png"));
        ui->silo->setIconSize(QSize(95, 95));

        //garner icon
        ui->garner->setIcon(QIcon("C:/HeydayLogo/Logo/garner.png"));
        ui->garner->setIconSize(QSize(90, 90));

        //wheatland icon
        ui->WheatLand->setIcon(QIcon("C:/HeydayLogo/Logo/wheatmenu.png"));
        ui->WheatLand->setIconSize(QSize(90, 90));


        ui->Sheepcote->setIcon(QIcon("C:/HeydayLogo/Logo/sheep.png"));
        ui->Sheepcote->setIconSize(QSize(88, 88));


        ui->Aviculture->setIcon(QIcon("C:/HeydayLogo/Logo/Aviculture.png"));
        ui->Aviculture->setIconSize(QSize(85, 85));


        ui->Dairyfarm->setIcon(QIcon("C:/HeydayLogo/Logo/cow.png"));
        ui->Dairyfarm->setIconSize(QSize(85, 85));

        ui->alfalfaLand->setIcon(QIcon("C:/HeydayLogo/Logo/alfalfamenu.jpg"));
        ui->alfalfaLand->setIconSize(QSize(80, 80));

    //multi thread
    Qt=QThread::create(runthread,ui->label_5,&myfarm,this);
    Qt->start();
        
    Qt2=QThread::create(runthread2,&myfarm,this);
    Qt2->start();

    connect(this,SIGNAL(showmessage()),this,SLOT(on_shoewMessage_signal()));

}

MainWindow::~MainWindow()
{

    Qt->terminate();
    Qt2->terminate();
    myfarm.owner.Update_file();
    myfarm.myAlf.update_file();
    myfarm.myAvi.Update_file();
    myfarm.myDai.Update_file();
    myfarm.myShe.Update_file();
    myfarm.mySil.update_file();
    myfarm.mySto.update_file();
    myfarm.myWhe.upDateFile();

    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    myfarm.owner.Update_file();
    sc=new scoreboard(this);
    sc->setWindowIcon(QIcon("C:/HeydayLogo/Logo/score.jpg"));
    sc->setModal(true);
    sc->show();
}



void MainWindow::showLevel()
{
    QString stringNumber = QString::number(myfarm.owner.getLevel());
    ui->label_4->setText(stringNumber);
}



//Display persentage of XP
void MainWindow::showXp()
{
   ui->exp2->setText(QString::number(myfarm.owner.getExp()));
}





void MainWindow::showCoin()
{
    QString stringNumber = QString::number(myfarm.owner.getCoin());
    ui->label_3->setText(stringNumber);

}





//shop button (AmirAli)
void MainWindow::on_pushButton_3_clicked()
{
    if(myfarm.owner.getLevel() > 1){
        stor=new store(this,&myfarm);
        stor->show();
    }
    else{
        QMessageBox::critical(this,"Error","At least level 2 is required!");
    }

}

//next day button(AmirAli)
void MainWindow::on_pushButton_2_clicked()
{
    myfarm.mymutex.lock();
    //

    myfarm.owner.setDay(myfarm.owner.getDay()+1);
    ui->label_5->setText("day : "+QString::number(myfarm.owner.getDay()));
    myfarm.owner.changeExp(1);
    if(myfarm.owner.changeLevel()){
        QMessageBox::information(this,"congratulation","You reach level "+QString::number(myfarm.owner.getLevel()));
    }
myfarm.mySto.addMilk(myfarm.read_milk(myfarm.owner.getShenaseP(),myfarm.owner.getDay()));
    showCoin();
   showLevel();
    showXp();
     //
    myfarm.mymutex.unlock();
}

//silo button (Soroosh)
void MainWindow::on_silo_clicked()
{
    Sil = new DialogSilo(this,&myfarm);
//    Sil->checkForUpgrade();
    Sil->show();
}

//garner button(Soroosh)
void MainWindow::on_garner_clicked()
{

    sto=new DialogStorage(this,&myfarm);
//    sto->checkForUpgrade();
    sto->show();

}

//alfalfa land(Soroosh)
void MainWindow::on_alfalfaLand_clicked()
{
    Alf = new DialogAlfalfaField(this,&myfarm);
//    Alf->checkForUpgrade();
//if(myfarm.owner.getLevel()>=3)
    Alf->show();

}

//Wheatland (Pouya)
void MainWindow::on_WheatLand_clicked()
{
    wh = new wheatland2(this,&myfarm);
    wh->show();
}


//Aviculture button (Ahmad)
void MainWindow::on_Aviculture_clicked()
{
        Avi=new Aviculture(this,&myfarm);
        Avi->show();
}

//Dairyfarm (Ahmad)
void MainWindow::on_Dairyfarm_clicked()
{
        Da = new Dairyfarm(this,&myfarm);
        Da->show();
}

//Sheepcote (Ahmad)
void MainWindow::on_Sheepcote_clicked()
{
  
        Sh = new Sheepcote(this,&myfarm);
        Sh->show();
    
}

void MainWindow::on_shoewMessage_signal()
{
    QMessageBox::information(this,"congratulation","You reach level "+QString::number(myfarm.owner.getLevel()));

}

