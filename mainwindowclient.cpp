#include "mainwindowclient.h"
#include "ui_mainwindowclient.h"
#include "client.h"
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>
#include<QDebug>
#include<QLineEdit>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QDialog>
#include <QPrinter>
#include <QPrintDialog>
#include "smtp.h"
#include <QAbstractSocket>
#include <QSslSocket>

mainwindowclient::mainwindowclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowclient)
{
    ui->setupUi(this);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
}

mainwindowclient::~mainwindowclient()
{
    delete ui;
}
void mainwindowclient::on_pushButton_clicked()
{
    int id=ui->a1->text().toInt();
    int cin=ui->a2->text().toInt();
    QString sexe=ui->a3->currentText();
    QString nom=ui->a4->text();
    QString prenom=ui->a5->text();
    QString adresse=ui->a6->text();
    QString tel=ui->a7->text();
    client m (id,cin,sexe,nom,prenom,adresse,tel);
    bool test= m.ajouter();


         if(test)//si requête executée ==>QMessageBox::information
         {


             QMessageBox::information(nullptr,QObject::tr("ok"),
                     QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
         }

         else //si requête non exécutée ==>QMessageBox::critical
             QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                   QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
     ui->tableView->setModel(m.afficher());
}

void mainwindowclient::on_pushButton_2_clicked()
{
    int idaa =ui->a1->text().toInt();
                bool test = m.supprimer(idaa);
                if(test)
                {
                    //refresh affichage
                    ui->tableView->setModel(m.afficher());
                    //update_id();
                    QMessageBox::information(nullptr,QObject::tr("ok"),
                                             QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

                }
                else
                    QMessageBox::critical(nullptr,QObject::tr("not ok"),

         QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void mainwindowclient::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
             QSqlQuery qry;
             qry.prepare("select * from Clients where"
                         " id='"+val+"' or cin='"+val+"' or sexe='"+val+"' or nom='"+val+"' or prenom='"+val+"' or adresse='"+val+"' or tel='"+val+"'");
             if(qry.exec())
               {while (qry.next())
              { ui->a1->setText(qry.value(0).toString());
              ui->a2->setText(qry.value(1).toString());
              ui->a3->setCurrentText(qry.value(2).toString());
                ui->a4->setText(qry.value(3).toString());
                ui->a5->setText(qry.value(4).toString());
                ui->a6->setText(qry.value(5).toString());
                ui->a7->setText(qry.value(6).toString());


               }
           }
}

void mainwindowclient::on_pushButton_3_clicked()
{
    int id=ui->a1->text().toInt();
    int cin=ui->a2->text().toInt();
    QString sexe=ui->a3->currentText();
    QString nom=ui->a4->text();
    QString prenom=ui->a5->text();
    QString adresse=ui->a6->text();
    QString tel=ui->a7->text();





client k (id,cin,sexe,nom,prenom,adresse,tel);

    bool test =k.modifier();


      if(test)//si requête executée ==>QMessageBox::information
      {


          QMessageBox::information(nullptr,QObject::tr("ok"),
                  QObject::tr("modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
      }

      else //si requête non exécutée ==>QMessageBox::critical
          QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                QObject::tr("modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
    ui->tableView->setModel(m.afficher());

}

void mainwindowclient::on_pushButton_4_clicked()
{
   ui->tableView->setModel(m.AfficherTrieID());
}

void mainwindowclient::on_lineEdit_textChanged(const QString &arg1)
{
  ui->tableView->setModel(m.rechercherID(arg1));
}

void mainwindowclient::on_pushButton_5_clicked()
{
    client c;

             QString text=c.apercu_pdf();
             ui->imp->setText(text);

             QPrinter printer ;
             printer.setPrinterName("imprim");
             QPrintDialog dialog (&printer,this);
             if(dialog.exec()==QDialog::Rejected) return ;
             ui->imp->print(&printer);
}

void mainwindowclient::on_tabWidget_2_tabBarClicked(int index)
{
    qDeleteAll(ui->tabWidget_2->widget(0)->children());
    QWidget* piestats = new QWidget(this);
    piestats = piechart();
    QGridLayout* layout1 = new QGridLayout(this);
    layout1->addWidget(piestats, 0, 0); // Top-Left
    layout1->addWidget(NULL, 0, 1); // Top-Right
    layout1->addWidget(NULL, 1, 0); // Bottom-Left
    layout1->addWidget(NULL, 1, 1); // Bottom-Right
    ui->tab_3->setLayout(layout1);
}


void  mainwindowclient::browse()
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
void   mainwindowclient::sendMail()
{
    Smtp* smtp = new Smtp("marwen.masmoudi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("marwen.masmoudi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("marwen.masmoudi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   mainwindowclient::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();

}

void mainwindowclient::on_sendBtn_clicked()
{
    Smtp* smtp = new Smtp("marwen.masmoudi@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("marwen.masmoudi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("marwen.masmoudi@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

