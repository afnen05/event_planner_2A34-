#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"avis.h"
#include"arduino.h"
#include<QIntValidator>
#include<QMessageBox>
#include<QTextDocument>
#include<QSqlQuery>
#include<QTextStream>
#include<QPrintDialog>
#include <QLabel>
#include <QPdfWriter>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QDialog>
#include <QDateEdit>
#include <QtCharts/QChartView>
#include <QPieSlice>
#include <QPieSeries>
#include <QFileDialog>
#include <QDesktopServices>
#include <QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int ret=A1.connect_arduino(); // lancer la connexion à arduino
    switch (ret){
    case (0) :qDebug ()<< "arduino is available and connected to : "<< A1.getarduino_port_name();
         break;
    case (1):qDebug() << "arduino is available but not connected to :" <<A1.getarduino_port_name();
        break;
    case (-1) :qDebug() << "arduino is not available";
    }
     QObject::connect (A1. getserial(), SIGNAL (readyRead ()), this, SLOT (update_label())); // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).


    // the edit lineedit will only accept integers between 100 and 999
    ui->le_id->setValidator(new QIntValidator(0, 999999, this));

    ui->tab_av->setModel(A.afficher());


}


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ajouter_clicked()
{   int id=ui->le_id->text().toInt();
    int cin=ui->le_cin->text().toInt();
    int note=ui->le_note->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString avis_client=ui->avis->text();

    avis A (id,cin,note,nom,prenom,avis_client);
    bool test=A.ajouter();
    QMessageBox msgBox;
    if(test)
    {msgBox.setText("ajout avec succes.");
        ui->tab_av->setModel(A.afficher());}
    else

        msgBox.setText("Echec d'ajout");
    msgBox.exec();
}

void MainWindow::on_supprimer_2_clicked()
{
    avis A1 ;A1.setid(ui->id_sup->text().toInt());
    bool test=A1.supprimer(A1.getid());
    QMessageBox msgBox;
    if(test)
    {msgBox.setText("Suppression avec succes.");
        ui->tab_av->setModel(A.afficher());}
    else

        msgBox.setText("Echec de suppression");
    msgBox.exec();

}






void MainWindow::on_pbpdf_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                               "/home",
                                                               QFileDialog::ShowDirsOnly
                                                               | QFileDialog::DontResolveSymlinks);
                   qDebug()<<dir;
                   QPdfWriter pdf(dir+"/PdfList.pdf");
                                          QPainter painter(&pdf);
                                         int i = 4000;

                                         painter.drawPixmap(QRect(100,100,2000,2000),QPixmap("C:/Users/Admin/Desktop/logo.png"));
                                             painter.drawText(900,650,"ahmed drid");

                                              //painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Users/Admin/Desktop/logo.png"));

                                              painter.setPen(Qt::blue);
                                              painter.setFont(QFont("Time New Roman", 25));
                                              painter.drawText(3000,1400,"Liste Des avis");
                                              painter.setPen(Qt::black);
                                              painter.setFont(QFont("Time New Roman", 15));
                                              painter.drawRect(100,100,9400,2500);
                                              painter.drawRect(100,3000,9400,500);
                                              painter.setFont(QFont("Time New Roman", 9));
                                              painter.drawText(300,3300,"identifiant");
                                              painter.drawText(2300,3300,"Prenom");
                                              painter.drawText(4300,3300,"Nom");
                                              painter.drawText(6300,3300,"mot de passe");
                                              painter.drawText(7500,3300,"type");

                                              painter.drawRect(100,3000,9400,10700);


                                              QTextDocument previewDoc;
                                              QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");


                                              QTextCursor cursor(&previewDoc);



                                              QSqlQuery query;
                                              query.prepare("select * from avis");
                                              query.exec();
                                              while (query.next())
                                              {
                                                  painter.drawText(300,i,query.value(0).toString());
                                                  painter.drawText(2300,i,query.value(1).toString());
                                                  painter.drawText(4300,i,query.value(2).toString());
                                                  painter.drawText(6300,i,query.value(3).toString());
                                                  painter.drawText(7500,i,query.value(4).toString());
                                                 /* painter.drawText(8500,i,query.value(5).toString());
                                                  painter.drawText(9500,i,query.value(6).toString());
                                                  painter.drawText(10500,i,query.value(7).toString());*/




                                                 i = i +500;
                                              }
                                              int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                                  QMessageBox::Yes|QMessageBox::No);
                                                  if (reponse == QMessageBox::Yes)
                                                  {
                                                      QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                      painter.end();
                                                  }
                                                  else
                                                  {
                                                       painter.end();
         }

    }






void MainWindow::on_le_nom_2_textChanged(const QString &nom)//recherche
{
    ui->tableView->setModel(A.rechercherNom(nom));
}

void MainWindow::on_pushButton_clicked()//TRIS
{
    QSqlQueryModel * model=new QSqlQueryModel();
        model->setQuery("select * from avis  ORDER BY cin ASC");
        ui->tab_av->setModel(model);
}



void   MainWindow::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}



void MainWindow::on_browseBtn_clicked()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("drid.ahmed@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("drid.ahmed@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("drid.ahmed@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::on_pushButton_3_clicked()
{

        QString link="https://mail.google.com/mail/u/0/#inbox?compose=new";
            QDesktopServices::openUrl(link);

}
void MainWindow::update_label()
{
    data=A1.read_from_arduino();
    QSqlQuery qry;
    if(data=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
    if(qry.exec("select NOTE from AVIS check (NOTE<5) "))
    {
        A1.write_to_arduino("0");
    }
}

void MainWindow::on_on_clicked()   // implémentation du slot bouton on
{
     A1.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_off_clicked()  // implémentation du slot bouton off
{

     A1.write_to_arduino("0");  //envoyer 0 à arduino
}

void MainWindow::on_plus_clicked()  // implémentation du slot bouton +
{
    A1.write_to_arduino("2");   //envoyer 2 à arduino
}

void MainWindow::on_moin_clicked() // implémentation du slot bouton -
{
    A1.write_to_arduino("3");  //envoyer 3 à arduino
}


