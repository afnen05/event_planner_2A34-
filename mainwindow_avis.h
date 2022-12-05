#ifndef MAINWINDOW_AVIS_H
#define MAINWINDOW_AVIS_H

#include <QDialog>
#include"avis.h"
#include"arduino.h"
#include "smtpp.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class mainwindow_avis;
}
QT_END_NAMESPACE
class mainwindow_avis : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindow_avis(QWidget *parent = nullptr);
    ~mainwindow_avis();
private slots:

    void on_ajouter_clicked();
    void on_supprimer_2_clicked();
    void on_pbpdf_clicked();


    void on_le_nom_2_textChanged(const QString &arg1);//recherche
    void on_pushButton_clicked();//TRIS


    void mailSent(QString);




    void on_browseBtn_clicked();

    void on_sendBtn_clicked();

    void on_pushButton_3_clicked();

    // ce slot est lancé à chaque réception d'un message de Arduino
    void update_label();

    void on_on_clicked();   // bouton ON

    void on_off_clicked(); // bouton OFF

    void on_plus_clicked(); // bouton +

    void on_moin_clicked(); // bouton -


private:
    Ui::mainwindow_avis *ui;
    Smtpp *smtpp;
    QStringList files;
    avis A;
    Arduino AA;
    QByteArray data4;
};

#endif // MAINWINDOW_AVIS_H
