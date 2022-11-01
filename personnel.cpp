#include "personnel.h"
#include<QSqlDatabase>
#include<QObject>
Personnel::Personnel()
{
cin=0;
nom=" ";
prenom=" ";
email="";
}
Personnel::Personnel(long cin ,QString nom,QString prenom,QString email)
{

  this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;

}
int Personnel::get_cin()
{
    return cin;
}
QString Personnel::getnom()
{
    return nom;
}
QString Personnel:: getprenom()
{
    return prenom;
}
QString Personnel::getemail()
{
    return email;
}
void Personnel::setid(int cin)
{
    this->cin=cin;

}
void Personnel:: setnom(QString nom)
{
    this->nom=nom;
}
void Personnel::setprenom(QString prenom)
{
    this->prenom=prenom;
}
void Personnel::setemail(QString email)
{
    this->email=email;
}
bool Personnel::ajouter()
{

 QSqlQuery query;
 QString cin_string=QString::number(cin);
    query.prepare("INSERT INTO PERSONNEL (cin, nom, prenom,email) "
                  "VALUES (:cin, :nom, :prenom,:email)");
    query.bindValue(":cin",cin );
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
        query.bindValue(":email", email);
   return  query.exec();

}

bool Personnel::supprimer(int cin)
{
    QSqlQuery query;
    QString cin_string=QString::number(cin);
       query.prepare("Delete from Personnel where cin=:cin");
       query.bindValue(":cin",cin);
      return  query.exec();

}

QSqlQueryModel* Personnel::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM personnel");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
return model;
}
