#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "facture.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->nf->setValidator(new QIntValidator(1, 1000000000, this));
    QRegularExpression rnumber("\\b([0-3][0-9][-][0-1][0-9][-][0-9][0-9][0-9][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionValidator *valnumber = new QRegularExpressionValidator(rnumber,this);
             ui->da->setValidator(valnumber);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    QString n_facture=ui->nf->text();
     QString offre=ui->off->text();
     QString date=ui->da->text();
    facture fac(n_facture,date,offre);
     bool test=fac.ajouter();
      MainWindow w;
      if(test)
      {ui->tab_fac ->setModel(fac.afficher());
          QMessageBox::information(nullptr, QObject::tr("Ajouter"),
                      QObject::tr("ajout avec succes.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
      }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                       QObject::tr("echec d ajout.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pb_supprimer_clicked()
{
    facture f1;
    f1.setNfacture(ui->supp->text());
    bool test=f1.supprimer(f1.getNfacture());

    QMessageBox msgBox;
    if(test)
        msgBox.setText("Suppression avec succes");
     else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}


void MainWindow::on_modifier_clicked()
{     facture f2;
      QSqlQuery query;
    QString n_facture=ui->nf2->text();

    QString offre=ui->off2->text();
    QString date=ui->da2->text();
      facture fac2(n_facture,offre,date);
        bool test;
        test= fac2.modifier(n_facture,offre,date);
          query.prepare("UPDATE FACTURE SET DATEE='"+date+"',OFFRE='"+offre+"''WHERE ID_FACTURE=:ID_FACTURE");
                  query.bindValue(":ID_FACTURE",n_facture);
       if (test)

          {
           ui->tab_fac->setModel(fac2.afficher());
           QMessageBox::information(nullptr, QObject::tr("MODIFIER"),
                                         QObject::tr("MODIFICATION avec succes .\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

           }
                         else
                             QMessageBox::critical(nullptr, QObject::tr("MODIFIER"),
                                         QObject::tr("UPDATE failed.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);
}
