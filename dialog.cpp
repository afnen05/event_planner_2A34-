#include "dialog.h"
#include "ui_dialog.h"
#include<Mainwindow.h>
#include<QIntValidator>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{

    // serialBuffer +=QString::fromStdString(data.toStdString());
    ui->setupUi(this);
  ui->cin_mdp->setValidator(new QIntValidator(0,99999999, this));
  int ret=A.connect_arduino(); // lancer la connexion à arduino
  switch(ret){
  case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
      break;
  case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
     break;
  case(-1):qDebug() << "arduino is not available";
  }
   QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
   //le slot update_label suite à la reception du signal readyRead (reception des données).
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    //mainwindow.exec
}


void Dialog::on_pushButton_clicked()
{
    QSqlQuery qry;
  QString cin=ui->cin_mdp->text();
    QString mdp=ui->mdp->text();
    QString type=ui->comboBox->currentText();
    if( qry.exec("select *from personnel where cin='"+cin+"' AND mdp='"+mdp+"' AND type='"+type+"'")
)

   {
        int count=0;
        while(qry.next())
           { count++;}
    if(count==1)
    {
m=new MainWindow(this);
    m->show();

}
    }
    else
    {
        QMessageBox::warning(this,"error","can't log in check informations");
    }

}
void Dialog::update_label()
{

    data=A.read_from_arduino();
    QByteArray text=QByteArray::fromHex(data);
    QSqlQuery qry;
    serialBuffer +=QString::fromStdString(data.toStdString());


    if( qry.exec("select * from PERSONNEL where RFID like '"+serialBuffer+"%'")
                 )
    {



                         int count=0;
                         while(qry.next())
                            { count++;}
                     if(count==1)
                     {
                 m=new MainWindow(this);
                     m->show();

                 }
                     }
                     else
                     {
                        // QMessageBox::warning(this,"error","can't log in check informations");
        QMessageBox::warning(this,"error","error");
                     }

}
