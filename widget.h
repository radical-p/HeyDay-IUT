#ifndef WIDGET_H
#define WIDGET_H
#include "dialogformakeaccount.h"
#include <QWidget>
#include <QDataStream>

#include  <mainwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


private slots:
    void on_pushButton_pressed();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
     DialogFormakeAccount* D;
     MainWindow * m;
};
#endif // WIDGET_H
