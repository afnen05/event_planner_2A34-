#ifndef SP_H
#define SP_H
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QDate>
#include"personnel.h"
class sp
{
public:
    sp();
    sp(int,QString,QString);
    int getcin();
    QString getsalaire();
    QString getprime();
    void setcin(int);
    void setsalaire(QString);
    void setprime(QString);
    bool ajout();
    void calcule_prime(int,float,float);
    float calcule_primee(float b, float a, QString salaire, int n,int somme);
  QSqlQuery calcule_prix_total(int);
  QSqlQuery salaire_distinct(int);
  bool update_prime(int,float ,float ,QString ,int ,int);
  Personnel p;
private:
    int cin;
    QString salaire;
    QString prime;
};

#endif // SP_H
