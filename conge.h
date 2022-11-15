#ifndef CONGE_H
#define CONGE_H
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QDate>
class conge
{
public:
    conge();
    conge(int,QString,QString,QString);
    int getcin();
    QString getdate_debut();
    QString getdate_retour();
    QString getetat();
    void setcin(int);
    void setdate_debut(QString);
    void setdate_retour(QString);
    void seteta(QString);
    bool ajouter();
    bool supprimer(int);
    bool modifier(int);
    bool refuser(int);
private:
 int cin;
 QString date_debut;
 QString date_retour;
 QString etat;
};

#endif // CONGE_H
