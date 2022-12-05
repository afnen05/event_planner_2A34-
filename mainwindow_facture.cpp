#include "mainwindow_facture.h"
#include "ui_mainwindow_facture.h"
#include "facture.h"
#include <QDateEdit>
#include <QMessageBox>
#include<QIntValidator>
#include <QSqlQuery>
#include <QtPrintSupport/QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include <QTextStream>
#include <QTextDocument>
#include <QDialog>
#include <QLabel>
#include <QPrintDialog>
#include <QDebug>
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include "arduino_facture.h"
mainwindow_facture::mainwindow_facture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindow_facture)
{
    ui->setupUi(this);
    ui->comboBox_events->setModel(fac.getEvents());
    ui->comboBox_events->setModelColumn(1);
    ui->comboBox_events_2->setModel(fac.getEvents());
    ui->comboBox_events_2->setModelColumn(1);
    ui->comboBox_remb->setModel(fac.afficher());
    ui->lineEdit_prix->setText(ui->comboBox_events->model()->data(ui->comboBox_events->model()->index(ui->comboBox_events->currentIndex(),5)).toString());
    refresh();

    int ret=AF.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< AF.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<AF.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(AF.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

}

mainwindow_facture::~mainwindow_facture()
{
    delete ui;
}
void mainwindow_facture::update_label()
{
    data2=AF.read_from_arduino();

    if(data2=="1")

        ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data2=="0")

        ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}

void mainwindow_facture::refresh(){
    ui->tab_fac->setModel(fac.afficher());
    ui->tableView_remb->setModel(fac.afficher_remboursement());
    bilan(0);
}

void mainwindow_facture::on_buttonBox_accepted()
{
    ui->tab_fac ->setModel(fac.afficher());
}

void mainwindow_facture::on_pb_ajouter_clicked()
{
    QSqlQuery query ;
    QString n_facture=ui->nf->text();
     QString offre=ui->off->text();

    QString date=ui->dateEdit->text();
    int tva = ui->spinBox_tva->value();
    int prix = ui->lineEdit_prix->text().toInt();
    facture fac(n_facture,date,offre,tva,prix);
     bool test=fac.ajouter();
     query.prepare("select from FACTURE ID_FACTURE VALUES :ID_FACTURE");
     query.bindValue(":ID_FACTURE", n_facture);

      if(test)
      {
          AF.write_to_arduino("n_facture");
          refresh();
          QMessageBox::information(nullptr, QObject::tr("Ajouter"),
                      QObject::tr("ajout avec succes.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
       else
           QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                       QObject::tr("echec d ajout.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);



}




void mainwindow_facture::on_pb_supprimer_clicked()
{
    facture f1;
    f1.setNfacture(ui->supp->text());
    bool test=f1.supprimer(f1.getNfacture());

    QMessageBox msgBox;
    if(test)
    {
        refresh();  AF.write_to_arduino("2");
        msgBox.setText("Suppression avec succes");

      }
     else
        msgBox.setText("Echec de suppression");
        msgBox.exec();
}


void mainwindow_facture::on_modifier_clicked()
{
    QString n_facture=ui->nf2->text();

    QString offre=ui->off_2->text();
    QString date=ui->dateEdit_2->text();
    int prix = ui->lineEdit_prix_2->text().toInt();
    int tva = ui->spinBox_tva_2->value();


    facture fac(n_facture,date,offre,tva,prix);
     bool test=fac.modifier();
     if(test)
     {refresh(); AF.write_to_arduino("3");
         QMessageBox::information(nullptr, QObject::tr("modifier"),
                     QObject::tr("modification avec succes.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier"),
                      QObject::tr("echec de modification.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);




}



void mainwindow_facture::on_pushButton_clicked()
{

    ui->tab_fac->setModel(fac.trier(ui->comboBox->currentText()));
}
void mainwindow_facture::on_comboBox_2_activated(const QString &arg1)
{
    ch1=arg1;

}

void mainwindow_facture::on_pushButton_2_clicked()
{

 bilan(0);

}


void mainwindow_facture::on_pdf_clicked()
{
    {QSqlDatabase db;
        QTableView tab_fac;
        QSqlQueryModel * Modal=new  QSqlQueryModel();

        QSqlQuery query;
         query.prepare("SELECT * FROM FACTURE ");
         query.exec();
         Modal->setQuery(query);
        tab_fac.setModel(Modal);



         db.close();


         QString strStream;
         QTextStream out(&strStream);

         const int rowCount = tab_fac.model()->rowCount();
         const int columnCount =  tab_fac.model()->columnCount();


         const QString strTitle ="Document";


         out <<  "<html>\n"
             "<head>\n"
                 "<meta Content=\"Text/html; charset=Windows-1251\">\n"
             <<  QString("<title>%1</title>\n").arg(strTitle)
             <<  "</head>\n"
             "<body bgcolor=#ffffff link=#5000A0>\n"
            << QString("<h3 style=\" font-size: 32px; font-family: Arial, Helvetica, sans-serif; color: #FF9933; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Event")
            <<"<br>"
             <<"<table border=1 cellspacing=0 cellpadding=2>\n";

         out << "<thead><tr bgcolor=#f0f0f0>";
         for (int column = 0; column < columnCount; column++)
             if (!tab_fac.isColumnHidden(column))
                 out << QString("<th>%1</th>").arg(tab_fac.model()->headerData(column, Qt::Horizontal).toString());
         out << "</tr></thead>\n";

         for (int row = 0; row < rowCount; row++) {
             out << "<tr>";
             for (int column = 0; column < columnCount; column++) {
                 if (!tab_fac.isColumnHidden(column)) {
                     QString data = tab_fac.model()->data(tab_fac.model()->index(row, column)).toString().simplified();
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

             document->print(&printer);
         }

         printer.setOutputFormat(QPrinter::PdfFormat);
         printer.setPaperSize(QPrinter::A4);
         printer.setOutputFileName("/tmp/commandes.pdf");
         printer.setPageMargins(QMarginsF(15, 15, 15, 15));



         delete document;
    }
}

void mainwindow_facture::on_comboBox_events_currentIndexChanged(int index)
{
    ui->lineEdit_prix->setText(ui->comboBox_events->model()->data(ui->comboBox_events->model()->index(index,5)).toString());

}

void mainwindow_facture::on_comboBox_events_2_currentIndexChanged(int index)
{
    ui->lineEdit_prix_2->setText(ui->comboBox_events->model()->data(ui->comboBox_events->model()->index(index,5)).toString());

}

void mainwindow_facture::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tab_fac->setModel(fac.rechercher(arg1));
}

void mainwindow_facture::on_pushButton_remb_clicked()
{
    int idF = ui->comboBox_remb->currentText().toInt();
    int pr = ui->spinBox_remb->value();
    int value = ui->lineEdit_valeur_rembourse->text().toInt();
    bool test = fac.ajouter_remboursement(idF,pr,value);

    if(test)
    {refresh();
        QMessageBox::information(nullptr, QObject::tr("Ajouter"),
                    QObject::tr("ajout avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
     else
         QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                     QObject::tr("echec d ajout.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

}

void mainwindow_facture::on_pushButton_3_clicked()
{
    int id = ui->tableView_remb->model()->data(ui->tableView_remb->model()->index(ui->tableView_remb->currentIndex().row(),0)).toInt();
    bool test = fac.supprimer_remboursement(id);
    if(test)
    {refresh();
        QMessageBox::information(nullptr, QObject::tr("supprimer "),
                    QObject::tr("suppression avec succes.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
     else
         QMessageBox::critical(nullptr, QObject::tr("supprimer"),
                     QObject::tr("echec d suppression.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
}

void mainwindow_facture::on_comboBox_remb_currentIndexChanged(int index)
{
    int prix_orig = ui->comboBox_remb->model()->data(ui->comboBox_remb->model()->index(index,4)).toInt();
    ui->lineEdit_prix_originale->setText(ui->comboBox_remb->model()->data(ui->comboBox_remb->model()->index(index,4)).toString());
    double valeur_remb = (prix_orig * ui->spinBox_remb->value())/100;
    ui->lineEdit_valeur_rembourse->setText(QString::number(valeur_remb));
}

void mainwindow_facture::on_spinBox_remb_valueChanged(int arg1)
{
    double valeur_remb = (ui->lineEdit_prix_originale->text().toInt() * arg1)/100;
    ui->lineEdit_valeur_rembourse->setText(QString::number(valeur_remb));
}


void mainwindow_facture::bilan(int annee){
    QSqlQuery query;
    QSqlQuery query1;
    QString a = QString::number(annee);
        QString qu = "SELECT SUM(prix), SUM(prix+((prix*tva)/100)) FROM FACTURE ";
        if (annee != 0) qu+=" WHERE DATEE LIKE  '%/"+a+"'";
       query.exec(qu);
       QString prix;
       QString s1;
       QString prixTVA;
       QString somme;
       int ptva;
       while (query.next()) {
                prix = query.value(0).toString();
                prixTVA = query.value(1).toString();
                ptva = query.value(1).toInt();
               ui->label_prix_tot->setText(prix);
               ui->label_prix_tva->setText(prixTVA);
           }

            QString q2 ="SELECT SUM(REMBOURSEMENT.VALUE) , SUM(FACTURE.PRIX) FROM FACTURE JOIN REMBOURSEMENT ON FACTURE.ID_FACTURE = REMBOURSEMENT.ID_FACTURE ";
            if (annee != 0) q2+=" WHERE FACTURE.DATEE LIKE  '%/"+a+"'";
          query1.exec(q2);
          while (query1.next()) {
                  somme = query1.value(0).toString();
                  s1 = query1.value(1).toString();
                  ui->label_remb->setText(somme);
              }
       int s3 = prix.toInt() - s1.toInt();
       int CA = ptva - somme.toInt();
       ui->label_fact_non_remb->setNum(s3);
       ui->label_CA->setNum(CA);

}

void mainwindow_facture::on_radioButton_clicked()
{
   bilan(0);
   ui->spinBox->setDisabled(true);
}

void mainwindow_facture::on_radioButton_2_clicked()
{
    ui->spinBox->setDisabled(false);
    bilan(ui->spinBox->value());
}

void mainwindow_facture::on_spinBox_valueChanged(int arg1)
{
    bilan(arg1);
}


QT_CHARTS_USE_NAMESPACE
void mainwindow_facture::on_pushButton_chart_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from FACTURE where prix < 90 ");
    float salaire=model->rowCount();
    model->setQuery("select * from FACTURE where prix  between 90 and 200 ");
    float salairee=model->rowCount();
    model->setQuery("select * from FACTURE where prix >200 ");
    float salaireee=model->rowCount();
    float total=salaire+salairee+salaireee;
    QString a=QString("moins de 90 dt . "+QString::number((salaire*100)/total,'f',2)+"%" );
    QString b=QString("entre 90 dt et 200 dt .  "+QString::number((salairee*100)/total,'f',2)+"%" );
    QString c=QString("plus de 300 dt ."+QString::number((salaireee*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,salaire);
    series->append(b,salairee);
    series->append(c,salaireee);
    if (salaire!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( salairee!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(salaireee!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();
    }
    // Create the chart widget
    QChart *chart = new QChart();
    // Add data to chart with title and hide legend
    chart->addSeries(series);
    chart->setTitle("prix Par Pourcentage des factures :Nombre Des factures "+ QString::number(total));
    chart->legend()->hide();
    // Used to display the chart
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(1000,500);
    chartView->show();
}

