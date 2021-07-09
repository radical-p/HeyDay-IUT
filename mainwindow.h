#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include "scoreboard.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:

    void setLevel(int);
    void showLevel();

    void setXp(int);
    void showXp();

    void setPassedDay(int);
    void showPassedDay();

    void setCoin(int);
    void showCoin();

    void upDateXp(int);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int level;
    int xp;
    int coin;
    int passedDays;
    int userId;
};
#endif // MAINWINDOW_H
