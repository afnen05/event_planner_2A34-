#include "event.h"
#include <QString>
#include <QSqlQuery>
#include<QSqlError>
#include <QDebug>
#include <QObject>
#include <map>

Event::Event()
{
 NOM="";CIN_CL="" ;DATE_EV=""; ID="";
PRIX=0; CIN_PERSO="";}

Event::Event(QString NOM,QString CIN_CL,QString DATE_EV,int PRIX){
     this->NOM=NOM; this->CIN_CL=CIN_CL; this->DATE_EV=DATE_EV;this->PRIX=PRIX;}
QString Event::getnom(){return NOM;}
QString Event::getid(){return ID;}
QString Event::getcin(){return CIN_CL;}
QString Event::getdate(){return DATE_EV;}
QString Event::getcin_perso(){return CIN_PERSO;}
int Event::getprix(){return  PRIX;}
//setter
void Event::setcin(QString CIN_CL){this->CIN_CL=CIN_CL;}
void Event::setid(QString ID){this->ID=ID;}
void Event::setnom(QString NOM){this->NOM=NOM;}
void Event::setdate(QString DATE_EV){this->DATE_EV=DATE_EV;}
void Event::setprix(int PRIX){this->PRIX=PRIX;}
void Event::setcin_perso(QString CIN_PERSO){this->CIN_PERSO=CIN_PERSO;}



bool Event::ajouter(){
 bool test =true ;
    QSqlQuery query;
          query.prepare("INSERT INTO EVENEMENT (CIN_CL,DATE_EV,NOM,PRIX,CIN_PERSO) "
                        "VALUES (:CIN_CL, :DATE_EV, :NOM, :PRIX,:CIN_PERSO)");
          query.bindValue(":CIN_CL",CIN_CL);
          query.bindValue(":DATE_EV",DATE_EV);
          query.bindValue(":NOM",NOM);
          query.bindValue(":PRIX",PRIX);
          query.bindValue(":CIN_PERSO",CIN_PERSO);

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
           model->setHeaderData(3, Qt::Horizontal,QObject::tr("PRIX"));
           model->setHeaderData(4, Qt::Horizontal,QObject::tr("CIN_PERSO"));








           return model;


}

bool Event::supprimer(QString NOM){
    QSqlQuery query;
    query.prepare("Delete from EVENEMENT where NOM=:NOM");
    query.bindValue(":NOM",NOM);
    return query.exec();
}





bool Event::Modifier(QString CIN_CL,QString DATE_EV,QString NOM,int PRIX)
{
    QSqlQuery query;

    query.prepare("UPDATE EVENEMENT SET CIN_CL=:CIN_CL, DATE_EV=:DATE_EV ,PRIX=PRIX  WHERE NOM=:NOM");
    query.bindValue(":CIN_CL", CIN_CL);
    query.bindValue(":NOM", NOM);
    query.bindValue(":DATE_EV", DATE_EV);
    query.bindValue(":PRIX",PRIX);

    return  query.exec();
     qDebug() << PRIX << "PRIX" << ID << "ID";
    }

void Event::rechercher(QString a,QTableView *g)
{ {QSqlQuery query;
         QSqlQueryModel *m=new QSqlQueryModel();//initialisation
         query.prepare("select * from EVENEMENT where ID like'%"+a+"%'");
                     query.exec();
                 m->setQuery(query);
        g->setModel(m);


     }}



QSqlQueryModel* Event:: afficher_tri_nom()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EVENEMENT order by PRIX");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATE_EV"));

    return model;
}

QSqlQueryModel* Event:: afficher_tri_nom_DESC()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EVENEMENT order by NOM desc");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATE_EV"));

    return model;
}
QSqlQueryModel* Event:: afficher_tri_nom_ASC()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from EVENEMENT order by NOM asc");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("PRIX"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("DATE_EV"));

    return model;
}

bool Event::annulation(QString ID){

    QSqlQuery query;


         query.prepare("Delete from EVENEMENT where ID=:ID" ) ;



         query.bindValue(":ID", ID);
         query.prepare("UPDATE EVENEMENT SET PENALITE='1' (WHERE ID=:ID)");
         query.bindValue(":ID", ID);

      return query.exec();



}
bool Event::reportor(QString DATE_EV,QString ID)
{
    try{
        QSqlQuery query;
        QSqlQuery query1;
        query.prepare("SELECT DATE_EV FROM EVENEMENT WHERE DATE_EV LIKE :DATE_EV");
        query.bindValue(":DATE_EV",DATE_EV);

        int index = 0;
        if(query.exec()){
        while(query.next()){
            index++;
            qDebug() << index << "index";
        }
        if(index != 0){
            return false;
        }else {
            qDebug() << DATE_EV << "date" << ID << "ID";
            query1.prepare("UPDATE evenement SET date_ev=:date WHERE ID LIKE :id");
            query1.bindValue(":date",DATE_EV);
            query1.bindValue(":id",ID);
            qDebug() << query1.exec() << "exec result";
            qDebug() << query1.lastError() << "last Error";
        }
        }else {
            return false;
        }
    }catch(...){
        return false;
    }

}

std::map<QString,int> Event::statNbrPerType(){
    QSqlQuery query;
    std::map <QString,int> list;
    try {
        query.prepare("SELECT SUM(PRIX) ,DATE_EV from EVENEMENT GROUP BY DATE_EV");
        if(query.exec()){
            while (query.next()) {
                query.value('s').toInt();
                list.insert({query.value(1).toString() , query.value(0).toInt()});
            }
        return list;
        }



    } catch (...) {
        list["error"] = 0;
        return  list;
    }

}






