#include "dialogformakeaccount.h"
#include "ui_dialogformakeaccount.h"

DialogFormakeAccount::DialogFormakeAccount(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFormakeAccount)
{
    ui->setupUi(this);
}

DialogFormakeAccount::~DialogFormakeAccount()
{
    delete ui;
}

void DialogFormakeAccount::on_makeaccPush_clicked()
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



        p.name=ui->LineEditName->text().toStdString();
        p.pass=ui->LineEditPass->text().toStdString();
        string repass=ui->LineEditPass_2->text().toUtf8().constData();
        p.username=ui->LineEditUser->text().toStdString();
        p.email=ui->LineEditEmail->text().toStdString();
        p.coin=0;
        p.exp=0;
        p.level=1;
        p.maxExp=10;

        int tedad = 0;
        FILE* fp ;
        fopen_s(&fp,"tedadC.txt", "r");
        if (fp == NULL) {
            if (fp)fclose(fp);
            fopen_s(&fp,"tedadC.txt", "w");
            fprintf(fp, "%d", tedad);
            if (fp)fclose(fp);
             fopen_s(&fp,"tedadC.txt", "r");
        }

        fscanf_s(fp, "%d", &tedad);
        tedad++;
        p.shenaseP=tedad;
        fclose(fp);
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
        struct temp temp2;
        QFile infile("person.txt");
        infile.open(QIODevice::ReadOnly);
        if(infile.isOpen()){
            infile.seek(ios_base::end);
            int size = infile.size();
            infile.seek(ios_base::beg);
            while(infile.pos()<size){
                   infile.read((char*)&temp2,sizeof(temp2));
                   if(ui->LineEditUser->text().toStdString()==temp2.username){
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
            outfile.write((char*)&p,sizeof(p));
            fopen_s(&fp,"tedadC.txt", "w");
            fprintf(fp, "%d", tedad);
            fclose(fp);
            outfile.close();
        }

        this->close();



}


void DialogFormakeAccount::on_cancel_push_clicked()
{
    this->close();
}

