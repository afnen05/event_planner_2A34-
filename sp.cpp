#include "sp.h"
#include<QMessageBox>

sp::sp()
{
cin=0;
salaire="";
prime="";
}
sp::sp(int cin,QString salaire,QString prime)
{
    this->cin=cin;
    this->salaire=salaire;
    this->prime=prime;
}
bool sp::ajout()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO salairee (cin,salaire,prime)"
                "VALUES(:cin,:salaire,:prime)");
    qry.bindValue(":cin",cin);
    qry.bindValue(":salaire",salaire);
    qry.bindValue(":prime",prime);
    return qry.exec();
}
QSqlQuery sp::calcule_prix_total(int cin)
{

    QSqlQuery qry;
    qry.prepare("SELECT SUM (prix) FROM evenment WHERE cin=:cin");
     qry.bindValue(":cin",cin);
     return qry;
}
QSqlQuery sp::salaire_distinct(int cin)
{
    QSqlQuery qry;
    qry.prepare("select DISTINCT (salaire)  from salairee where cin=:cin");
     qry.bindValue(":cin",cin);
     return qry;
}
bool sp::update_prime(int cin,float a,float b,QString sal ,int n,int somme)
{
    QSqlQuery qu;
    int prime;
    prime=(p.calcule_prime(a,b,sal,n,somme));

    qu.prepare("update salairee set prime=:prime where cin=:cin");
     qu.bindValue(":cin",cin);
     qu.bindValue(":prime",prime);
     return qu.exec();
}
