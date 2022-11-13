#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QDate>

class Personnel
{
public:
    Personnel();
    Personnel(int,QString,QString,QString,float,float);
    int get_cin();
    QString getnom();
    QString getprenom();
    QString getemail();
    int getsalaire();
    float getprime();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setsalaire(float);
    void setprime(float);
    bool ajouter();
    //QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);

    float calcule_prime(float,float,QString,int,int);

private:
int cin;
  QString nom;
  QString prenom;
  QString email;
  int salaire;
 float prime;
  QDate date_debut;
  QDate date_retour;
  QString confirmation="en attente";

};

#endif // PERSONNEL_H
