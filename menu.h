#ifndef MENU_H
#define MENU_H
#include "dialog.h"
#include "mainwindowclient.h"
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

private:
    Ui::MENU *ui;
    mainwindowclient *c;
    Dialog *d;
};

#endif // MENU_H
