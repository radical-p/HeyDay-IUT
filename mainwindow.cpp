#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <iostream>
#include <QFile>
#include <string>
using namespace std;

struct temp{
string name;
string pass;
string username;
string email;
int coin;
int exp;
int level;
int shenaseP;
int maxExp;
}p;

MainWindow::MainWindow(QWidget *parent, int _id)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    userId = _id;

    ui->setupUi(this);
    this->setWindowTitle("HeyDay");

    QPixmap bkgnd("C:/Users/Radikal/Desktop/Logo/back.jpg");
       bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
       QPalette palette;
       palette.setBrush(QPalette::Window/*Background*/, bkgnd);
       this->setPalette(palette);

    //main window title icon
    setWindowIcon(QIcon("C:/Users/Radikal/Desktop/Logo/heyday1.jpg"));

    //level icon
    QPixmap starIcon("C:/Users/Radikal/Desktop/Logo/images.png");
    ui->label->setPixmap(starIcon.scaled(30,30));

    //coin icon
    QPixmap coinIcon("C:/Users/Radikal/Desktop/Logo/coin.png");
    ui->label_2->setPixmap(coinIcon.scaled(35,35));

    //next day button icon
    ui->pushButton_2->setIcon(QIcon("C:/Users/Radikal/Desktop/Logo/images.jpg"));
    ui->pushButton_2->setIconSize(QSize(54, 52));

    //scorebored button icon
    ui->pushButton->setIcon(QIcon("C:/Users/Radikal/Desktop/Logo/score.jpg"));
    ui->pushButton->setIconSize(QSize(40, 40));

    //shop button icon
    ui->pushButton_3->setIcon(QIcon("C:/Users/Radikal/Desktop/Logo/shop.jpg"));
    ui->pushButton_3->setIconSize(QSize(61, 62));

    //seting data
    QFile infile("person.txt");
    infile.open(QIODevice::ReadOnly);
    if(infile.isOpen()){
        infile.seek(ios::end);
        int size = infile.size();
        infile.seek(ios_base::beg);
        while(infile.pos()<size){
               infile.read((char*)&p,sizeof(p));
               if(p.shenaseP == userId){
                   setLevel(p.level);
                   level = p.level;
                   setXp(p.exp);
                   xp = p.exp;
                   setCoin(p.coin);
                   coin = p.coin;
                   setPassedDay(0);
               }

        }

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    scoreboard sc;
    sc.setWindowIcon(QIcon("C:/Users/Radikal/Desktop/Logo/score.jpg"));
    sc.setModal(true);
    sc.exec();
}

void MainWindow::setLevel(int _level)
{
    level = _level;
    showLevel();
}

void MainWindow::showLevel()
{
    QString stringNumber = QString::number(level);
    ui->label_4->setText(stringNumber);
}

void MainWindow::setXp(int _xp)
{
    xp = _xp;
    showXp();
}

//Display persentage of XP
void MainWindow::showXp()
{
    int XpOfLvl = 0;
    for (int i = 0 ; i < level ; i++) {
        XpOfLvl = 10 + 2 * XpOfLvl;
    }
   ui->XP->setValue( xp/XpOfLvl * 100 );
}

//Update value of xp and level
void MainWindow::upDateXp(int additionalXp){
    int xp2 = 0;
    xp2 = xp + additionalXp;

}

void MainWindow::setCoin(int _coin)
{
    coin = _coin;
    showCoin();
}

void MainWindow::showCoin()
{
    QString stringNumber = QString::number(coin);
    ui->label_3->setText(stringNumber);

}

void MainWindow::setPassedDay(int _passed)
{
    passedDays = _passed;
    showPassedDay();
}

void MainWindow::showPassedDay()
{
    QString stringNumber = QString::number(passedDays);
    ui->label_5->setText(stringNumber);
}
