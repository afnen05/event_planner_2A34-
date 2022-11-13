#include "personnel.h"
#include<QSqlDatabase>
#include<QObject>
Personnel::Personnel()
{
cin=0;
nom=" ";
prenom=" ";
email="";
salaire=0.0;
prime=0.0;
}
Personnel::Personnel(int cin ,QString nom,QString prenom,QString email,float salaire,float prime)
{

  this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->email=email;
    this->salaire=salaire;
    this->prime=prime;

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
int Personnel::getsalaire()
{
    return salaire;

}
float Personnel::getprime()
{

    return prime;
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
void Personnel::setsalaire(float salaire)
{

    this->salaire=salaire;
}
void Personnel::setprime(float prime)
{
    this->prime=prime;
}
bool Personnel::ajouter()
{

    QSqlQuery query;
    query.prepare("INSERT INTO PERSONNEL (cin, nom, prenom,salaire,prime,email) "
                  "VALUES (:cin,:nom, :prenom,:salaire,:prime,:email)");
   query.bindValue(":cin",cin);
   query.bindValue(":nom", nom);
   query.bindValue(":prenom", prenom);
   query.bindValue(":salaire", salaire);
   query.bindValue(":prime", prime);
     query.bindValue(":email", email);
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

float Personnel::calcule_prime(float b, float a, QString salaire, int n,int somme)
{
float sal;
sal=salaire.toFloat();
    float s,s1;
    s=somme/n;
    return( s1=(b*sal)+(s*a));


}
