#ifndef AVIS_H
#define AVIS_H
#include<QString>
#include<QSqlQueryModel>
#include<QTableView>
#include<QMessageBox>

class avis
{private:
    QString nom;
    QString prenom;
    int cin;
    int id;
    int note;
    QString avis_client;
public:
    avis();
    avis(int , int ,int, QString ,QString ,QString );


    int getcin() ;
    int getid() ;
    int getnote() ;
    QString getnom();
    QString getprenom();
    QString getavis_client();
    void setid(int id);
    void setcin(int cin);
    void setnote(int note);
    void setprenom(QString);
    void setnom(QString);
    void setavis_client(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int id );
    QSqlQueryModel * rechercherNom(QString);
    bool modifier();
    QSqlQueryModel * trier();


};

#endif // AVIS_H
