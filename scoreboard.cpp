#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <QDataStream>
#include <QFile>


struct tempo{
    QString name;
    QString pass;
    QString username;
    QString email;
    int coin;
    int exp;
    int level;
    int shenaseP;
    int maxExp;
    int day;
};

bool compareTwoStudents(tempo a, tempo b)
{
    if (a.level != b.level)
        return a.level > b.level;

    if (a.exp != b.exp)
        return a.exp > b.exp;

    return (a.coin > b.coin);
}

QDataStream &operator>>(QDataStream &in, struct tempo &p){
    in >> p.name >> p.pass >>p.username>>p.email>>p.coin>>p.exp>>p.level>>p.shenaseP>>p.maxExp >> p.day;
    return in;
}

scoreboard::scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scoreboard)
{
    ui->setupUi(this);

    this->setWindowTitle("Ranking Table");

    QPixmap starIcon("C:/Users/Radikal/Desktop/Logo/rank.jpg");
    ui->label->setPixmap(starIcon.scaled(30,30));

    //set background color
    this->setStyleSheet("background-color: lightblue");
    ui->listWidget->setStyleSheet("background-color: white");

    //ok logo
    ui->pushButton->setIcon(QIcon("C:/Users/Radikal/Desktop/Logo/ok.png"));
    ui->pushButton->setIconSize(QSize(45, 45));

    struct tempo p[10];
    int i = 0;
        QFile infile("person.txt");
        infile.open(QIODevice::ReadOnly);
        if(infile.isOpen()){
            while(!infile.atEnd()){
                QDataStream in(&infile);
                in>>p[i];
                i++;
            }
        }
        ui->listWidget->addItem("RANK      USERNAME      LEVEL      EXP");
        int ranker = 1;
        std::sort(p, p + i, compareTwoStudents);
        for (int j = 0; j < i ; j++ ) {
            if((p[j-1].level != p[j].level || p[j-1].exp != p[j].exp) && j != 0)
                ranker++;
            QString tmp = QString::number(ranker) + "             " + p[j].name + "                    " + QString::number(p[j].level) + "         " + QString::number(p[j].exp) ;
            ui->listWidget->addItem(tmp);
        }

}

scoreboard::~scoreboard()
{
    delete ui;
}


