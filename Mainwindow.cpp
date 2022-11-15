#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include"personnel.h"
#include"conge.h"
#include<QString>
#include<QMessageBox>
#include <QSqlQueryModel>
#include<QIntValidator>
#include <QStandardItemModel>
#include<QList>
#include<QPrinter>
#include<QPrintDialog>
#include <QDesktopServices>
#include<QDate>
#include<QRegularExpression>
#include<QRegExpValidator>
#include"sp.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRegularExpression datenumber("\\b([0-3][0-9][-][0-1][0-9][-][2][0][2][2-3])\\b",QRegularExpression::CaseInsensitiveOption);
        QRegularExpressionValidator *datevalnumber = new QRegularExpressionValidator(datenumber,this);
        ui->date_debut->setValidator(datevalnumber);
        QRegularExpression datenumbe("\\b([0-3][0-9][-][0-1][0-9][-][2][0][2][2-3])\\b",QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionValidator *dateval = new QRegularExpressionValidator(datenumbe,this);
        ui->date_retour->setValidator(dateval);
    QPixmap pix("C:/Users/user/Pictures/backg.jfif");
    ui->label_pic->setPixmap(pix);
     ui->le_cin->setValidator(new QIntValidator(0,99999999, this));
     ui->cin_recherche->setValidator(new QIntValidator(0,99999999, this));
     ui->cin_sal->setValidator(new QIntValidator(0,99999999, this));
ui->cin_cong->setValidator(new QIntValidator(0,99999999, this));
ui->cin_salaire->setValidator(new QIntValidator(0,99999999, this));
ui->lineEdit_2->setValidator(new QIntValidator(0,9999, this));
}

MainWindow::~MainWindow()
{
    delete ui;


}


void MainWindow::on_pb_ajouter_clicked()
{

   QSqlQuery q,qry;

   int cin=ui->le_cin->text().toInt();
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();

   QString type=ui->comboBox_3->currentText();
   QString mdp=ui->le_mdp->text();
   QString email=ui->le_email->text();
Personnel p(cin,nom,prenom,email,type,mdp);
             bool test=p.ajouter();

if(test)
    QMessageBox::information(this,"edit","hmdlh");
else
    QMessageBox::warning(this,"error","leeee");


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
int cin=ui->cin_recherche->text().toInt();
    QString nom=ui->nv_nom->text();
    QString prenom=ui->nv_prenom->text();
    QString email=ui->nv_email->text();
    QString type=ui->nv_type->text();
    QString mdp=ui->nv_mdp->text();
     Personnel p(cin,nom,prenom,email,type,mdp);
   bool test=p.modifier(cin);
   if(test)
   {
       QMessageBox::information(this,"edit","modification effectuee");
   }
   else
       QMessageBox::warning(this,"error","error");

}



void MainWindow::on_pb_afficher_clicked()
{
    QSqlQuery req;
        QStandardItemModel *model =new QStandardItemModel(6,6);
       int row=0;
       req.exec("select *from personnel");
       while(req.next())
       {
           for(int i=0;i<6;i++)
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
       model->setHeaderData(4,Qt::Horizontal,"type");
       model->setHeaderData(5,Qt::Horizontal,"mdp");

       ui->tab_perso->setModel(model);
}

void MainWindow::on_pb_recherche_clicked()
{
    int cin=ui->cin_recherche->text().toInt();
       QSqlQuery qry=p.recherche(cin);
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
    QSqlQuery qry=p.tri();

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
    QSqlQuery qry=p.tab_afficher(val);

    if (qry.exec())
    {
        while(qry.next())
        {

            ui->cin_recherche->setText(qry.value(0).toString());
            ui->nv_nom->setText(qry.value(1).toString());
            ui->nv_prenom->setText(qry.value(2).toString());
            ui->nv_email->setText(qry.value(3).toString());
            ui->nv_type->setText(qry.value(4).toString());
            ui->nv_mdp->setText(qry.value(5).toString());
            QString s=(qry.value(0).toString()+"\n"+qry.value(1).toString()+"\n"+qry.value(2).toString()+"\n"+qry.value(3).toString()+"\n"+qry.value(4).toString()+"\n"+qry.value(5).toString());
            ui->aff_pdf->setText(s);
        }
    }
        else
        {
           QMessageBox::warning(this,"error","no information");
        }
}

void MainWindow::on_pb_conf_clicked()
{
int cin=ui->cin_sal->text().toInt();
//int prime=ui->line_prime->text().toInt();
QSqlQuery qry;
qry.prepare("update personnel set prime=:prime where cin=:cin");
qry.bindValue(":cin",cin);
//qry.bindValue(":prime",prime);
if(qry.exec())
{
    QMessageBox::information(this,"edit","validee");

}
else
{
    QMessageBox::warning(this,"edit","failed");
}
}

void MainWindow::on_pushButton_3_clicked()
{
QPrinter printer;
printer.setPrinterName("fichier");
QPrintDialog dialog(&printer,this);
if(dialog.exec()==QDialog::Rejected)
{

    return ;
}
else
    ui->aff_pdf->print(&printer);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tabWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_7_clicked()
{

    int cin=ui->cin_cong->text().toInt();
    QString d1=ui->date_debut->text();
    QString d2=ui->date_retour->text();
   QString etat="";
    conge g(cin,d1,d2,etat);
    bool test=g.ajouter();
    if(test)
    {

     QMessageBox::information(this,"edit","validee");

    }
    else
    {
            QMessageBox::warning(this,"edit","failed");


}

}



void MainWindow::on_pb_supp1_clicked()
{

    int cin=ui->cin_cong->text().toInt();
      bool test=g.supprimer(cin);
      if (test)
      {

       QMessageBox::information(this,"edit","validee");

      }
      else
      {QMessageBox::warning(this,"edit","failed");


  }

}


void MainWindow::on_pushButton_5_clicked()
{

    int cin=ui->cin_cong->text().toInt();
   bool test=g.modifier(cin);
      if (test)
      {

       QMessageBox::information(this,"edit","validee");

      }

      else
      {
          QMessageBox::warning(this,"edit","failed");

}
}

void MainWindow::on_pushButton_9_clicked()
{
    QSqlQuery req;
        QStandardItemModel *model =new QStandardItemModel(4,4);
       int row=0;
       req.exec("select *from CONGE");
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
       model->setHeaderData(1,Qt::Horizontal,"date_debut");//ecrire header of table
       model->setHeaderData(2,Qt::Horizontal,"date_retour");
       model->setHeaderData(3,Qt::Horizontal,"confirmation");




       ui->aff_cong->setModel(model);
}

void MainWindow::on_pushButton_8_clicked()
{
    QSqlQuery req;
    int cin=ui->cin_sal->text().toInt();

        QStandardItemModel *model =new QStandardItemModel(3,3);
       int row=0;
       req.bindValue(":cin",cin);
       req.exec("select * from salairee ");
       while(req.next())
       {
           for(int i=0;i<3;i++)
           {
               QStandardItem *item=new QStandardItem(req.value(i).toString());   //i le nombre de colone;
               model->setItem(row,i,item);
           }
           row++;

       }

       model->setHeaderData(0,Qt::Horizontal,"cin");
       model->setHeaderData(1,Qt::Horizontal,"salaire");//ecrire header of table
       model->setHeaderData(2,Qt::Horizontal,"prime");

       ui->afficher_salaire->setModel(model);
}

void MainWindow::on_pushButton_10_clicked()
{

    int cin=ui->cin_cong->text().toInt();
   bool test=g.refuser(cin);
      if (test)
      {

       QMessageBox::information(this,"edit","validee");

      }

      else
      {
          QMessageBox::warning(this,"edit","failed");

}
}

void MainWindow::on_pushButton_11_clicked()
{

    float a=ui->comboBox->currentText().toFloat();
    float b=ui->comboBox_2->currentText().toFloat();
    int cin=ui->cin_sal->text().toInt();
  QString prime;
  int n=0;
 QString sal;
  int somme=0;
   QSqlQuery q,qry,query,qu;
   q.prepare("select * from evenment where cin=:cin ");
   q.bindValue(":cin",cin);
   if(q.exec())
   {
 while(q.next())
 {
     n++;
 }

 }
   else
   {
       QMessageBox::warning(this,"edit","failed");

   }
  qry=s.salaire_distinct(cin);

   if(qry.exec())
   {
       while(qry.next())
       sal=qry.value(0).toString();

       QMessageBox::information(this,"edit","salaire mchee");
}
else
       QMessageBox::warning(this,"error","salaire lee");

   query=s.calcule_prix_total(cin);
   if(query.exec())
   {
       while(query.next())
       somme=query.value(0).toInt();
   QMessageBox::information(this,"edit","somme mrigel");
   }
   else
       QMessageBox::warning(this,"error","somme lee");


  bool test=s.update_prime(cin,a,b,sal,n,somme);
   if(test)
       QMessageBox::information(this,"edit","insertion mchet");
   else
       QMessageBox::warning(this,"error","errorrr");

}


void MainWindow::on_pushButton_12_clicked()
{
    QSqlQuery q1,q2,q3;
        qreal tot=0,c1=0,c2=0;
        q1.prepare("Select * from personnel ");
        if(q1.exec())
        {
            while (q1.next())
            {
                tot++;
            }
        }
        q2.prepare("Select * from personnel where type ='admin'");
        if(q2.exec())
        {
            while (q2.next())
            {
                c1++;
            }
        }
        q3.prepare("Select * from personnel where type='utilisateur'");
        if(q3.exec())
        {
            while (q3.next())
            {
                c2++;
            }
        }

        c1=c1/tot;
        c2=c2/tot;


    QPieSeries *series = new QPieSeries();
                series->append("admin",c1);
                series->append("utilisateur",c2);

                QPieSlice *slice0 = series->slices().at(0);
                slice0->setExploded();
                slice0->setLabelVisible();
                slice0->setPen(QPen(Qt::darkGray, 2));
                slice0->setBrush(Qt::white);
                QPieSlice *slice1 = series->slices().at(1);
                slice1->setExploded();
                slice1->setLabelVisible();
                slice1->setPen(QPen(Qt::darkRed, 2));
                slice1->setBrush(Qt::blue);
                QChart *chart = new QChart();
                chart->addSeries(series);
                chart->setTitle("statistique");
                chart->setAnimationOptions(QChart::AllAnimations);
                chart->legend()->hide();
                QChartView *chartView = new QChartView(chart,ui->stat);
                chartView->setRenderHint(QPainter::Antialiasing);
                QGridLayout *layout = new QGridLayout();
                layout->addWidget(chartView);
                ui->stat->setLayout(layout);

}



void MainWindow::on_ajout_salaire_clicked()
{
    int cin=ui->cin_salaire->text().toInt();
    QString salaire=ui->lineEdit_2->text();
    QString prime="";
    sp s(cin,salaire,prime);
    bool test=s.ajout();
    if (test)
    {

     QMessageBox::information(this,"edit","validee");

    }

    else
    {
        QMessageBox::warning(this,"edit","failed");

}
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->le_cin->clear();
    ui->le_nom->clear();
    ui->le_prenom->clear();
    ui->le_email->clear();
    ui->le_mdp->clear();
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->cin_salaire->clear();
    ui->lineEdit_2->clear();
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->cin_recherche->clear();
    ui->nv_nom->clear();
    ui->nv_prenom->clear();
    ui->nv_type->clear();
    ui->nv_mdp->clear();
    ui->nv_email->clear();
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->cin_cong->clear();
    ui->date_debut->clear();
    ui->date_retour->clear();

}
