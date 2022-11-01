#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "event.h"
#include <QMainWindow>

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
    void on_push1_clicked();

    void on_supprimer_clicked();

    void on_Modifier_clicked();

private:
    Ui::MainWindow *ui;
    Event E;
};
#endif // MAINWINDOW_H
