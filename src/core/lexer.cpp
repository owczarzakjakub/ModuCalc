#include "lexer.h"
#include <string>
#include <iostream>
#include <cctype>
#include <unordered_set>

using std::string;
using std::vector;
using std::isdigit;

Lexer::Lexer() {

}
vector<Token> Lexer::tokenize(string input){
    vector<Token> tokens;
    for(int i = 0; i < input.length();i++){
        TokenType type = TokenType::UNKNOWN;
        string value;
        int precedence = 0;
        char currentCharacter = input[i];
        value = currentCharacter;

        if(std::isspace(currentCharacter)){
            continue;
        }


        if(isdigit(currentCharacter) || currentCharacter == '.'){
            int j = i;
            string number;
            bool dotSeen = false;
            while(j < input.length() && (isdigit(input[j]) || input[j] == '.')){
                if(input[j] == '.'){
                    if(dotSeen) break;
                    dotSeen = true;
                }
                number += input[j];
                j++;
            }
            type = TokenType::NUMBER;
            value = string("") + currentCharacter;
            precedence = 0;
            i = j - 1;
        }


        else if(std::isalpha(input[i])){
            std::unordered_set<string> functions = {
                "sin", "cos", "tg", "ctg", "asin", "acos", "atan", "actg", "log", "sqrt"
            };
            string functionName;
            int j = i;
            while(j < input.length() && isalpha(input[j])){
                functionName += input[j];
                j++;
            }
            i = j - 1;
            if(functions.find(functionName) != functions.end()){
                type = TokenType::FUNCTION;
                value = functionName;
            }
            else{
                type = TokenType::VARIABLE; //rozwazyc czy zmienne moga zawierac liczby
                value = functionName;
            }
        }

        else if(currentCharacter == '('){
            type = TokenType::LPAREN;
            value = "(";
        }
        else if(currentCharacter == ')'){
            type = TokenType::RPAREN;
            value = ")";
        }

        else if(currentCharacter == ','){
            type = TokenType::COMMA;
            value = ",";
        }



        switch(currentCharacter){
        case '+':
            type = TokenType::OPERATOR;
            value = string("") + currentCharacter;
            precedence = 1;
            break;
        case '-':
            type = TokenType::OPERATOR;
            value = string("") + currentCharacter;
            precedence = 1;
            break;
        case '*':
            type = TokenType::OPERATOR;
            value = string("") + currentCharacter;
            precedence = 2;
            break;
        case '/':
            type = TokenType::OPERATOR;
            value = string("") + currentCharacter;
            precedence = 2;
            break;
        case '^':
            type = TokenType::OPERATOR;
            value = string("") + currentCharacter;
            precedence = 3;
            break;
        default:
            // type = TokenType::UNKNOWN;
            // value = string("") + currentCharacter;
            break;
        }



        Token token(type, value, precedence);
        tokens.push_back(token);
    }
    return tokens;
}

