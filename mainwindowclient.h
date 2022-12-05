#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H
#include <QPoint>
#include <QtCharts>
#include <QMainWindow>
#include <QFile>
#include "client.h"
#include "smtp.h"
#include <QDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindowclient;
}
QT_END_NAMESPACE
class mainwindowclient : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowclient(QWidget *parent = nullptr);
    ~mainwindowclient();
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



    void on_sendBtn_clicked();

private:
    client m;
    int id_p=0;
    Ui::mainwindowclient *ui;
    QStringList files;
};

#endif // MAINWINDOWCLIENT_H
