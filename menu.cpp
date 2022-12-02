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
