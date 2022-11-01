#include "event.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlError>
#include <QDebug>
#include <QObject>
Event::Event()
{
 NOM="";CIN_CL="" ;DATE_EV="";}

Event::Event(QString NOM,QString CIN_CL,QString DATE_EV){
     this->NOM=NOM; this->CIN_CL=CIN_CL; this->DATE_EV=DATE_EV;}
QString Event::getnom(){return NOM;}
QString Event::getcin(){return CIN_CL;}
QString Event::getdate(){return DATE_EV;}
//setter
void Event::setcin(QString CIN_CL){this->CIN_CL=CIN_CL;}
void Event::setnom(QString NOM){this->NOM=NOM;}
void Event::setdate(QString DATE_EV){this->DATE_EV=DATE_EV;}
bool Event::ajouter(){
bool test =true ;
    QSqlQuery query;
          query.prepare("INSERT INTO EVENEMENT (CIN_CL,DATE_EV,NOM) "
                        "VALUES (:CIN_CL, :DATE_EV, :NOM)");
          query.bindValue(":CIN_CL",CIN_CL);
          query.bindValue(":DATE_EV",DATE_EV);
          query.bindValue(":NOM",NOM);
          query.exec();
          qDebug() <<query.lastError();
    return  test;
};

QSqlQueryModel* Event::afficher(){
    QSqlQueryModel* model=new QSqlQueryModel();


    model->setQuery("SELECT* FROM EVENEMENT");
           model->setHeaderData(0, Qt::Horizontal,QObject::tr("DATE_EV"));
           model->setHeaderData(1, Qt::Horizontal,QObject::tr("CIN_CL"));
           model->setHeaderData(2, Qt::Horizontal,QObject::tr("NOM"));




           return model;


}

bool Event::supprimer(QString NOM){
    QSqlQuery query;
    query.prepare("Delete from EVENEMENT where NOM=:NOM");
    query.bindValue(":NOM",NOM);
    return query.exec();
}





bool Event::Modifier(QString CIN_CL,QString DATE_EV,QString NOM)
{
    QSqlQuery query;

    query.prepare("UPDATE EVENEMENT SET CIN_CL=:CIN_CL, DATE_EV=:DATE_EV  WHERE NOM=:NOM");
    query.bindValue(":CIN_CL", CIN_CL);
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATE_EV", DATE_EV);

    return  query.exec();
    }














