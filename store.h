#ifndef STORE_H
#define STORE_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QSize>
#include <farm.h>
#include "getamount.h"
QT_BEGIN_NAMESPACE
namespace Ui { class store; }
QT_END_NAMESPACE

class store : public QWidget
{
    Q_OBJECT

public:
    store(QWidget *parent = nullptr,Farm *_m=NULL);
    ~store();
    getAmount *ge;

public slots:
    void slotToSell(int,int);
    void slotToBuy(int,int);
    void on_pushButton_2_clicked();


    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private slots:
    void on_pushButton_11_clicked();

private:
    Ui::store *ui;
    Farm *myfarm;

};
#endif // STORE_H
