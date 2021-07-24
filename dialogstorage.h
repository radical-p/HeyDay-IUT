#ifndef DIALOGSTORAGE_H
#define DIALOGSTORAGE_H
#include "farm.h"
#include <QDialog>
//#include "milk.h"
#include <time.h>
#include <iostream>
//#include <person.h>
#include <math.h>
#include <stdbool.h>
namespace Ui {
class DialogStorage;
}

class DialogStorage : public QDialog
{
    Q_OBJECT

public:
    explicit DialogStorage(QWidget *parent = nullptr,Farm *_myfarm = nullptr);
    ~DialogStorage();
    int checkForUpgrade();

    friend class alfalfaField;
    friend class silo;

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogStorage *ui;
Farm* myfarm;
};

#endif // DIALOGSTORAGE_H





