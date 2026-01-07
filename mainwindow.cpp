#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
double MainWindow::calculateExpression(const QString &expr,bool &hasVariable,double xValue){
    QStringList sides=expr.split("=");
    QString combinedExpr;
    if(sides.size()==2){
        combinedExpr=sides[0]+"-("+sides[1]+')';
    }
    else{
        combinedExpr=expr;
    }

    std::string input=combinedExpr.toStdString();
    auto tokens=lexer.tokenize(input);
    hasVariable=false;
    for(const Token &t : tokens){
        if(t.type==TokenType::VARIABLE){
            hasVariable=true;
            break;
        }
    }
    auto parsedTokens=parser.parse(tokens);
    if(hasVariable){
        auto result=solver.solve(parsedTokens);
        return result.coefX != 0 ? -result.constant / result.coefX : 0;
    }
    else{
        Number result=evaluator.evaluate(parsedTokens);
        return result.toDouble();
    }
}
