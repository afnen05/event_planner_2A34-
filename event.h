#ifndef EVENT_H
#define EVENT_H
#include <QDate>
#include<QString>
#include<QSqlQueryModel>
class Event
{
public:

    Event();
    Event(QString,QString,QString);
    //getter
    //int getid();
    QString getnom();
    QString getcin();
    QString getdate();
    //setter;
    //void setid(int);
    void setnom(QString);
    void setcin(QString);
    void setdate(QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(QString);
    bool Modifier(QString,QString,QString);


private:
    QString NOM,CIN_CL,DATE_EV;

};

#endif // EVENT_H
