#include "Mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include"dialog.h"
#include "menu.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
    Dialog d;
    MENU m;
    bool test=c.createconnect();
    if(test)
    {m.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


//w.affichage();
    return a.exec();

}
