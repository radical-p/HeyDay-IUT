#ifndef WHEATLAND2_H
#define WHEATLAND2_H

#include <QDialog>
#include "farm.h"

namespace Ui {
class wheatland2;
}

class wheatland2 : public QDialog
{
    Q_OBJECT

public:
    wheatland2(QWidget *parent = Q_NULLPTR, Farm *_myfarm = nullptr);
    ~wheatland2();
    void keshtUpDate(int);
public:
    void upDate();
private slots:
    void on_kesht_clicked();

    void on_bardasht_clicked();

    void on_upGrade_clicked();

private:
    Ui::wheatland2 *ui;
    Farm *myfarm;
};

#endif // WHEATLAND2_H
