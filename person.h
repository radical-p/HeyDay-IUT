#ifndef PERSON_H
#define PERSON_H
#include <QString>
#include <iostream>
#include <QFile>


class person0{
    private:
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
    public://functions
    void setName(QString);
    void setPass(QString);
    void setUsername(QString);
    void setEmail(QString);
    void setCoin(int);
    void setExp(int);
    void setLevel(int);
    void setShenaseP(int);
    void setMaxExp(int);
    void setDay(int d){day=d;}
    person0(int);//constructor
    QString getName();
    QString getUsername();
    QString getEmail();
    int getShenaseP();
    int changeCoin(int);//return coin
    int changeExp(int);
    int changeLevel();
    int getMaxExp();
    int getExp();
    int getCoin();
    int getLevel();
    int getDay(){return day;}
    void Update_file();
};



#endif // PERSON_H
