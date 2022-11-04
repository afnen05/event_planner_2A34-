#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"personnel.h"
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


    void on_pushButton_9_clicked();

    void on_pb_afficher_clicked();

    void on_pb_recherche_clicked();

    void on_pushButton_clicked();



    void on_tab_perso_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Personnel p;
};
#endif // MAINWINDOW_H
