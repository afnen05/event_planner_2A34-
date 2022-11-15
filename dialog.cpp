#include "dialog.h"
#include "ui_dialog.h"
#include<Mainwindow.h>
#include<QIntValidator>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
  ui->cin_mdp->setValidator(new QIntValidator(0,99999999, this));
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
