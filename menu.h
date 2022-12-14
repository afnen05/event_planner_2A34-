#ifndef MENU_H
#define MENU_H
#include "dialog.h"
#include "mainwindowclient.h"
#include "mainwindow_facture.h"
#include "mainwindow_avis.h"
#include <QDialog>

namespace Ui {
class MENU;
}

class MENU : public QDialog
{
    Q_OBJECT

public:
    explicit MENU(QWidget *parent = nullptr);
    ~MENU();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MENU *ui;
    mainwindowclient *c;
    mainwindow_avis *a;
    Dialog *d;
    mainwindow_facture *f;
};

#endif // MENU_H
