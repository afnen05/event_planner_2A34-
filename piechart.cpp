#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <string>
#include <QMessageBox>
#include <QLineEdit>
#include <QSqlQueryModel>
#include <QtCharts>

QChartView* MainWindow::piechart()
{

    QPieSeries *series = new QPieSeries();
    series->append("homme", 1);
    series->append("femme", 2);


    // Add label to 1st slice

    QPieSlice *slice0 = series->slices().at(0);
    slice0->setExploded();
    slice0->setLabelVisible();
    slice0->setPen(QPen(Qt::darkBlue, 2));
    slice0->setBrush(Qt::blue);

    // Add label, explode and define brush for 2nd slice
    QPieSlice *slice1 = series->slices().at(1);
    slice1->setExploded();
    slice1->setLabelVisible();
    slice1->setPen(QPen(Qt::darkGreen, 2));
    slice1->setBrush(Qt::green);

    // Add labels to rest of slices



    series->slices().at(0)->setValue(G_PVS1());
    series->slices().at(1)->setValue(G_PVS2());


    series->slices().at(0)->setBrush(Qt::darkMagenta);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle(" POURCENTAGE DES sexes ");


    QChartView *chartView1 = new QChartView(chart);
    chartView1->setRenderHint(QPainter::Antialiasing);
    return chartView1;
}

int MainWindow::G_PVS1()
{
    int c22=0;
    QSqlQuery qry22;
    qry22.exec("SELECT id FROM Clients WHERE sexe='homme'");
    while(qry22.next())
    {
        c22++;
    }
    return c22;
}

int MainWindow::G_PVS2()
{
    int c21=0;
    QSqlQuery qry21;
    qry21.exec("SELECT id FROM Clients WHERE sexe='femme' ");
    while(qry21.next())
    {
        c21++;
    }
    return c21;
}


