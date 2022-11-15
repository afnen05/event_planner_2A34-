#include "personnel.h"
#include<QSqlDatabase>
#include<QObject>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
Personnel::Personnel()
{
cin=0;
nom=" ";
prenom=" ";
email="";
type="";
mdp="";
}
Personnel::Personnel(int cin ,QString nom,QString prenom,QString email,QString type,QString mdp)
{

  this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->type=type;
    this->mdp=mdp;

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
QString Personnel::gettype()
{
    return type;
}
QString Personnel::getmdp()
{
    return mdp;
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
void Personnel::settype(QString type)
{
    this->type=type;
}
bool Personnel::ajouter()
{
QString cin_string=QString::number(cin);
    QSqlQuery query;
    query.prepare("INSERT INTO PERSONNEL (cin, nom, prenom,email,type,mdp) "
                  "VALUES (:cin,:nom, :prenom,:email,:type,:mdp)");
   query.bindValue(":cin",cin);
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":email",email);
   query.bindValue(":type",type);
     query.bindValue(":mdp",mdp);
   return  query.exec();

}

bool Personnel::supprimer(int cin)
{
     QSqlQuery query;
     QString cin_string=QString::number(cin);
       query.prepare("Delete from Personnel where cin=:cin");
       query.bindValue(":cin",cin);
      return query.exec();

}
bool Personnel::modifier(int cin )
{
 QSqlQuery q;
 q.prepare("update personnel set  cin=:cin,nom='"+nom+"',prenom='"+prenom+"',email='"+email+"',type='"+type+"',mdp='"+mdp+"'where cin=:cin " );
q.bindValue(":cin",cin);
 return q.exec();
}

float Personnel::calcule_prime(float b, float a, QString salaire, int n,int somme)
{
float sal;
sal=salaire.toFloat();
    float s,s1;
    s=somme/n;
    return( s1=(b*sal)+(s*a));
}
QSqlQuery Personnel::recherche(int cin)
{
QSqlQuery qry;
 qry.prepare("select * from personnel where cin=:cin");
 qry.bindValue(":cin",cin);
 return qry;
}
QSqlQuery Personnel::tri()
{
QSqlQuery qry;
 qry.prepare("select * from personnel ORDER BY nom");
 return qry;
}
QSqlQuery Personnel::tab_afficher(QString val)
{
QSqlQuery qry;
 qry.prepare("select * from personnel where cin=:val");
 qry.bindValue(":val",val);
 return qry;
}
