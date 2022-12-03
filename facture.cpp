#include "facture.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

facture::facture()
{
    n_facture="",date="",offre="";
}
facture::facture(QString n_facture,QString date,QString offre)
{ this->n_facture=n_facture;

  this->date=date;
  this->offre=offre;
}
QString facture:: getNfacture(){return n_facture;}

QString facture:: getdate(){return date;}
QString facture:: getid_offre(){return offre;}

void facture::setNfacture(QString n_facture){this->n_facture=n_facture;}
void facture::setdate(QString date){this->date=date;}
void facture::setid_offre(QString offre){this->offre=offre;}

 bool facture::ajouter()
 {
     QSqlQuery query;

     /*QString n_facture_string=QString::(n_facture);
     QString id_event_string=QString::number(id_event);
      QString date_string=QString::number(DATEE);
     QString offre_string=QString::number(offre);*/


      query.prepare("INSERT INTO FACTURE(ID_FACTURE,DATEE,OFFRE)"
                    "VALUES (:ID_FACTURE,:DATEE,:OFFRE)");
      query.bindValue(":ID_FACTURE", n_facture);
      query.bindValue(":DATEE", date);
      query.bindValue(":OFFRE", offre);


      return query.exec();
 }
bool facture::supprimer(QString n_facture)
{
    QSqlQuery query;

    query.prepare("Delete from FACTURE where ID_FACTURE=:ID_FACTURE");
    query.bindValue(0, n_facture );

    return query.exec();
}

QSqlQueryModel * facture::afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT ID_FACTURE, DATEE, OFFRE FROM FACTURE");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("N_FACTURE"));

     model->setHeaderData(1, Qt::Horizontal,QObject::tr("DATEE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("OFFRE"));
            return model;
}
bool facture::modifier(QString n_facture,QString date,QString offre)
{
    QSqlQuery query ;
    /*  QString n_facture_string = QString::number(N_FACTURE);
      QString id_event_string = QString::number(ID_EVENT);
       QString date_string = QString::number(DATEE);
      QString offre_string = QString::number(OFFRE);*/

    query.prepare("update FACTURE set  DATEE=:DATEE,  OFFRE=:OFFRE, where ID_FACTURE=:ID_FACTURE");


    query.bindValue(":DATEE",date);
    query.bindValue(":OFFRE",offre);

    return query.exec();
}






