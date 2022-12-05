#include "menu.h"
#include "ui_menu.h"
#include "menu.h"

MENU::MENU(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MENU)
{
    ui->setupUi(this);
}

MENU::~MENU()
{
    delete ui;
}

void MENU::on_pushButton_clicked()
{
   d=new Dialog();
   d->show();
}

void MENU::on_pushButton_2_clicked()
{
    c = new mainwindowclient();
    c->show();
}

void MENU::on_pushButton_3_clicked()
{
    f = new mainwindow_facture();
    f -> show();
}
