#pragma once

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QTableWidget>
#include "src/history/scriptengine.h"
#include "historymanager.h"
#include "src/types/number.h"
#include "src/core/lexer.h"
#include "src/core/parser.h"
#include "src/core/evaluator.h"
#include "src/core/solver.h"
#include "src/types/matrix.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double calculateExpression(const QString &expr, bool &hasVariable, double xValue = 0);

private slots:
    // Kalkulator
    void on_Button0_clicked();
    void on_Button1_clicked();
    void on_Button2_clicked();
    void on_Button3_clicked(); // Uwaga: To jest cyfra 3, nie mylić z Clear (pushButton_3)
    void on_Button4_clicked();
    void on_Button5_clicked(); // Uwaga: To jest cyfra 5
    void on_Button6_clicked();
    void on_Button7_clicked();
    void on_Button8_clicked();
    void on_Button9_clicked();

    void on_ButtonPlus_clicked();
    void on_ButtonMinus_clicked();
    void on_ButtonMultiply_clicked();
    void on_ButtonDivide_clicked();
    void on_ButtonDot_clicked();
    void on_ButtonEqual_clicked();
    void on_ButtonClear_clicked(); // To jest 'C' kalkulatora

    void on_ButtonLParen_clicked();
    void on_ButtonRParen_clicked();
    void on_ButtonPower_clicked();
    void on_ButtonDel_clicked();
    void on_ButtonAns_clicked();
    void on_ButtonRownaSie_clicked();
    void on_ButtonX_clicked();

    // Funkcje trygonometryczne
    void on_ButtonSin_clicked();
    void on_ButtonCos_clicked();
    void on_ButtonTan_clicked();
    void on_ButtonCtg_clicked();
    void on_ButtonAsin_clicked();
    void on_ButtonAcos_clicked();
    void on_ButtonAtan_clicked();
    void on_ButtonActg_clicked();
    void on_ButtonLog_clicked();
    void on_ButtonSqrt_clicked();

    // --- MACIERZE (Zgodne z Twoim UI) ---
    void on_btnAdd_clicked();
    void on_btnSub_clicked();
    void on_btnMul_clicked();

    // UI nazwało te przyciski automatycznie:
    void on_pushButton_5_clicked(); // To jest TransposeA
    void on_pushButton_3_clicked(); // To jest Clear Macierzy

    void on_spinRowsA_valueChanged(int arg1);
    void on_spinColsA_valueChanged(int arg1);
    void on_spinRowsB_valueChanged(int arg1);
    void on_spinColsB_valueChanged(int arg1);

    void on_ButtonTransposeB_clicked();

private:
    Ui::MainWindow *ui;

    HistoryManager historyManager;
    ScriptEngine engine;
    std::string currentExpression;

    Lexer lexer;
    Parser parser;
    Evaluator evaluator;
    Solver solver;

    // Metody pomocnicze
    void appendToExpression(const QString& value);
    void setupMatrixTables(); // Konfiguracja początkowa tabel
    Matrix readMatrixFromTable(QTableWidget* table);
    void writeMatrixToTable(QTableWidget* table, const Matrix& m);
};
