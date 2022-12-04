#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "arduino.h"
#include <QMainWindow>
#include "facture.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void refresh();
    void bilan(int);

private slots:

    void on_buttonBox_accepted();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_modifier_clicked();

    void on_comboBox_activated(const QString &arg1);

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

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

private:
    facture fac;
   QString ch,ch1;
    Ui::MainWindow *ui;
    QByteArray data; // variable contenant les données reçues

    arduino A; // objet temporaire
};

#endif // MAINWINDOW_H
