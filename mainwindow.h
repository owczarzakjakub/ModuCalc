#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "src/core/lexer.h"
#include "src/core/parser.h"
#include "src/core/evaluator.h"
#include "src/core/solver.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    double calculateExpression(const QString &expr, bool &hasVariable,double xValue=0);


private:
    Ui::MainWindow *ui;
    Lexer lexer;
    Parser parser;
    Evaluator evaluator;
    Solver solver;
};
#endif // MAINWINDOW_H
