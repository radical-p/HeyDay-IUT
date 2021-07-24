#ifndef DIALOGFORMAKEACCOUNT_H
#define DIALOGFORMAKEACCOUNT_H
#include "string"
using namespace std;
#include <QDialog>
#include <QMessageBox>
#include <QFile>
#include  <QDataStream>

struct person{
QString name;
QString pass;
QString username;
QString email;
int coin;
int exp;
int level;
int shenaseP;
int maxExp;
int day;
};
namespace Ui {
class DialogFormakeAccount;
}

class DialogFormakeAccount : public QDialog
{
    Q_OBJECT

public:
    explicit DialogFormakeAccount(QWidget *parent = nullptr);

    ~DialogFormakeAccount();

private slots:
    void on_makeaccPush_clicked();

    void on_cancel_push_clicked();

private:
    Ui::DialogFormakeAccount *ui;

};

#endif // DIALOGFORMAKEACCOUNT_H
