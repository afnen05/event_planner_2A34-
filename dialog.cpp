#include "dialog.h"
#include "ui_dialog.h"
#include<Mainwindow.h>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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
    int cin=ui->cin_mdp->text().toInt();
    QString mdp=ui->mdp->text();
    QString type=ui->comboBox->currentText();
    qry.prepare("select * from personnel where cin=:cin AND mdp=:mdp AND type=:type");
    qry.bindValue(":cin",cin);
    qry.bindValue(":mdp",mdp);
    qry.bindValue(":type",type);
    if(qry.exec())
    {
m=new MainWindow();
    m->show();
}
    else
    {
        QMessageBox::warning(this,"error","can't log in check informations");
    }

}
