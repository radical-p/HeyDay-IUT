#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
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
    }p;
    bool peyda=1;
    QFile infile("person.txt");
    infile.open(QIODevice::ReadOnly);
    if(infile.isOpen()){
        infile.seek(ios_base::end);
        int size = infile.size();
        infile.seek(ios_base::beg);
        while(infile.pos()<size){
               infile.read((char*)&p,sizeof(p));
               if(ui->userLine->text().toUtf8().constData()==p.username&&ui->passlineEdit->text().toUtf8().constData()==p.pass){

                   peyda=0;
                  m=new MainWindow(this,p.shenaseP);
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

