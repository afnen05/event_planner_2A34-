#include "facture.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>

facture::facture()
{
    n_facture="",date="",offre="";
}
facture::facture(QString n_facture,QString date,QString offre, int tva, int prix)
{ this->n_facture=n_facture;

  this->date=date;
  this->offre=offre;
    this->TVA = tva;
    this->prix = prix;
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


      query.prepare("INSERT INTO FACTURE(ID_FACTURE,DATEE,OFFRE,TVA,PRIX)"
                    "VALUES (:ID_FACTURE,:DATEE,:OFFRE,:TVA,:PRIX)");
      query.bindValue(":ID_FACTURE", n_facture);
      query.bindValue(":DATEE", date);
      query.bindValue(":OFFRE", offre);
      query.bindValue(":TVA", TVA);
      query.bindValue(":PRIX", prix);


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
    model->setQuery("SELECT * FROM FACTURE");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("N_FACTURE"));

     model->setHeaderData(1, Qt::Horizontal,QObject::tr("DATEE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("OFFRE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("TVA"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("PRIX"));


    return model;
}

QSqlQueryModel * facture::afficher_remboursement()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM REMBOURSEMENT");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));

     model->setHeaderData(1, Qt::Horizontal,QObject::tr("VALUE"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("N_FACTURE"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("POURCENTAGE"));


    return model;
}




QSqlQueryModel * facture::getEvents()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM EVENEMENT");
            return model;
}
bool facture::modifier()
{
    QSqlQuery query ;

    query.prepare("UPDATE FACTURE SET  DATEE=:DATEE,  OFFRE=:OFFRE , TVA=:TVA , PRIX=:PRIX where ID_FACTURE=:n_facture");

    query.bindValue(":n_facture",n_facture);
    query.bindValue(":DATEE",date);
    query.bindValue(":OFFRE",offre);
    query.bindValue(":TVA",TVA);
    query.bindValue(":PRIX",prix);

    return query.exec();
}

QSqlQueryModel * facture::trier(QString ch)
{

    QSqlQueryModel * model=new QSqlQueryModel();
     QString query="SELECT * FROM FACTURE ORDER BY "+ch+" ASC";
     model->setQuery(query);
    return model;
}

QSqlQueryModel * facture::rechercher(QString a)
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM FACTURE WHERE ID_FACTURE LIKE '%"+a+"%' OR PRIX LIKE '%"+a+"%' OR OFFRE LIKE '%"+a+"%' ");
    return model;
}

bool facture::ajouter_remboursement (int id_facture,int pourcentage,int value){
    QSqlQuery query;


     query.prepare("INSERT INTO REMBOURSEMENT(ID_FACTURE,POURCENTAGE,VALUE)"
                   "VALUES (:ID_FACTURE,:POURCENTAGE,:VALUE)");

     query.bindValue(":ID_FACTURE", id_facture);
     query.bindValue(":VALUE", value);
      query.bindValue(":POURCENTAGE", pourcentage);

     return query.exec();
}

bool facture::supprimer_remboursement(int id)
{
    QSqlQuery query;

    query.prepare("Delete from REMBOURSEMENT where ID=:id");
    query.bindValue(0, id );

    return query.exec();
}
