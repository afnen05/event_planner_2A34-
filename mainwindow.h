#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "event.h"
#include "arduino.h" 
#include <QMainWindow>
#include "popup.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void update_label();
    void on_push1_clicked();

    void on_supprimer_clicked();

    void on_Modifier_clicked();

    void on_pdf_pb_clicked();

    void on_recherch_pb_clicked();

    void on_tri_clicked();

    void on_croissant_clicked();

    void on_decroissant_clicked();

    void on_annuler_clicked();

    void on_report_clicked();

    void on_stat_clicked();


private:
    Ui::MainWindow *ui;
    Event E;
    PopUp *popUp;
    QByteArray data;
Arduino A;
};
#endif // MAINWINDOW_H
