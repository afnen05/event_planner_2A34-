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
    Personnel(int,QString,QString,QString,QString,QString);
    int get_cin();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getmdp();
    QString gettype();
    int getsalaire();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    void setprime(float);
    void setmdp(QString);
    void settype(QString);
    bool ajouter();
    //QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
QSqlQuery recherche(int);
QSqlQuery tri();
QSqlQuery affiher();
QSqlQuery tab_afficher(QString);
bool ajout_conge(int);
    float calcule_prime(float,float,QString,int,int);

private:
  int cin;
  QString nom;
  QString prenom;
  QString email;
  QString type;
  QString mdp;


};

#endif // PERSONNEL_H
