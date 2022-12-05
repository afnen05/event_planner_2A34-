#ifndef MAINWINDOW_FACTURE_H
#define MAINWINDOW_FACTURE_H
#include "arduino_facture.h"
#include "facture.h"
#include <QDialog>

namespace Ui {
class mainwindow_facture;
}

class mainwindow_facture : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow_facture(QWidget *parent = nullptr);
    ~mainwindow_facture();
    void refresh();
    void bilan(int);
private slots:

    void on_buttonBox_accepted();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_clicked();

    void on_pushButton_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_2_clicked();


    void on_pdf_clicked();

void update_label();

    void on_comboBox_events_currentIndexChanged(int index);

    void on_comboBox_events_2_currentIndexChanged(int index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_remb_clicked();

    void on_pushButton_3_clicked();

    void on_comboBox_remb_currentIndexChanged(int index);

    void on_spinBox_remb_valueChanged(int arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_chart_clicked();



private:
    Ui::mainwindow_facture *ui;
    facture fac;
    QString ch,ch1;
    QByteArray data2; // variable contenant les données reçues
    arduino_facture AF ;
};

#endif // MAINWINDOW_FACTURE_H
