#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>

class Personnel
{
public:
    Personnel();
    Personnel(long,QString,QString,QString);
    int get_cin();
    QString getnom();
    QString getprenom();
    QString getemail();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setemail(QString);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
private:
int cin;
  QString nom;
  QString prenom;
  QString email;



};

#endif // PERSONNEL_H
