#include "scoreboard.h"
#include "ui_scoreboard.h"
#include <QFile>
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
}person;

scoreboard::scoreboard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::scoreboard)
{
    ui->setupUi(this);

    QFile infile("person.txt");
    infile.open(QIODevice::ReadOnly);
    if(infile.isOpen()){
        infile.seek(ios_base::end);
        int size = infile.size();
        infile.seek(ios_base::beg);
        while(infile.pos()<size){
               infile.read((char*)&person,sizeof(person));
               QString qstr = QString::fromStdString(person.name);
               QString tmp = qstr +  "    " +QString::number(person.level);
               ui->listWidget->addItem(tmp);
               }
        }

}

scoreboard::~scoreboard()
{
    delete ui;
}
