#include "person.h"
struct personinper{
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
QDataStream &operator>>(QDataStream &in, struct personinper &p){ //for read from the file
    in >> p.name >> p.pass >>p.username>>p.email>>p.coin>>p.exp>>p.level>>p.shenaseP>>p.maxExp>>p.day;
    return in;
}

QDataStream &operator<<(QDataStream &out, struct personinper &p){ //for writing from the file
    out << p.name <<p.pass <<p.username<<p.email<<p.coin<<p.exp<<p.level<<p.shenaseP<<p.maxExp<<p.day;
    return out;
}

void person0::Update_file(){

   struct personinper p;

    QFile outfile("person-temp.txt");//for writing in new file.
    QFile infile("person.txt");//for reading.

    infile.open(QIODevice::ReadOnly);
     if(infile.isOpen()){
    outfile.open(QIODevice::Append);//make file.

    while(!infile.atEnd()){

           QDataStream in(&infile);
           in>>p;
           if(shenaseP==p.shenaseP){
                   p.name=name;
                   p.pass=pass;
                   p.username=username;
                   p.email=email;
                   p.coin=coin;
                   p.exp=exp;
                   p.level=level;
                   p.shenaseP=shenaseP;
                   p.maxExp=maxExp;
                   p.day=day;
           }
           //outfile.write((char*)&p,sizeof(p));
           QDataStream out(&outfile);
           out<<p;
    }
    infile.remove();
    outfile.rename("person.txt");
    outfile.close();
    infile.close();


    }

}
///

    void person0::setName(QString _name){name=_name;}
    void person0::setPass(QString _Pass){pass=_Pass;}
    void person0::setUsername(QString _username){username=_username;}
    void person0::setEmail(QString _Email){email=_Email;}
    void person0::setCoin(int _coin){coin=_coin;}
    void person0::setExp(int _Exp){exp=_Exp;}
    void person0::setLevel(int _Level){level=_Level;}
    void person0::setShenaseP(int _Shenasep){shenaseP=_Shenasep;}
    void person0::setMaxExp(int _MaxExp){maxExp=_MaxExp;}

 /////
    person0::person0(int _shenasep){
       struct personinper p;


    QFile infile("person.txt");//for reading.

    infile.open(QIODevice::ReadOnly);
     if(infile.isOpen()){


    while(!infile.atEnd()){
        QDataStream in(&infile);
        in>>p;
           if(_shenasep==p.shenaseP){
              name=p.name;
              pass=p.pass;
              username=p.username;
              email=p.email;
              coin=p.coin;
              exp=p.exp;
              level=p.level;
              shenaseP=p.shenaseP;
              maxExp=p.maxExp;
              day=p.day;
              break;
           }
          }


    infile.close();

     }
    }
    QString person0::getName(){return name;}

    QString person0::getUsername(){return username;}

    QString person0::getEmail(){return email;}

    int person0::getShenaseP(){return shenaseP;}

    int person0::changeCoin(int _coin){
      return coin+=_coin;
    }

    int person0::changeExp(int _Exp){
        return exp+=_Exp;
    }

    int person0::changeLevel(){
        if(exp==maxExp){
         level++;
         maxExp=2*maxExp+10;
         return level;
        }
        return 0;
    }

    int person0::getMaxExp(){return maxExp;}

    int person0::getExp(){return exp;}

    int person0::getCoin(){return coin;}

    int person0::getLevel(){return level;}
