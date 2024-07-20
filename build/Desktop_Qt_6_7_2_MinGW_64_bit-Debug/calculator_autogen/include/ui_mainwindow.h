/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btndivide;
    QPushButton *btnmultiple;
    QPushButton *btnadd;
    QPushButton *btnsub;
    QPushButton *btnanswer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLineEdit *lineEdit_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btndivide = new QPushButton(centralwidget);
        btndivide->setObjectName("btndivide");
        btndivide->setGeometry(QRect(480, 250, 93, 51));
        btnmultiple = new QPushButton(centralwidget);
        btnmultiple->setObjectName("btnmultiple");
        btnmultiple->setGeometry(QRect(480, 320, 93, 51));
        btnadd = new QPushButton(centralwidget);
        btnadd->setObjectName("btnadd");
        btnadd->setGeometry(QRect(480, 390, 93, 51));
        btnsub = new QPushButton(centralwidget);
        btnsub->setObjectName("btnsub");
        btnsub->setGeometry(QRect(480, 460, 93, 51));
        btnanswer = new QPushButton(centralwidget);
        btnanswer->setObjectName("btnanswer");
        btnanswer->setGeometry(QRect(600, 460, 93, 51));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(350, 250, 93, 51));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(350, 320, 93, 51));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(350, 390, 93, 51));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(240, 250, 93, 51));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(240, 320, 93, 51));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(240, 390, 93, 51));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(130, 250, 93, 51));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(130, 320, 93, 51));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(130, 390, 93, 51));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(130, 460, 93, 51));
        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(240, 460, 93, 51));
        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(350, 460, 93, 51));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 80, 441, 151));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btndivide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        btnmultiple->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        btnadd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnsub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnanswer->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
