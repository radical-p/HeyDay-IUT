#include "getamount.h"
#include "ui_getamount.h"

getAmount::getAmount(QWidget *parent,int _sell,int _buy,int _coin,int _tedad,int _capacity,int _kodom) :
    QDialog(parent),
    ui(new Ui::getAmount)
{
    ui->setupUi(this);
    sell=_sell;
    buy=_buy;
    coin=_coin;
    tedad=_tedad;
    capacity=_capacity;
    kodom=_kodom;
    ui->coin->setText(QString("coin ")+QString::number(_coin));
    ui->tedad->setText(QString("tedad ")+QString::number(_tedad));
    ui->BUY->setText(QString("BUY ")+QString::number(_buy));
    ui->SELL->setText(QString("SELL ")+QString::number(_sell));
    ui->capacity->setText(QString("Free Sapce ")+QString::number(_capacity));
}

getAmount::~getAmount()
{
    delete ui;
}

void getAmount::on_SELL_clicked()
{
    if(tedad-(ui->lineEdit->text().toInt())>=0){

        emit mysell(kodom,ui->lineEdit->text().toInt());

    }else {
     QMessageBox::information(this,"ERROR","you dont have enough ");
}
    this->close();
}


void getAmount::on_BUY_clicked()
{

    if(coin-(ui->lineEdit->text().toInt()*buy)>=0){
        if(capacity-(ui->lineEdit->text().toInt())>=0)
        {

        emit mybuy(kodom,ui->lineEdit->text().toInt());
        }else {
        QMessageBox::information(this,"ERROR","you dont have enough capacity");
}

    }else {
     QMessageBox::information(this,"ERROR","you dont have enough coin");
}
    this->close();

}

