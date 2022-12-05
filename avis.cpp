#include"avis.h"
#include <QSqlQueryModel>
#include<QtDebug>
#include<QObject>
#include<QMessageBox>
#include <QSqlQuery>
#include "smtp.h"


avis::avis()
{
        nom="";
        prenom= "";
        avis_client= "";
        id =0;
        cin=  0;
        note=0  ;
}
avis::avis(int id ,int cin, int note , QString nom,QString prenom,QString avis_client)
{   this->id=id;
     this->cin=cin;
     this->note=note;
     this->nom=nom;
     this->prenom=prenom;
     this->avis_client=avis_client;
}
int avis:: getid(){return id;}
int avis:: getcin(){return cin;}
int avis:: getnote(){return note;}
QString  avis:: getnom(){return nom;}
QString  avis:: getprenom(){return prenom;}
QString  avis:: getavis_client(){return avis_client;}
void avis::setid(int id){this->id=id;}
void avis::setcin(int cin){this->cin=cin;}
void avis::setnote(int note){this->note=note;}
void avis::setnom(QString nom){this->nom=nom;}
void avis::setprenom(QString prenom){this->prenom=prenom;}

bool avis::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(id);
    QString cin_string=QString::number(cin);
     QString note_string=QString::number(note);

          query.prepare("INSERT INTO avis (id,nom,cin,prenom,avis_client) "
                        "VALUES (:id,:nom,:cin,:prenom,:avis_client )");
          query.bindValue(":id", id_string);
          query.bindValue(":cin", cin_string);
          query.bindValue(":note", note_string);
          query.bindValue(":avis_client", avis_client);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);

          return query.exec();


}

QSqlQueryModel* avis::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();

model->setQuery("SELECT* FROM avis");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("avis_client"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("cin"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("note"));




return model;
}

bool avis::supprimer(int id ){

    QSqlQuery query;


          query.prepare(" Delete from avis where id=:id");

          query.bindValue(0, id);
          query.bindValue(":cin", cin);
          query.bindValue(":note", note);
          query.bindValue(":avis_client", avis_client);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);

          return query.exec();

}

QSqlQueryModel * avis::rechercherNom(QString nom)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from avis where nom like '%" +nom+"%'");
    return model;
}


bool avis::modifier()
    {
    QSqlQuery query;

        QString id_string=QString::number(id);


          QSqlQuery queryr;


          QSqlQueryModel *modelr= new QSqlQueryModel();


          queryr.prepare("SELECT * FROM aviss WHERE (identifiant  LIKE "+id_string+  ")");
          if(queryr.exec()){
          modelr->setQuery(queryr);
          }


      if(queryr.exec()){
      modelr->setQuery(queryr);
      }



          if(queryr.numRowsAffected()==0){
             QMessageBox::warning(nullptr, QObject::tr("database is open"),
                         QObject::tr("avis introvale .\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);


        }



          else{

    QSqlQuery query;
    QString id_string=QString::number(id);
    QString cin_string=QString::number(cin);

    query.prepare("UPDATE aviss SET prenom=:prenom,cin=:cin,nom=:nom,avis_client=avis_client WHERE idd=:id;");

    query.bindValue(":id",id_string);
        query.bindValue(":cin",cin_string);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":avis_client",avis_client);







    return    query.exec();}
    return false;
    }

QSqlQueryModel * avis::trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from avis order by nom");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("avis_client"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("note"));


    return model;
}



