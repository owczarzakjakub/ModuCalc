#include "mainwindow.h"
#include "src/core/lexer.h"
#include "src/core/TokenType.h"
#include "src/core/parser.h"
#include <vector>
#include <iostream>
#include <string>
#include <QApplication>

using namespace std;

string TokenTypeToString(TokenType type){
    switch(type){
    case TokenType::NUMBER:
        return "NUMBER";
    case TokenType::OPERATOR:
        return "OPERATOR";
    case TokenType::FUNCTION:
        return "FUNCTION";
    case TokenType::LPAREN:
        return "LPAREN";
    case TokenType::RPAREN:
        return "RPAREN";
    case TokenType::COMMA:
        return "COMMA";
    case TokenType::VARIABLE:
        return "VARIAVBLE";
    case TokenType::UNKNOWN:
        return "UNKNOWN";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //tokenizer test
    Lexer lex = Lexer();
    vector<Token> tokens = lex.tokenize("1,2");
    for (const Token &t : tokens) {
        cout << t.value;
        cout<<" - Precedence: ";
        cout<< t.precedence;
        cout<<" - TokenType: ";
        cout<<TokenTypeToString(t.type)<<endl;

    }
    //parser test
    Parser parser = Parser();
    vector<Token> parsedTokens = parser.parse(tokens);
    for (const Token &t : parsedTokens){
        cout<<t.value<<" ";
    }

    return a.exec();
}
