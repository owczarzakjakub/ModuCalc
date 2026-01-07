#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , historyManager()
    , engine(historyManager)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::appendToExpression(const QString& value)
{
    currentExpression += value.toStdString();
    ui->lineEditDisplay->setText(QString::fromStdString(currentExpression));
}


void MainWindow::on_Button0_clicked() { appendToExpression("0"); }
void MainWindow::on_Button1_clicked() { appendToExpression("1"); }
void MainWindow::on_Button2_clicked() { appendToExpression("2"); }
void MainWindow::on_Button3_clicked() { appendToExpression("3"); }
void MainWindow::on_Button4_clicked() { appendToExpression("4"); }
void MainWindow::on_Button5_clicked() { appendToExpression("5"); }
void MainWindow::on_Button6_clicked() { appendToExpression("6"); }
void MainWindow::on_Button7_clicked() { appendToExpression("7"); }
void MainWindow::on_Button8_clicked() { appendToExpression("8"); }
void MainWindow::on_Button9_clicked() { appendToExpression("9"); }


void MainWindow::on_ButtonDot_clicked() { appendToExpression("."); }
void MainWindow::on_ButtonPlus_clicked() { appendToExpression("+"); }
void MainWindow::on_ButtonMinus_clicked() { appendToExpression("-"); }
void MainWindow::on_ButtonMultiply_clicked() { appendToExpression("*"); }
void MainWindow::on_ButtonDivide_clicked() { appendToExpression("/"); }
void MainWindow::on_ButtonLParen_clicked() { appendToExpression("("); }
void MainWindow::on_ButtonRParen_clicked() { appendToExpression(")"); }
void MainWindow::on_ButtonPower_clicked() { appendToExpression("^"); }


void MainWindow::on_ButtonSin_clicked()   { appendToExpression("sin("); }
void MainWindow::on_ButtonCos_clicked()   { appendToExpression("cos("); }
void MainWindow::on_ButtonTan_clicked()   { appendToExpression("tan("); }
void MainWindow::on_ButtonCtg_clicked()   { appendToExpression("ctg("); }
void MainWindow::on_ButtonAsin_clicked()  { appendToExpression("asin("); }
void MainWindow::on_ButtonAcos_clicked()  { appendToExpression("acos("); }
void MainWindow::on_ButtonAtan_clicked()  { appendToExpression("atan("); }
void MainWindow::on_ButtonActg_clicked()  { appendToExpression("actg("); }
void MainWindow::on_ButtonLog_clicked()   { appendToExpression("log("); }
void MainWindow::on_ButtonSqrt_clicked()  { appendToExpression("sqrt("); }


void MainWindow::on_ButtonClear_clicked()
{
    currentExpression.clear();
    ui->lineEditDisplay->clear();
}

void MainWindow::on_ButtonDel_clicked()
{
    if (!currentExpression.empty()) {
        currentExpression.pop_back();
        ui->lineEditDisplay->setText(QString::fromStdString(currentExpression));
    }
}


void MainWindow::on_ButtonAns_clicked()
{
    try {
        auto last = historyManager.getLastEntry();
        appendToExpression(QString::fromStdString(last.second.toString()));
    } catch (...) {
        QMessageBox::information(this, "ANS", "Brak poprzedniego wyniku");
    }
}


void MainWindow::on_ButtonEqual_clicked()
{
    try {
        double result = 0;
        bool hasVariable = false;

        if (currentExpression.find("x") != std::string::npos || currentExpression.find("X") != std::string::npos)
        {
            result = calculateExpression(QString::fromStdString(currentExpression), hasVariable);
        }
        else
        {
            Number numResult = engine.runScript(currentExpression);
            result = numResult.toDouble();
        }

        ui->lineEditDisplay->setText(QString::number(result));
        historyManager.addEntry(currentExpression, Number(result));
        currentExpression.clear();
    }
    catch (const std::exception &e) {
        QMessageBox::warning(this, "Błąd", e.what());
    }
}


double MainWindow::calculateExpression(const QString &expr, bool &hasVariable, double xValue)
{
    QStringList sides = expr.split("=");
    QString combinedExpr;
    if (sides.size() == 2) {
        combinedExpr = sides[0] + "-(" + sides[1] + ")";
    } else {
        combinedExpr = expr;
    }

    std::string input = combinedExpr.toStdString();
    auto tokens = lexer.tokenize(input);

    hasVariable = false;
    for (const Token &t : tokens) {
        if (t.type == TokenType::VARIABLE) {
            hasVariable = true;
            break;
        }
    }

    auto parsedTokens = parser.parse(tokens);

    if (hasVariable) {
        auto result = solver.solve(parsedTokens);
        return result.coefX != 0 ? -result.constant / result.coefX : 0;
    } else {
        Number result = evaluator.evaluate(parsedTokens);
        return result.toDouble();
    }
}


void MainWindow::on_ButtonRownaSie_clicked()
{
    appendToExpression("=");
}


void MainWindow::on_ButtonX_clicked()
{
    appendToExpression("x");
}

