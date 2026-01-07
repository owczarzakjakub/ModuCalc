#include "mainwindow.h"
#include "src/core/lexer.h"
#include "src/core/TokenType.h"
#include "src/core/parser.h"
#include "src/core/evaluator.h"
#include "src/core/solver.h"
#include <vector>
#include <iostream>
#include <string>
#include <QApplication>

using namespace std;

string TokenTypeToString(TokenType type){
    switch(type){
    case TokenType::NUMBER: return "NUMBER";
    case TokenType::OPERATOR: return "OPERATOR";
    case TokenType::FUNCTION: return "FUNCTION";
    case TokenType::LPAREN: return "LPAREN";
    case TokenType::RPAREN: return "RPAREN";
    case TokenType::COMMA: return "COMMA";
    case TokenType::VARIABLE: return "VARIABLE";
    case TokenType::UNKNOWN: return "UNKNOWN";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    bool hasVar;


    QString eq1 = "2*x + 12 = 33";
    double xVal = 0;
    double xResult = w.calculateExpression(eq1, hasVar, xVal);
    if(hasVar)
        std::cout << "Test 1 - x = " << xResult << std::endl;

    // Test 2: zwykłe wyrażenie
    QString eq2 = "3+12*2-4";
    double result2 = w.calculateExpression(eq2, hasVar);
    std::cout << "Test 2 - Result = " << result2 << std::endl;


    QString eq3 = "2*x - 4 = 10";
    double xResult3 = w.calculateExpression(eq3, hasVar);
    if(hasVar)
        std::cout << "Test 3 - x = " << xResult3 << std::endl;


    QString eq4 = "(3+4)*5 - (7/(3+1))";
    double result4 = w.calculateExpression(eq4, hasVar);
    std::cout << "Test 4 - Result = " << result4 << std::endl;

    return a.exec();
}
