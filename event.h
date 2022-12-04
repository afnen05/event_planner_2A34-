#ifndef EVENT_H
#define EVENT_H
#include <QDate>
#include<QString>
#include<QTableView>
#include<QSqlQueryModel>
class Event
{
public:

    Event();
    Event(QString,QString,QString,int);
    //getter
    QString getid();
    QString getnom();
    QString getcin();
    QString getdate();
    QString getcin_perso();
    int getprix();
    //setter;
    void setid(QString);
    void setnom(QString);
    void setcin(QString);
    void setdate(QString);
    void setprix(int);
    void setcin_perso(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool Modifier(QString,QString,QString,int);
    void rechercher(QString a,QTableView *g);
    QSqlQueryModel * afficher_tri_nom();
     QSqlQueryModel * afficher_tri_nom_DESC();
        QSqlQueryModel * afficher_tri_nom_ASC();
        bool annulation(QString);
        bool reportor (QString,QString);
std::map<QString,int> statNbrPerType();


private:
    QString NOM,CIN_CL,DATE_EV,ID,CIN_PERSO;
    int PRIX;

};

#endif // EVENT_H
