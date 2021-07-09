#include "widget.h"
#include "mainwindow.h"
#include "ui_widget.h"
#include "global.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    w = new MainWindow;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_pressed()
{

    D=new DialogFormakeAccount(this);
    D->show();
}


void Widget::on_pushButton_2_clicked()
{
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
    }pers;
    bool peyda=1;
    ifstream infile;
    infile.open("person.txt",ios::in);
    if(infile.good()){
        infile.seekg(0, ios::end);
        int size = infile.tellg();
        infile.seekg(0, ios_base::beg);
        while(infile.tellg()<size){
               infile.read((char*)&pers,sizeof(pers));
               if(1/*ui->userLine->text().toUtf8().constData()==pers.username&&ui->passlineEdit->text().toUtf8().constData()==pers.pass*/){
                   peyda=0;
                   // pouya code
                   w->show();
                   w->activateWindow();
               }
        }

    }
    if(peyda != 0){
        QMessageBox::information(this,"ERROR","acc not found !");
    }
    infile.close();
}

