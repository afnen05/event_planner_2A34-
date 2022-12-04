#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "event.h"
#include <QDateEdit>
#include <QMessageBox>
#include<QIntValidator>
#include<QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QTextStream>
#include <QTextDocument>
#include <QDialog>
#include <QLabel>
#include <QSystemTrayIcon>
#include <QSqlQueryModel>
#include <QTextStream>
#include <QTimer>
#include <QPrintDialog>
#include <QSystemTrayIcon>
#include <QLabel>
#include <QPrinter>
#include <QPainter>
#include <QPrintDialog>
#include <QSqlQueryModel>
#include <QDebug>
#include "popup.h"
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include "arduino.h"
#include <QtCore>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret=A.connect_arduino();
    switch (ret) {
    case(0):qDebug()<<"arduino is available and connected to "<<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to:" <<A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available";
        break;


    }

    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    popUp = new PopUp();

    QRegularExpression rnumber("\\b([0-9][0-9][-][0-9][0-9][-][0-9][0-9][0-9][0-9])\\b",QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionValidator *valnumber = new QRegularExpressionValidator(rnumber,this);
             ui->date_ev->setValidator(valnumber);

             QRegularExpression r2number("\\b([a-zA-Z])([a-zA-Z0-9])*\\b",QRegularExpression::CaseInsensitiveOption);
                   QRegularExpressionValidator *val1 = new QRegularExpressionValidator(r2number,this);
                    ui->nom_ev->setValidator(val1);
ui->tab_ev->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::update_label(){
  //  data=A.read_from_arduino();
    //if (data==)
//}

void MainWindow::on_push1_clicked()
{
QSqlQuery query;
QString i;
QByteArray X;
     QString CIN_CL=ui->cin_c->text();
     QString NOM=ui->nom_ev->text();
     QString DATE_EV=ui->date_ev->text();
     int PRIX=ui->PRIX->text().toInt(); 
     Event E(CIN_CL,DATE_EV,NOM,PRIX);
     bool test= E.ajouter(); 
     uint decimal = 203888026;
     QString hexvalue = QString("%1").arg(decimal, 8, 16, QLatin1Char( '0' ));
     if (test){
         QMessageBox::information(nullptr, QObject::tr(" OK"),
                     QObject::tr("Ajout successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
         ui->tab_ev->setModel(E.afficher());
           query.prepare("select PRIX from evenement where NOM=:NOM");
           query.bindValue(":NOM",NOM);
           while(query.next())
               i=query.value(0).toString();
              if(i<50)
              {A.write_to_arduino("1");}
              else if(i<100 && i>50)
              {
                  A.write_to_arduino("2");
              }

     }
     else{
         QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                     QObject::tr("Ajout failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);}


}



void MainWindow::on_supprimer_clicked()
{ Event E1;
    E1.setnom(ui->sup->text());
    bool test=E1.supprimer(E1.getnom());
    if (test){
        QMessageBox::information(nullptr, QObject::tr(" OK"),
                    QObject::tr("Delete successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tab_ev->setModel(E.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                    QObject::tr("Delete failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_Modifier_clicked()
{
    Event E3;
        QString NOM=ui->L1->text();
        QString DATE_Ev=ui->L2->text();
        QString CIN_CL=ui->L3->text();
        int PRIX=ui->leprix->text().toInt()   ;
        bool test=E3.Modifier(CIN_CL,DATE_Ev,NOM,PRIX);
         if (test){
             QMessageBox::information(nullptr, QObject::tr(" OK"),
                         QObject::tr("modifier successful.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

         }
         else
         {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                         QObject::tr("modifier failed.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pdf_pb_clicked()
{
    {QSqlDatabase db;
        QTableView tab_event;
        QSqlQueryModel * Modal=new  QSqlQueryModel();

        QSqlQuery query;
         query.prepare("SELECT * FROM EVENEMENT ");
         query.exec();
         Modal->setQuery(query);
        tab_event.setModel(Modal);



         db.close();


         QString strStream;
         QTextStream out(&strStream);

         const int rowCount = tab_event.model()->rowCount();
         const int columnCount =  tab_event.model()->columnCount();


         const QString strTitle ="Document";


         out <<  "<html>\n"
             "<head>\n"
                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             <<  QString("<title>%1</title>\n").arg(strTitle)
             <<  "</head>\n"
             "<body bgcolor=#ffffff link=#5000A0>\n"
            << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("LES EVENEMENTS")
            <<"<br>"
             <<"<table border=1 cellspacing=0 cellpadding=2>\n";

         out << "<thead><tr bgcolor=#f0f0f0>";
         for (int column = 0; column < columnCount; column++)
             if (!tab_event.isColumnHidden(column))
                 out << QString("<th>%1</th>").arg(tab_event.model()->headerData(column, Qt::Horizontal).toString());
         out << "</tr></thead>\n";

         for (int row = 0; row < rowCount; row++) {
             out << "<tr>";
             for (int column = 0; column < columnCount; column++) {
                 if (!tab_event.isColumnHidden(column)) {
                     QString data = tab_event.model()->data(tab_event.model()->index(row, column)).toString().simplified();
                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                 }
             }
             out << "</tr>\n";
         }
         out <<  "</table>\n"
                 "<br><br>"
                 //<< QString("<p><img src=":/img/aze.png"; width="200"; height="200";\">%1</p>\n")
                 <<"<br>"
                 <<"<table border=1 cellspacing=0 cellpadding=2>\n";


             out << "<thead><tr bgcolor=#f0f0f0>";

                 out <<  "</table>\n"

             "</body>\n"
             "</html>\n";

         QTextDocument *document = new QTextDocument();
         document->setHtml(strStream);

         QPrinter printer;
         QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
         if (dialog->exec() == QDialog::Accepted) {

             QLabel lab;
              QPixmap pixmap(":/img/aze.png");
             lab.setPixmap(pixmap);
             QPainter painter(&lab);
             //QPrinter printer(QPrinter::PrinterResolution);

             //pixmap.load("aze.png");
             //painter.drawPixmap(0,0,this->width(),this->height(),pixmap);
             //painter.drawPixmap(10,10,50,50, pixmap);

             document->print(&printer);
         }

         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setPaperSize(QPrinter::A4);
         printer.setOutputFileName("/tmp/commandes.pdf");
         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



         delete document;
    }

}

void MainWindow::on_recherch_pb_clicked()
{
    {

        Event E3;

                E3.rechercher(ui->X_ev->text(),ui->tab_view);

        ui->X_ev->setText("");
    }

}

void MainWindow::on_tri_clicked()
{
    ui->tab_view->setModel(E.afficher_tri_nom());

}

void MainWindow::on_croissant_clicked()
{
    ui->tab_view->setModel(E.afficher_tri_nom_ASC());

}

void MainWindow::on_decroissant_clicked()
{     ui->tab_view->setModel(E.afficher_tri_nom_DESC());


}




void MainWindow::on_annuler_clicked()
{
    Event E1;
    E1.setid(ui->id_ev->text());
    bool test=E1.annulation(E1.getid());
     QString lol="Event deleted with succes";
      QString lool="Event failed to delete";
    if (test){

    ui->tab_ev->setModel(E.afficher());

   popUp->setPopupText(lol);

      popUp->show();

}
else
     popUp->setPopupText(lool);

          popUp->show();



  }





void MainWindow::on_report_clicked()
{
    QString DATE_EV=ui->iddate->text();
    QString ID= ui->idev->text();
    Event E;
    if (E.reportor(DATE_EV,ID)){
        QMessageBox::information(nullptr, QObject::tr(" OK"),
                        QObject::tr("report successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
             ui->tab_ev->setModel(E.afficher());

        }
        else
        {QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                        QObject::tr("report failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_stat_clicked()
{
    {
        Event E;
        try{
            QT_CHARTS_USE_NAMESPACE
            QChart *chart = new QChart();
            QBarSeries *series = new QBarSeries();
            QBarCategoryAxis *axis = new QBarCategoryAxis();

            QBarSet *set = new QBarSet(" PRIX");
            QStringList typesList;
            QList<QBarSet *> nbrList;
            std::map<QString , int> list = E.statNbrPerType();
            for(auto itr = list.begin() ; itr != list.end(); itr++) {
                typesList.append(itr->first);
    //            nbrList.append(itr->second);
                *set << itr->second;
                nbrList.append(set);
            }
            qDebug() << typesList;
            series->append(set);
            chart->addSeries(series);
            chart->setAnimationOptions(QChart::AllAnimations);
            axis->append(typesList);
            chart->createDefaultAxes();
            chart->setAxisX(axis, series);
            chart->legend()->setAlignment(Qt::AlignBottom);
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);
            QPalette pal = qApp->palette();
            pal.setColor(QPalette::Window, QRgb(0x0d4261));
            pal.setColor(QPalette::WindowText, QRgb(0x95212c));
            qApp->setPalette(pal);
            QFont font;
            font.setPixelSize(40);
            chart->setTitleFont(font);
            chart->setTitleBrush(QBrush(Qt::red));
            chart->setTitle("statistique PRIX PAR DATE ");
            chartView->setChart(chart);
            chartView->showNormal();



        }catch(...){
            qDebug() << "error";
        }
}}

