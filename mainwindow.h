#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include"avis.h"
#include"arduino.h"

#include"smtp.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();
    void on_supprimer_2_clicked();
    void on_pbpdf_clicked();
    void on_modifier_clicked();

    void on_le_nom_2_textChanged(const QString &arg1);//recherche
    void on_pushButton_clicked();//TRIS

    void sendMail();
    void mailSent(QString);
    void browse();



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
    Ui::MainWindow *ui;
    Smtp* smtp;
    QStringList files;
   avis A;
    Arduino A1;
    QByteArray data;

};
#endif
