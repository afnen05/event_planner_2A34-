#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include <QDateEdit>
#include <QMessageBox>
#include <QIntValidator>
#include <QValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRegularExpression rnumber("\\b([0-9][0-9][-][0-9][0-9][-][0-9][0-9][0-9][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionValidator *valnumber = new QRegularExpressionValidator(rnumber,this);
             ui->date_ev->setValidator(valnumber);

             QRegularExpression r2number("\\b([a-zA-Z])([a-zA-Z0-9])*\\b",QRegularExpression::CaseInsensitiveOption);
                   QRegularExpressionValidator *val1 = new QRegularExpressionValidator(r2number,this);
                    ui->nom_ev->setValidator(val1);
ui->tab_ev->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_push1_clicked()
{

     QString CIN_CL=ui->cin_c->text();
     QString NOM=ui->nom_ev->text();
     QString DATE_EV=ui->date_ev->text();
     Event E(CIN_CL,DATE_EV,NOM);
     bool test= E.ajouter();
     if (test){
         QMessageBox::information(nullptr, QObject::tr(" OK"),
                     QObject::tr("Ajout successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tab_ev->setModel(E.afficher());


     }
     else
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                     QObject::tr("Ajout failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_supprimer_clicked()
{ Event E1;
    E1.setnom(ui->sup->text());
    bool test=E1.supprimer(E1.getnom());
    if (test){
        QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("Delete successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_ev->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Delete failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_Modifier_clicked()
{
    Event E3;
        QString NOM=ui->L1->text();
        QString DATE_Ev=ui->L2->text();
        QString CIN_CL=ui->L3->text();
         bool test=E3.Modifier(CIN_CL,DATE_Ev,NOM);
         if (test){
             QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("modifier successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
         {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("modifier failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}
}
