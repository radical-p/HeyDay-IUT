#include "widget.h"
#include "ui_widget.h"
#pragma once

struct temp{
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
QDataStream &operator>>(QDataStream &in, struct temp &p){ //for read from the file
    in >> p.name >> p.pass >>p.username>>p.email>>p.coin>>p.exp>>p.level>>p.shenaseP>>p.maxExp>>p.day;
    return in;
}
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->passlineEdit->setEchoMode(QLineEdit::Password);

    QPixmap bkgnd("C:/HeydayLogo/Logo/login.jpg");
          bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
          QPalette palette;
          palette.setBrush(QPalette::Window, bkgnd);
          this->setPalette(palette);

          this->setWindowTitle("Login");

          setWindowIcon(QIcon("C:/HeydayLogo/Logo/heyday1.jpg"));

          ui->pushButton_2->setIcon(QIcon("C:/HeydayLogo/Logo/loginbut.png"));
          ui->pushButton_2->setIconSize(QSize(54, 52));

          ui->pushButton->setIcon(QIcon("C:/HeydayLogo/Logo/makeaccbut.jpg"));
          ui->pushButton->setIconSize(QSize(54, 52));


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

struct temp p;
    bool peyda=1;
    QFile infile("person.txt");
    infile.open(QIODevice::ReadOnly);
    if(infile.isOpen()){

        while(!infile.atEnd()){

            QDataStream in(&infile);
            in>>p;
               if(ui->userLine->text()==p.username&&ui->passlineEdit->text()==p.pass){

                   peyda=0;

                  m = new MainWindow(this,p.shenaseP);
                  this->close();

                  m->show();

               }

        }

    }
    if(peyda){
        QMessageBox::information(this,"ERROR","acc not found !");
        this->close();
    }
    infile.close();
}

