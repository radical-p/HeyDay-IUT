#ifndef GETAMOUNT_H
#define GETAMOUNT_H

#include <QDialog>
#include <QString>
#include <QMessageBox>
#include "farm.h"
namespace Ui {
class getAmount;
}

class getAmount : public QDialog
{
    Q_OBJECT

public:
    explicit getAmount(QWidget *parent = nullptr,int _sell=0,int _buy=0,int _coin=0,int _tedad=0,int capacity=0,int _kodom=0);
    ~getAmount();

private slots:
    void on_SELL_clicked();

    void on_BUY_clicked();

private:
    Ui::getAmount *ui;
    int sell;
    int buy;
    int tedad;
    int coin;
    int capacity;
    int kodom;
signals:
    void mysell(int kodom,int tedad);
    void mybuy(int kodom,int tedad);

};

#endif // GETAMOUNT_H
