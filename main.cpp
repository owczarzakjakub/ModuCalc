#include "mainwindow.h"
#include "src/core/lexer.h"
#include "src/core/TokenType.h"
#include "src/core/parser.h"
#include "src/core/evaluator.h"
#include "src/core/solver.h"
#include "src/ocr/OCRReader.h"
#include "src/types/complex.h"
#include <QDebug>
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
    return "UNKNOWN";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    w.show();

    cout << "----- TOKENIZER TEST -----" << endl;
    Lexer lexer;
    vector<Token> tokens = lexer.tokenize("(3+4)*5-(7/(3+sin(2)))");
    for (const Token &t : tokens) {
        cout << t.value
             << " - Precedence: " << t.precedence
             << " - TokenType: " << TokenTypeToString(t.type)
             << endl;
    }

    cout << "\n----- PARSER TEST (postfix) -----" << endl;
    Parser parser;
    vector<Token> parsedTokens = parser.parse(tokens);
    for (const Token &t : parsedTokens) {
        cout << t.value << " ";
    }
    cout << endl;

    cout << "\n----- EXPRESSION TESTS -----" << endl;


    bool hasVar = false;

    QString eq1 = "2*x + 12 = 33";
    double xVal = 0;
    double xResult = w.calculateExpression(eq1, hasVar, xVal);
    if (hasVar)
        cout << "Test 1 - x = " << xResult << endl;

    QString eq2 = "3+12*2-4";
    double result2 = w.calculateExpression(eq2, hasVar);
    cout << "Test 2 - Result = " << result2 << endl;

    QString eq3 = "2*x - 4 = 10";
    double xResult3 = w.calculateExpression(eq3, hasVar);
    if (hasVar)
        cout << "Test 3 - x = " << xResult3 << endl;

    QString eq4 = "(3+4)*5 - (7/(3+1))";
    double result4 = w.calculateExpression(eq4, hasVar);
    cout << "Test 4 - Result = " << result4 << endl;

    cout<<"------ test vector---------"<<endl;
    Vector v1({1, 2});
    Vector v2({4, 5});
    Vector suma = v1.add(v2);
    cout<<"-- "<<v1.get(0);
    cout << "Suma: ";
    for (int i = 0; i < suma.size(); i++)
        cout << suma.get(i) << " ";
    cout << endl;
    Vector roznica = v1.sub(v2);
    cout << "Roznica: ";
    for (int i = 0; i < suma.size(); i++)
        cout << roznica.get(i) << " ";
    cout << endl;
    double iloczyn = v1.dot(v2);
    cout << "Iloczyn skalarny: " << iloczyn <<endl;
    cout << "Dlugosc v1: " << v1.length() << endl;

    cout<<"------- zespolone testy ----"<<endl;
    Complex z1(3, 4);
    Complex z2(1, -2);

    Complex csuma = z1.add(z2);
    Complex croznica = z1.sub(z2);
    Complex ciloczyn = z1.multi(z2);
    Complex ciloraz = z1.div(z2);
    Complex csprzez = z1.conjugate();

    cout << "z1 + z2 = " << csuma.getReal() << "+" << csuma.getImag() << "i\n";
    cout << "z1 - z2 = " << croznica.getReal() << "+" << croznica.getImag() << "i\n";
    cout << "z1 * z2 = " << ciloczyn.getReal() << "+" << ciloczyn.getImag() << "i\n";
    cout << "z1 / z2 = " << ciloraz.getReal() << "+" << ciloraz.getImag() << "i\n";
    cout << "conjugate(z1) = " << csprzez.getReal() << "+" << csprzez.getImag() << "i\n";
    cout << "magnitude(z1) = " << z1.magnitude() << "\n";
    cout << "angle(z1) = " << z1.angle() << " rad\n";
    cout << std::flush;
    return a.exec();
}
