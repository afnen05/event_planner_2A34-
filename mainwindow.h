#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPoint>
#include <QMainWindow>
#include <QtCharts>
#include <QMainWindow>
#include <QFile>
#include "client.h"
#include "smtp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update_id();
    int G_PVS1();
    int G_PVS2();
    int G_PVS5();

    QChartView* piechart();
private slots:


    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_5_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void sendMail();
    void mailSent(QString);
    void browse();

    void on_tabWidget_2_currentChanged(int index);

private:
    client m;
    int id_p=0;
    Ui::MainWindow *ui;
    QStringList files;

};
#endif // MAINWINDOW_H
