#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"personnel.h"
#include"conge.h"
#include"sp.h"
#include <QApplication>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "arduino.h"
QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //void affichage();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supp_clicked();

    void on_pb_modifier_clicked();



    void on_pb_afficher_clicked();

    void on_pb_recherche_clicked();

    void on_pushButton_clicked();



    void on_tab_perso_clicked(const QModelIndex &index);

    void on_pb_conf_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();



    void on_pb_supp1_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();


    void on_ajout_salaire_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();



private:
    Ui::MainWindow *ui;
    Personnel p;
    conge g;
    sp s;

};
#endif // MAINWINDOW_H
