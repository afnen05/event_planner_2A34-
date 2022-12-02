#ifndef MAINWINDOW_PERSONNEL_H
#define MAINWINDOW_PERSONNEL_H
#include"dialog.h"
#include <QDialog>

namespace Ui {
class Mainwindow_personnel;
}

class Mainwindow_personnel : public QDialog
{
    Q_OBJECT

public:
    explicit Mainwindow_personnel(QWidget *parent = nullptr);
    ~Mainwindow_personnel();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Mainwindow_personnel *ui;

};

#endif // MAINWINDOW_PERSONNEL_H
