/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *centralwidget_2;
    QLineEdit *lineEditDisplay;
    QPushButton *Button3;
    QPushButton *Button4;
    QPushButton *Button5;
    QPushButton *Button6;
    QPushButton *Button7;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *ButtonPlus;
    QPushButton *ButtonMinus;
    QPushButton *ButtonMultiply;
    QPushButton *ButtonDivide;
    QPushButton *ButtonPower;
    QPushButton *ButtonEqual;
    QPushButton *ButtonSin;
    QPushButton *ButtonCos;
    QPushButton *Button0;
    QPushButton *ButtonTan;
    QPushButton *ButtonCtg;
    QPushButton *ButtonAsin;
    QPushButton *ButtonAcos;
    QPushButton *ButtonAtan;
    QPushButton *ButtonLog;
    QPushButton *ButtonSqrt;
    QPushButton *ButtonLParen;
    QPushButton *ButtonRParen;
    QPushButton *ButtonClear;
    QPushButton *ButtonDel;
    QPushButton *ButtonAns;
    QPushButton *ButtonDot;
    QPushButton *Button1;
    QPushButton *Button2;
    QPushButton *ButtonX;
    QPushButton *ButtonRownaSie;
    QStatusBar *statusbar_2;
    QSpinBox *spinRows;
    QSpinBox *spinCols;
    QTableWidget *tableMatrixA;
    QTableWidget *tableMatrixB;
    QTableWidget *tableResult;
    QPushButton *btnAdd;
    QPushButton *btnMul;
    QPushButton *pushButton_3;
    QPushButton *btnSub;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1310, 540);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget_2 = new QWidget(centralwidget);
        centralwidget_2->setObjectName("centralwidget_2");
        centralwidget_2->setGeometry(QRect(0, 20, 361, 491));
        lineEditDisplay = new QLineEdit(centralwidget_2);
        lineEditDisplay->setObjectName("lineEditDisplay");
        lineEditDisplay->setGeometry(QRect(10, 30, 351, 131));
        lineEditDisplay->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        lineEditDisplay->setReadOnly(false);
        Button3 = new QPushButton(centralwidget_2);
        Button3->setObjectName("Button3");
        Button3->setGeometry(QRect(190, 340, 80, 24));
        Button4 = new QPushButton(centralwidget_2);
        Button4->setObjectName("Button4");
        Button4->setGeometry(QRect(10, 310, 80, 24));
        Button5 = new QPushButton(centralwidget_2);
        Button5->setObjectName("Button5");
        Button5->setGeometry(QRect(100, 310, 80, 24));
        Button6 = new QPushButton(centralwidget_2);
        Button6->setObjectName("Button6");
        Button6->setGeometry(QRect(190, 310, 80, 24));
        Button7 = new QPushButton(centralwidget_2);
        Button7->setObjectName("Button7");
        Button7->setGeometry(QRect(10, 280, 81, 21));
        Button8 = new QPushButton(centralwidget_2);
        Button8->setObjectName("Button8");
        Button8->setGeometry(QRect(100, 280, 80, 24));
        Button9 = new QPushButton(centralwidget_2);
        Button9->setObjectName("Button9");
        Button9->setGeometry(QRect(190, 280, 80, 24));
        ButtonPlus = new QPushButton(centralwidget_2);
        ButtonPlus->setObjectName("ButtonPlus");
        ButtonPlus->setGeometry(QRect(280, 370, 80, 24));
        ButtonMinus = new QPushButton(centralwidget_2);
        ButtonMinus->setObjectName("ButtonMinus");
        ButtonMinus->setGeometry(QRect(280, 340, 80, 24));
        ButtonMultiply = new QPushButton(centralwidget_2);
        ButtonMultiply->setObjectName("ButtonMultiply");
        ButtonMultiply->setGeometry(QRect(280, 310, 80, 24));
        ButtonDivide = new QPushButton(centralwidget_2);
        ButtonDivide->setObjectName("ButtonDivide");
        ButtonDivide->setGeometry(QRect(280, 280, 80, 24));
        ButtonPower = new QPushButton(centralwidget_2);
        ButtonPower->setObjectName("ButtonPower");
        ButtonPower->setGeometry(QRect(280, 410, 80, 24));
        ButtonEqual = new QPushButton(centralwidget_2);
        ButtonEqual->setObjectName("ButtonEqual");
        ButtonEqual->setGeometry(QRect(190, 370, 80, 24));
        ButtonSin = new QPushButton(centralwidget_2);
        ButtonSin->setObjectName("ButtonSin");
        ButtonSin->setGeometry(QRect(10, 190, 80, 24));
        ButtonCos = new QPushButton(centralwidget_2);
        ButtonCos->setObjectName("ButtonCos");
        ButtonCos->setGeometry(QRect(100, 190, 80, 24));
        Button0 = new QPushButton(centralwidget_2);
        Button0->setObjectName("Button0");
        Button0->setGeometry(QRect(10, 370, 80, 24));
        ButtonTan = new QPushButton(centralwidget_2);
        ButtonTan->setObjectName("ButtonTan");
        ButtonTan->setGeometry(QRect(190, 190, 80, 24));
        ButtonCtg = new QPushButton(centralwidget_2);
        ButtonCtg->setObjectName("ButtonCtg");
        ButtonCtg->setGeometry(QRect(280, 190, 80, 24));
        ButtonAsin = new QPushButton(centralwidget_2);
        ButtonAsin->setObjectName("ButtonAsin");
        ButtonAsin->setGeometry(QRect(10, 220, 80, 24));
        ButtonAcos = new QPushButton(centralwidget_2);
        ButtonAcos->setObjectName("ButtonAcos");
        ButtonAcos->setGeometry(QRect(100, 220, 80, 24));
        ButtonAtan = new QPushButton(centralwidget_2);
        ButtonAtan->setObjectName("ButtonAtan");
        ButtonAtan->setGeometry(QRect(190, 220, 80, 24));
        ButtonLog = new QPushButton(centralwidget_2);
        ButtonLog->setObjectName("ButtonLog");
        ButtonLog->setGeometry(QRect(10, 250, 80, 24));
        ButtonSqrt = new QPushButton(centralwidget_2);
        ButtonSqrt->setObjectName("ButtonSqrt");
        ButtonSqrt->setGeometry(QRect(100, 250, 80, 24));
        ButtonLParen = new QPushButton(centralwidget_2);
        ButtonLParen->setObjectName("ButtonLParen");
        ButtonLParen->setGeometry(QRect(190, 250, 80, 24));
        ButtonRParen = new QPushButton(centralwidget_2);
        ButtonRParen->setObjectName("ButtonRParen");
        ButtonRParen->setGeometry(QRect(280, 250, 80, 24));
        ButtonClear = new QPushButton(centralwidget_2);
        ButtonClear->setObjectName("ButtonClear");
        ButtonClear->setGeometry(QRect(10, 410, 80, 24));
        ButtonDel = new QPushButton(centralwidget_2);
        ButtonDel->setObjectName("ButtonDel");
        ButtonDel->setGeometry(QRect(100, 410, 80, 24));
        ButtonAns = new QPushButton(centralwidget_2);
        ButtonAns->setObjectName("ButtonAns");
        ButtonAns->setGeometry(QRect(190, 410, 80, 24));
        ButtonDot = new QPushButton(centralwidget_2);
        ButtonDot->setObjectName("ButtonDot");
        ButtonDot->setGeometry(QRect(100, 370, 80, 24));
        Button1 = new QPushButton(centralwidget_2);
        Button1->setObjectName("Button1");
        Button1->setGeometry(QRect(10, 340, 80, 24));
        Button2 = new QPushButton(centralwidget_2);
        Button2->setObjectName("Button2");
        Button2->setGeometry(QRect(100, 340, 80, 24));
        ButtonX = new QPushButton(centralwidget_2);
        ButtonX->setObjectName("ButtonX");
        ButtonX->setGeometry(QRect(100, 440, 80, 24));
        ButtonRownaSie = new QPushButton(centralwidget_2);
        ButtonRownaSie->setObjectName("ButtonRownaSie");
        ButtonRownaSie->setGeometry(QRect(190, 440, 80, 24));
        statusbar_2 = new QStatusBar(centralwidget);
        statusbar_2->setObjectName("statusbar_2");
        statusbar_2->setGeometry(QRect(330, 220, 3, 22));
        spinRows = new QSpinBox(centralwidget);
        spinRows->setObjectName("spinRows");
        spinRows->setEnabled(true);
        spinRows->setGeometry(QRect(720, 240, 42, 25));
        spinRows->setValue(2);
        spinCols = new QSpinBox(centralwidget);
        spinCols->setObjectName("spinCols");
        spinCols->setGeometry(QRect(1000, 240, 42, 25));
        spinCols->setValue(2);
        tableMatrixA = new QTableWidget(centralwidget);
        tableMatrixA->setObjectName("tableMatrixA");
        tableMatrixA->setGeometry(QRect(460, 30, 256, 192));
        tableMatrixB = new QTableWidget(centralwidget);
        tableMatrixB->setObjectName("tableMatrixB");
        tableMatrixB->setGeometry(QRect(750, 30, 256, 192));
        tableResult = new QTableWidget(centralwidget);
        tableResult->setObjectName("tableResult");
        tableResult->setGeometry(QRect(1030, 30, 256, 192));
        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setGeometry(QRect(520, 280, 80, 24));
        btnMul = new QPushButton(centralwidget);
        btnMul->setObjectName("btnMul");
        btnMul->setGeometry(QRect(700, 280, 80, 24));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(890, 280, 80, 24));
        btnSub = new QPushButton(centralwidget);
        btnSub->setObjectName("btnSub");
        btnSub->setGeometry(QRect(610, 280, 80, 24));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(790, 280, 91, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1310, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        Button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        Button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        Button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        Button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        Button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        ButtonPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        ButtonMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        ButtonMultiply->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        ButtonDivide->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        ButtonPower->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        ButtonEqual->setText(QCoreApplication::translate("MainWindow", "RESULT", nullptr));
        ButtonSin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        ButtonCos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        Button0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        ButtonTan->setText(QCoreApplication::translate("MainWindow", "tg", nullptr));
        ButtonCtg->setText(QCoreApplication::translate("MainWindow", "ctg", nullptr));
        ButtonAsin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
        ButtonAcos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
        ButtonAtan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        ButtonLog->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        ButtonSqrt->setText(QCoreApplication::translate("MainWindow", "sqrt", nullptr));
        ButtonLParen->setText(QCoreApplication::translate("MainWindow", "(", nullptr));
        ButtonRParen->setText(QCoreApplication::translate("MainWindow", ")", nullptr));
        ButtonClear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        ButtonDel->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
        ButtonAns->setText(QCoreApplication::translate("MainWindow", "ANS", nullptr));
        ButtonDot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        Button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        Button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        ButtonX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        ButtonRownaSie->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "A+B", nullptr));
        btnMul->setText(QCoreApplication::translate("MainWindow", "A*B", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        btnSub->setText(QCoreApplication::translate("MainWindow", "A-B", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "TransposeA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
