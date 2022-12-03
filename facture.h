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
    facture(QString,QString,QString);
    QString getNfacture();
    QString getid_event();
    QString getid_offre();
    QString getdate();

    void setNfacture(QString);
    void setid_event(QString);
    void setid_offre(QString);
    void setdate(QString);

    bool ajouter ();
    QSqlQueryModel * afficher();
    bool supprimer(QString);
    bool modifier(QString,QString,QString);

    QSqlQueryModel * trier(int choix);
    QSqlQueryModel * rechercher(int choix);

private:
    QString n_facture;

    QString date;
    QString offre;

};

#endif // FACTURE_H
