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



       // p.name=ui->LineEditName->text().toStdString();
       // p.pass=ui->LineEditPass->text().toStdString();
        p.name=ui->LineEditName->text().toUtf8().constData();
        p.pass=ui->LineEditPass->text().toUtf8().constData();
       // string repass=ui->LineEditPass_2->text().toStdString();
        string repass=ui->LineEditPass_2->text().toUtf8().constData();
       // p.username=ui->LineEditUser->text().toStdString();
       // p.email=ui->LineEditEmail->text().toStdString();
         p.username=ui->LineEditUser->text().toUtf8().constData();
         p.email=ui->LineEditEmail->text().toUtf8().constData();
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

        fscanf(fp, "%d", &tedad);
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
        struct temp temp2;
        ifstream infile;
        infile.open("person.txt",ios::in);
        if(infile.good()){
            infile.seekg(0, ios::end);
            int size = infile.tellg();
            infile.seekg(0, ios_base::beg);
            while(infile.tellg()<size){
                   infile.read((char*)&temp2,sizeof(temp2));
                   if(ui->LineEditUser->text().toStdString()==temp2.username){
                       valid=0;

                       QMessageBox::information(this,"Error","this username has chosen :(",QMessageBox::Ok);
                       break;
                   }

            }

        }
        infile.close();
        if(valid){
            fstream outfile;
            outfile.open("person.txt", ios::app);
            outfile.write((char*)&p,sizeof(p));
            fopen_s(&fp,"tedadC.txt", "w");
            fprintf(fp, "%d", tedad);
            fclose(fp);
            this->close();
        }

}


void DialogFormakeAccount::on_cancel_push_clicked()
{
    this->close();
}

