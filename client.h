#ifndef MARKETING_H
#define MARKETING_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class client
{
private:
    int id,cin;
    QString nom,prenom,adresse,tel,sexe;
public:
    client();
    client(int,int,QString,QString,QString,QString,QString);
    QString getnom(){return nom;}
      QString getprenom(){return prenom;}
      QString getadresse(){return adresse;}
        QString gettel(){return tel;}
        QString getsexe(){return sexe;}
      int getid(){return id;}

      int getcin(){return cin;}
      void setnom(QString n){nom=n;}
          void setprenom(QString p){prenom=p;}
          void setadresse(QString a){adresse=a;}
              void settel(QString t){tel=t;}
              void setsexe(QString s){sexe=s;}
          void setid(int i){this->id=i;}
          void setcin(int c){cin=c;}
          bool ajouter();
              bool modifier();

              QSqlQueryModel * afficher();
              bool supprimer(int);
              QSqlQueryModel * AfficherTrieID();
              QSqlQueryModel * rechercherID(QString);
              QString  apercu_pdf();

};

#endif
