#include "parser.h"
#include <vector>
#include <stack>
#include "TokenType.h"

using std::vector;
using std::stack;

Parser::Parser() {}

//poprawic ewentualne bledy
vector<Token> Parser::parse(vector<Token> tokens){

    vector<Token> outputQueue;
    stack<Token> operatorStack;

    for(int i = 0; i < tokens.size(); i++){
        \
        Token currentToken = tokens[i];

        if(currentToken.type == TokenType::NUMBER){
            outputQueue.push_back(currentToken);
        }

        else if(currentToken.type ==TokenType::VARIABLE){
            outputQueue.push_back(currentToken);
        }

        else if(currentToken.type == TokenType::FUNCTION){
            operatorStack.push(currentToken);
        }

        else if(currentToken.type == TokenType::COMMA){
            Token currentOperatorStackToken = operatorStack.top();
            while(currentOperatorStackToken.type != TokenType::LPAREN){
                if(currentOperatorStackToken.type == TokenType::OPERATOR){
                    outputQueue.push_back(currentOperatorStackToken);
                    operatorStack.pop();
                    currentOperatorStackToken = operatorStack.top();
                }
            }
        }

        else if(currentToken.type == TokenType::OPERATOR){
            if(operatorStack.size() > 0){
                Token currentOperatorStackToken = operatorStack.top();
                //dokonczyc
            }
        }

        else if(currentToken.type == TokenType::LPAREN){
            operatorStack.push(currentToken);
        }

        else if(currentToken.type == TokenType::RPAREN){
            Token currentOperatorStackToken = operatorStack.top();
            while(currentOperatorStackToken.type != TokenType::LPAREN){
                outputQueue.push_back(currentOperatorStackToken);
                operatorStack.pop();
                currentOperatorStackToken = operatorStack.top();
            }
            operatorStack.pop();


            if(operatorStack.size() > 0 && currentOperatorStackToken.type == TokenType::FUNCTION){
                outputQueue.push_back(operatorStack.top());
                operatorStack.pop();
            }
        }
    }

    while(operatorStack.size() > 0){
        Token currentOperatorStackToken = operatorStack.top();
        outputQueue.push_back(currentOperatorStackToken);
        operatorStack.pop();
        currentOperatorStackToken = operatorStack.top();
    }

    return outputQueue;

}
