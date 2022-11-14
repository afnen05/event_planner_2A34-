#include "connexion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Project2A");
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("025879");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

