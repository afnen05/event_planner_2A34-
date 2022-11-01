#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include<QString>
#include<QMessageBox>
#include <QSqlQueryModel>
#include<QIntValidator>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Pictures/backg.jfif");
    ui->label_pic->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;

 ui->lineEdit->setValidator(new QIntValidator(100, 999, this));


}


void MainWindow::on_pb_ajouter_clicked()
{
   int cin=ui->lineEdit->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString email=ui->le_email->text();
  Personnel p(cin,nom,prenom,email);
  bool test=p.ajouter();
  if(test)
    {
        QMessageBox::information(this,"edit","service added successfully");
    }
    else
    {
        QMessageBox::warning(this,"error","error");
    }

  ui->tab_perso->setModel(p.afficher());
}
void MainWindow::affichage()
{



        ui->tab_perso->setModel(p.afficher());
}





void MainWindow::on_pb_supp_clicked()
{
    Personnel p1;
    p1.setid(ui->cin_mod->text().toInt());
    bool test=p1.supprimer(p1.get_cin());
    if(test)
      {
          QMessageBox::information(this,"edit","service deleted successfully");
      }
      else
      {
          QMessageBox::warning(this,"error","error");
      }
}

void MainWindow::on_pb_modifier_clicked()
{
    QSqlQuery qry;
QString cin=ui->cin_mod->text();
    QString nom=ui->nv_nom->text();
    QString prenom=ui->nv_prenom->text();
    QString email=ui->nv_email->text();


     qry.prepare("update personnel set  cin='"+cin+"',nom='"+nom+"',prenom='"+prenom+"',email='"+email+"'where cin='"+cin+"' " );

      if(qry.exec())
       {
           QMessageBox::information(this,"edit","service modified successfully");
       }
       else
       {
           QMessageBox::warning(this,"error","error");
       }



}

