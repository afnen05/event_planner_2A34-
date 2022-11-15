#ifndef DIALOG_H
#define DIALOG_H
#include"Mainwindow.h"
#include <QDialog>
#include"personnel.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_buttonBox_accepted();

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    Ui::MainWindow *uii;
    MainWindow *m;
    Personnel p;
};

#endif // DIALOG_H