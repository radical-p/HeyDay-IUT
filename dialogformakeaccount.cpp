#include "dialogformakeaccount.h"
#include "ui_dialogformakeaccount.h"

QDataStream &operator>>(QDataStream &in, struct person &p){ //for read from the file
    in >> p.name >> p.pass >>p.username>>p.email>>p.coin>>p.exp>>p.level>>p.shenaseP>>p.maxExp>>p.day;
    return in;
}

QDataStream &operator<<(QDataStream &out, struct person &p){ //for writing from the file
    out << p.name <<p.pass <<p.username<<p.email<<p.coin<<p.exp<<p.level<<p.shenaseP<<p.maxExp<<p.day;
    return out;
}
DialogFormakeAccount::DialogFormakeAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFormakeAccount)
{
    ui->setupUi(this);

    QPixmap bkgnd("C:/HeydayLogo/Logo/makeacc2.jpg");
           bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
           QPalette palette;
           palette.setBrush(QPalette::Window, bkgnd);
           this->setPalette(palette);

           ui->LineEditPass->setEchoMode(QLineEdit::Password);
           ui->LineEditPass_2->setEchoMode(QLineEdit::Password);
}

DialogFormakeAccount::~DialogFormakeAccount()
{
    delete ui;
}

void DialogFormakeAccount::on_makeaccPush_clicked()
{


       struct person p;

        p.name=ui->LineEditName->text();
        p.pass=ui->LineEditPass->text();
        QString repass=ui->LineEditPass_2->text();
        p.username=ui->LineEditUser->text();
        p.email=ui->LineEditEmail->text();
        p.coin=20;
        p.exp=0;
        p.level=1;
        p.maxExp=10;
        p.day=0;
        int tedad = 0;
        QFile fp("tedadC.txt");
        fp.open(QIODevice::ReadOnly);
        if (!fp.isOpen()) {
            fp.close();
            fp.open(QIODevice::WriteOnly);
           fp.write((char*)&tedad,sizeof(int));
            fp.close();
             fp.open(QIODevice::ReadOnly);
        }

        fp.read((char*)&tedad,sizeof(int));
        tedad++;
        p.shenaseP=tedad;
        fp.close();
        bool valid=1;
        if(p.name=="\0"){
            valid=0;
            QMessageBox::information(this,"Error","name is empty :(",QMessageBox::Ok);


        }else if(p.pass=="\0"){
            valid=0;
            QMessageBox::information(this,"Error","pass is empty :(",QMessageBox::Ok);

        }else if(p.username=="\0"){
            valid=0;
             QMessageBox::information(this,"Error","username is empty :(",QMessageBox::Ok);

        }else if(p.pass !=repass){
            valid=0;
             QMessageBox::information(this,"Error","password dont match :(",QMessageBox::Ok);

        }
        if(valid){
        struct person temp2;
        QFile infile("person.txt");
        infile.open(QIODevice::ReadOnly);
        if(infile.isOpen()){

            while(!infile.atEnd()){
                QDataStream in(&infile);
                in>>temp2;
                   /*infile.read((char*)&temp2,sizeof(temp2));*/
                   if(ui->LineEditUser->text()==temp2.username){
                       valid=0;

                       QMessageBox::information(this,"Error","this username has chosen :(",QMessageBox::Ok);

                       break;
                   }

            }
          infile.close();
        }

}
if (valid){
            QFile outfile("person.txt");
            outfile.open(QIODevice::Append);
            /*outfile.write((char*)&p,sizeof(p));*/
            QDataStream out(&outfile);
            out<<p;
            fp.open(QIODevice::WriteOnly);
           fp.write((char*)&tedad,sizeof(int));
            fp.close();
            outfile.close();
        }

        this->close();



}


void DialogFormakeAccount::on_cancel_push_clicked()
{
    this->close();
}

