#ifndef DIALOGSILO_H
#define DIALOGSILO_H

#include <QDialog>
#include "farm.h"
#include <stdbool.h>
namespace Ui {
class DialogSilo;
}

class DialogSilo : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSilo(QWidget *parent = nullptr,Farm *_myfarm= nullptr);
    ~DialogSilo();
int checkForUpgrade();

    friend class storage;
    friend class alfalfaField;

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogSilo *ui;
    Farm *myfarm;

};

#endif // DIALOGSILO_H



