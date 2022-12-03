/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *af;
    QLabel *label;
    QLineEdit *nf;
    QPushButton *pb_ajouter;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QTableWidget *tablen;
    QDialogButtonBox *buttonBox;
    QLineEdit *off;
    QDateEdit *dateEdit;
    QComboBox *comboBox_events;
    QLineEdit *lineEdit_prix;
    QLabel *label_14;
    QSpinBox *spinBox_tva;
    QWidget *tab_2;
    QTableView *tab_fac;
    QLabel *label_6;
    QLineEdit *nf2;
    QPushButton *modifier;
    QPushButton *pushButton;
    QComboBox *comboBox;
    QPushButton *pdf;
    QLineEdit *off_2;
    QSpinBox *spinBox_tva_2;
    QLabel *label_15;
    QComboBox *comboBox_events_2;
    QLabel *label_16;
    QLabel *label_4;
    QDateEdit *dateEdit_2;
    QLineEdit *lineEdit_prix_2;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QPushButton *pushButton_chart;
    QPushButton *pb_supprimer;
    QLabel *label_2;
    QLineEdit *supp;
    QWidget *tab_4;
    QGroupBox *groupBox;
    QLabel *label_8;
    QComboBox *comboBox_remb;
    QLabel *label_9;
    QSpinBox *spinBox_remb;
    QPushButton *pushButton_remb;
    QLabel *label_11;
    QLabel *label_13;
    QLineEdit *lineEdit_prix_originale;
    QLineEdit *lineEdit_valeur_rembourse;
    QTableView *tableView_remb;
    QPushButton *pushButton_3;
    QWidget *tab_5;
    QGroupBox *groupBox_2;
    QLabel *label_17;
    QLabel *label_prix_tot;
    QLabel *label_prix_tva;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_remb;
    QLabel *label_23;
    QLabel *label_fact_non_remb;
    QLabel *label_25;
    QLabel *label_CA;
    QGroupBox *groupBox_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpinBox *spinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1319, 745);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 10, 1121, 631));
        tabWidget->setStyleSheet(QStringLiteral("background-color: rgb(252, 231, 212);"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        af = new QGroupBox(tab);
        af->setObjectName(QStringLiteral("af"));
        af->setGeometry(QRect(20, 20, 1001, 561));
        label = new QLabel(af);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 101, 20));
        nf = new QLineEdit(af);
        nf->setObjectName(QStringLiteral("nf"));
        nf->setGeometry(QRect(120, 30, 113, 20));
        pb_ajouter = new QPushButton(af);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(50, 510, 111, 31));
        label_10 = new QLabel(af);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 30, 47, 14));
        label_12 = new QLabel(af);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 80, 101, 16));
        label_3 = new QLabel(af);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 160, 41, 20));
        toolButton = new QToolButton(af);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(420, 160, 32, 26));
        toolButton_2 = new QToolButton(af);
        toolButton_2->setObjectName(QStringLiteral("toolButton_2"));
        toolButton_2->setGeometry(QRect(340, 160, 32, 26));
        toolButton_3 = new QToolButton(af);
        toolButton_3->setObjectName(QStringLiteral("toolButton_3"));
        toolButton_3->setGeometry(QRect(380, 160, 32, 26));
        tablen = new QTableWidget(af);
        if (tablen->columnCount() < 4)
            tablen->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tablen->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tablen->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tablen->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tablen->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tablen->setObjectName(QStringLiteral("tablen"));
        tablen->setGeometry(QRect(30, 220, 611, 271));
        buttonBox = new QDialogButtonBox(af);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(180, 510, 230, 34));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        off = new QLineEdit(af);
        off->setObjectName(QStringLiteral("off"));
        off->setGeometry(QRect(100, 160, 201, 20));
        dateEdit = new QDateEdit(af);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(380, 20, 110, 25));
        comboBox_events = new QComboBox(af);
        comboBox_events->setObjectName(QStringLiteral("comboBox_events"));
        comboBox_events->setGeometry(QRect(120, 70, 131, 31));
        lineEdit_prix = new QLineEdit(af);
        lineEdit_prix->setObjectName(QStringLiteral("lineEdit_prix"));
        lineEdit_prix->setGeometry(QRect(290, 70, 151, 31));
        lineEdit_prix->setReadOnly(true);
        label_14 = new QLabel(af);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(30, 120, 101, 16));
        spinBox_tva = new QSpinBox(af);
        spinBox_tva->setObjectName(QStringLiteral("spinBox_tva"));
        spinBox_tva->setGeometry(QRect(120, 110, 131, 31));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_fac = new QTableView(tab_2);
        tab_fac->setObjectName(QStringLiteral("tab_fac"));
        tab_fac->setGeometry(QRect(10, 20, 651, 331));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(680, 20, 91, 20));
        nf2 = new QLineEdit(tab_2);
        nf2->setObjectName(QStringLiteral("nf2"));
        nf2->setGeometry(QRect(810, 20, 113, 20));
        modifier = new QPushButton(tab_2);
        modifier->setObjectName(QStringLiteral("modifier"));
        modifier->setGeometry(QRect(850, 290, 101, 31));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(40, 380, 101, 31));
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(170, 380, 181, 31));
        pdf = new QPushButton(tab_2);
        pdf->setObjectName(QStringLiteral("pdf"));
        pdf->setGeometry(QRect(700, 290, 101, 31));
        off_2 = new QLineEdit(tab_2);
        off_2->setObjectName(QStringLiteral("off_2"));
        off_2->setGeometry(QRect(800, 220, 201, 20));
        spinBox_tva_2 = new QSpinBox(tab_2);
        spinBox_tva_2->setObjectName(QStringLiteral("spinBox_tva_2"));
        spinBox_tva_2->setGeometry(QRect(800, 170, 131, 31));
        label_15 = new QLabel(tab_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(680, 170, 101, 16));
        comboBox_events_2 = new QComboBox(tab_2);
        comboBox_events_2->setObjectName(QStringLiteral("comboBox_events_2"));
        comboBox_events_2->setGeometry(QRect(780, 120, 131, 31));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(680, 120, 101, 21));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(680, 220, 41, 20));
        dateEdit_2 = new QDateEdit(tab_2);
        dateEdit_2->setObjectName(QStringLiteral("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(830, 70, 110, 25));
        lineEdit_prix_2 = new QLineEdit(tab_2);
        lineEdit_prix_2->setObjectName(QStringLiteral("lineEdit_prix_2"));
        lineEdit_prix_2->setGeometry(QRect(940, 120, 151, 31));
        lineEdit_prix_2->setReadOnly(true);
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(680, 70, 91, 20));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(170, 430, 181, 31));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(60, 430, 91, 31));
        pushButton_chart = new QPushButton(tab_2);
        pushButton_chart->setObjectName(QStringLiteral("pushButton_chart"));
        pushButton_chart->setGeometry(QRect(980, 290, 112, 34));
        pb_supprimer = new QPushButton(tab_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(320, 530, 91, 31));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 530, 111, 20));
        supp = new QLineEdit(tab_2);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(170, 530, 113, 20));
        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox = new QGroupBox(tab_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(60, 70, 361, 431));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 70, 91, 20));
        comboBox_remb = new QComboBox(groupBox);
        comboBox_remb->setObjectName(QStringLiteral("comboBox_remb"));
        comboBox_remb->setGeometry(QRect(180, 55, 111, 41));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 190, 111, 20));
        spinBox_remb = new QSpinBox(groupBox);
        spinBox_remb->setObjectName(QStringLiteral("spinBox_remb"));
        spinBox_remb->setGeometry(QRect(180, 160, 111, 51));
        pushButton_remb = new QPushButton(groupBox);
        pushButton_remb->setObjectName(QStringLiteral("pushButton_remb"));
        pushButton_remb->setGeometry(QRect(100, 290, 112, 34));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(30, 120, 101, 31));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(30, 240, 131, 31));
        lineEdit_prix_originale = new QLineEdit(groupBox);
        lineEdit_prix_originale->setObjectName(QStringLiteral("lineEdit_prix_originale"));
        lineEdit_prix_originale->setGeometry(QRect(182, 114, 111, 31));
        lineEdit_prix_originale->setReadOnly(true);
        lineEdit_valeur_rembourse = new QLineEdit(groupBox);
        lineEdit_valeur_rembourse->setObjectName(QStringLiteral("lineEdit_valeur_rembourse"));
        lineEdit_valeur_rembourse->setGeometry(QRect(180, 230, 111, 41));
        lineEdit_valeur_rembourse->setReadOnly(true);
        tableView_remb = new QTableView(tab_4);
        tableView_remb->setObjectName(QStringLiteral("tableView_remb"));
        tableView_remb->setGeometry(QRect(460, 80, 531, 351));
        pushButton_3 = new QPushButton(tab_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(460, 450, 112, 34));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_2 = new QGroupBox(tab_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(480, 80, 591, 421));
        label_17 = new QLabel(groupBox_2);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(30, 70, 341, 51));
        label_17->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_prix_tot = new QLabel(groupBox_2);
        label_prix_tot->setObjectName(QStringLiteral("label_prix_tot"));
        label_prix_tot->setGeometry(QRect(480, 80, 161, 51));
        label_prix_tot->setStyleSheet(QStringLiteral("font: 75 16pt \"MS Shell Dlg 2\";"));
        label_prix_tva = new QLabel(groupBox_2);
        label_prix_tva->setObjectName(QStringLiteral("label_prix_tva"));
        label_prix_tva->setGeometry(QRect(480, 140, 161, 51));
        label_prix_tva->setStyleSheet(QStringLiteral("font: 75 16pt \"MS Shell Dlg 2\";"));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(30, 130, 341, 51));
        label_20->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(30, 190, 441, 51));
        label_21->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_remb = new QLabel(groupBox_2);
        label_remb->setObjectName(QStringLiteral("label_remb"));
        label_remb->setGeometry(QRect(480, 200, 161, 51));
        label_remb->setStyleSheet(QStringLiteral("font: 75 16pt \"MS Shell Dlg 2\";"));
        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(110, 330, 341, 51));
        label_23->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_fact_non_remb = new QLabel(groupBox_2);
        label_fact_non_remb->setObjectName(QStringLiteral("label_fact_non_remb"));
        label_fact_non_remb->setGeometry(QRect(480, 250, 161, 51));
        label_fact_non_remb->setStyleSheet(QStringLiteral("font: 75 16pt \"MS Shell Dlg 2\";"));
        label_25 = new QLabel(groupBox_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(30, 240, 451, 71));
        label_25->setStyleSheet(QStringLiteral("font: 75 12pt \"MS Shell Dlg 2\";"));
        label_CA = new QLabel(groupBox_2);
        label_CA->setObjectName(QStringLiteral("label_CA"));
        label_CA->setGeometry(QRect(360, 330, 161, 51));
        label_CA->setStyleSheet(QStringLiteral("font: 75 16pt \"MS Shell Dlg 2\";"));
        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(40, 150, 331, 211));
        radioButton = new QRadioButton(groupBox_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(40, 70, 191, 24));
        radioButton_2 = new QRadioButton(groupBox_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(40, 120, 120, 24));
        spinBox = new QSpinBox(groupBox_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(190, 120, 101, 25));
        spinBox->setMinimum(2015);
        spinBox->setMaximum(2023);
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1319, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        af->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "N\302\260 Facture", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "evenement", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Offre", Q_NULLPTR));
        toolButton->setText(QApplication::translate("MainWindow", "...", Q_NULLPTR));
        toolButton_2->setText(QApplication::translate("MainWindow", "+", Q_NULLPTR));
        toolButton_3->setText(QApplication::translate("MainWindow", "-", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tablen->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "N\302\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tablen->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Qt\303\251", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tablen->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Designation", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tablen->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Prix unitaire", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "TVA (%)", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter une facture", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "N\302\260 Facture", Q_NULLPTR));
        modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "TVA", Q_NULLPTR)
         << QApplication::translate("MainWindow", "PRIX", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ID_FACTURE", Q_NULLPTR)
        );
        pdf->setText(QApplication::translate("MainWindow", "pdf", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "TVA (%)", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "evenement", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Offre", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "date", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "recherche :", Q_NULLPTR));
        pushButton_chart->setText(QApplication::translate("MainWindow", "chart", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "ID_Facture", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher les facture", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "creer nouveau", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "id facture :", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "pourcentage", Q_NULLPTR));
        pushButton_remb->setText(QApplication::translate("MainWindow", "ajouter", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "prix originale :", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "valeur rembours\303\251 :", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "remboursements", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Bilan", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "prix totale des factures : ", Q_NULLPTR));
        label_prix_tot->setText(QApplication::translate("MainWindow", "000", Q_NULLPTR));
        label_prix_tva->setText(QApplication::translate("MainWindow", "000", Q_NULLPTR));
        label_20->setText(QApplication::translate("MainWindow", "prix totale des factures + TVA: ", Q_NULLPTR));
        label_21->setText(QApplication::translate("MainWindow", "somme de remboursements (perte) : ", Q_NULLPTR));
        label_remb->setText(QApplication::translate("MainWindow", "000", Q_NULLPTR));
        label_23->setText(QApplication::translate("MainWindow", "chiffre d'affaire = ", Q_NULLPTR));
        label_fact_non_remb->setText(QApplication::translate("MainWindow", "000", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "prix totale des factures non rembours\303\251s : ", Q_NULLPTR));
        label_CA->setText(QApplication::translate("MainWindow", "000", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "periode", Q_NULLPTR));
        radioButton->setText(QApplication::translate("MainWindow", "tous les annee", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("MainWindow", "annee", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "chiffre d'affaire", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
