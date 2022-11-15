#include "conge.h"

conge::conge()
{
cin=0;
date_debut="";
date_retour="";
etat="";
}
conge::conge(int cin,QString date_debut,QString date_retour,QString etat)
{
    this->cin=cin;
    this->date_debut=date_debut;
    this->date_retour=date_retour;
    this->etat=etat;
}
int conge::getcin()
{return cin ;}
QString conge::getdate_debut()
{
   return date_debut;
}
QString conge::getdate_retour()
{
    return date_retour;
}
QString conge::getetat()
{return etat;}
void conge::setcin(int cin)
{
    this->cin=cin;
}
void conge::setdate_debut(QString date_debut)
{
    this->date_debut=date_debut;
}
void conge::seteta(QString etat)
{this->etat=etat;}
void conge::setdate_retour(QString date_retour)
{this->date_retour=date_retour;}
bool conge::ajouter()
{
    QString cin_string=QString::number(cin);
        QSqlQuery query;
        QString etat="non confirmee";
        query.prepare("INSERT INTO conge (cin,date_debut,date_retour,etat) "
                      "VALUES (:cin,:date_debut,:date_retour,:etat)");
       query.bindValue(":cin",cin);
       query.bindValue(":date_debut", date_debut);
       query.bindValue(":date_retour",date_retour);
       query.bindValue(":etat",etat);
       return  query.exec();

}
bool conge::supprimer(int cin)
{
    QSqlQuery query;
    query.prepare("Delete from conge where cin=:cin");
    query.bindValue(":cin",cin);
    return query.exec();
}
bool conge::modifier(int cin)
{
    QSqlQuery query;
    QString etat="confirmee";
       query.prepare("update conge set  etat=:etat where cin=:cin" );
       query.bindValue(":cin",cin);
       query.bindValue(":etat",etat);
       return query.exec();
}
bool conge::refuser(int cin)
{
    QSqlQuery query;
    QString etat="refuser";
       query.prepare("update conge set  etat=:etat where cin=:cin" );
       query.bindValue(":cin",cin);
       query.bindValue(":etat",etat);
       return query.exec();
}
