#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"personnel.h"
#include<QString>
#include<QMessageBox>
#include <QSqlQueryModel>
#include<QIntValidator>
#include <QStandardItemModel>

#include <QDesktopServices>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Pictures/backg.jfif");
    ui->label_pic->setPixmap(pix);

    ui->lineEdit->setValidator(new QIntValidator(0,99999999, this));


}

MainWindow::~MainWindow()
{
    delete ui;


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

  //ui->tab_perso->setModel(p.afficher());
}
//void MainWindow::affichage()




//        ui->tab_perso->setModel(p.afficher());






void MainWindow::on_pb_supp_clicked()
{
    Personnel p1;
    p1.setid(ui->cin_recherche->text().toInt());
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
QString cin=ui->cin_recherche->text();
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



void MainWindow::on_pb_afficher_clicked()
{
    QSqlQuery req;
        QStandardItemModel *model =new QStandardItemModel(4,4);
       int row=0;
       req.exec("select cin,nom,prenom,email from personnel");
       while(req.next())
       {
           for(int i=0;i<4;i++)
           {
               QStandardItem *item=new QStandardItem(req.value(i).toString());   //i le nombre de colone;
               model->setItem(row,i,item);
           }
           row++;

       }

       model->setHeaderData(0,Qt::Horizontal,"cin");
       model->setHeaderData(1,Qt::Horizontal,"nom");//ecrire header of table
       model->setHeaderData(2,Qt::Horizontal,"prenom");
       model->setHeaderData(3,Qt::Horizontal,"email");



       ui->tab_perso->setModel(model);
}

void MainWindow::on_pb_recherche_clicked()
{
    int cin=ui->cin_recherche->text().toInt();
       QSqlQuery qry;
       qry.prepare("select * from personnel where cin=:cin");
        qry.bindValue(":cin",cin );
       if(qry.exec())
       {QSqlQueryModel * model=new QSqlQueryModel();


           model->setQuery(qry);
           ui->tab_perso->setModel(model);

       }
       else
       {
           QMessageBox::warning(this,"error","error");
       }
}

void MainWindow::on_pushButton_clicked()
{
    QSqlQuery qry;
      qry.prepare("select * from personnel ORDER BY nom");
      if(qry.exec())


      {
          QSqlQueryModel * model=new QSqlQueryModel();


                  model->setQuery(qry);
                  ui->tab_perso->setModel(model);

      }
      else {
          QMessageBox::warning(this,"error","no information");
      }
}



void MainWindow::on_tab_perso_clicked(const QModelIndex &index)
{
    QString val=ui->tab_perso->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("select * from personnel where cin=:val");
    qry.bindValue(":val",val);
    if (qry.exec())
    {
        while(qry.next())
        {

            ui->cin_recherche->setText(qry.value(0).toString());
            ui->nv_nom->setText(qry.value(1).toString());
            ui->nv_prenom->setText(qry.value(2).toString());
            ui->nv_email->setText(qry.value(3).toString());

        }
    }
        else
        {
           QMessageBox::warning(this,"error","no information");
        }
}
