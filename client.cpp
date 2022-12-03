#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
client::client()
{
    id=0;
    cin=0;
       sexe="";
       nom="";
       prenom="";
       adresse="";
       tel="";

}
client::client(int id,int cin,QString sexe,QString nom,QString prenom,QString adresse,QString tel)
{

    this->id=id;
   this->cin=cin;
    this->sexe=sexe;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->tel=tel;

}
bool client::ajouter()
{
    QSqlQuery query;
    QString res1 = QString::number(id);
    QString res2 = QString::number(cin);



    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Clients(id,cin,sexe,nom,prenom,adresse,tel)""values( :id, :cin, :sexe, :nom, :prenom, :adresse, :tel)");

    //Création des variables liées
    query.bindValue(":id",id);
    query.bindValue(":cin",cin);
    query.bindValue(":sexe",sexe);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",tel);



    return query.exec();//exec() envoie la requête pour l'exécution





}
bool client::modifier()
{
    QSqlQuery query ;
    QSqlQuery query1;
    int b=0;
    QString res1 = QString::number(id);
    QString res2 = QString::number(cin);

    query1.prepare("SELECT id FROM Clients WHERE id=:idA");
    query1.bindValue(":idA",res1);
    query1.exec();
    while(query1.next())
    {
        b++;
    }

    if (b!=0)
    {
    query.prepare("UPDATE Clients set id = :id, cin = :cin,sexe = :sexe,nom=:nom,prenom = :prenom,adresse=:adresse,tel=:tel WHERE id=:id");
    query.bindValue(":id",res1);
    query.bindValue(":cin",res2);
    query.bindValue(":sexe",sexe);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",tel);

    return query.exec();//exec() envoie la requête pour l'exécution
}
    else
    {
        return false;
    }
}





QSqlQueryModel * client ::afficher()
{


QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from Clients");
return model;

}




bool client::supprimer(int idA)
{

               QSqlQuery query;
               QSqlQuery query1;
               int b=0;
               QString res=QString::number(idA);

               query1.prepare("SELECT id FROM Clients WHERE id=:idA");
               query1.bindValue(":idA",res);
               query1.exec();
               while(query1.next())
               {
                   b++;
               }

               if (b!=0)
               {


               query.prepare("Delete from Clients where id=:idA");
               query.bindValue(":idA",res);
               return query.exec(); }

               else
               {
                   return false;
               }
    }
QSqlQueryModel * client::AfficherTrieID()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Clients ORDER BY id");

    return model;
}




QSqlQueryModel * client::rechercherID(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Clients where id like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}
QString client:: apercu_pdf()
 {
    QString text="          ****** clients  ******      \n \n " ;
     QSqlQuery query ;
     QString i,x,z,a,e,r,t;


      query.exec("select * from Clients  ");
      while (query.next())
      {
         i=query.value(0).toString();
         x=query.value(1).toString();
         z=query.value(2).toString();
         a=query.value(3).toString();
         e=query.value(4).toString();
         r=query.value(5).toString();
         t=query.value(6).toString();

        text += "\n id  : "+i+"\n\n - cin : "+ x+"\n - sexe : "+ z+"\n - nom:"+a+"\n - prenom : "+ e+"\n - adresse : "+ r+"\n - tel:"+t+"\n"  ;


     }

             return text ;
 }




