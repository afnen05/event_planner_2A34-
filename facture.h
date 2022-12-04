#ifndef FACTURE_H
#define FACTURE_H
#include <QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QCalendarWidget>
#include <QTextCharFormat>
#include<QMessageBox>

class facture
{
public:
    facture();
    facture(QString,QString,QString,int,int);
    QString getNfacture();
    QString getid_event();
    QString getid_offre();
    QString getdate();

    void setNfacture(QString);
    void setid_event(QString);
    void setid_offre(QString);
    void setdate(QString);

    bool ajouter ();
    bool ajouter_remboursement (int,int,int);
    bool supprimer_remboursement(int);
    QSqlQueryModel * afficher_remboursement();
    QSqlQueryModel * afficher();
    QSqlQueryModel * getEvents();
    bool supprimer(QString);
    bool modifier();

    QSqlQueryModel * trier(QString);
    QSqlQueryModel * rechercher(QString );

private:
    QString n_facture;

    QString date;
    QString offre;
    int TVA;
    int prix;

};

#endif // FACTURE_H
