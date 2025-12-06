#include "parser.h"
#include <vector>
#include <stack>
#include "TokenType.h"

using std::vector;
using std::stack;

Parser::Parser() {}

vector<Token> Parser::parse(vector<Token> tokens){

    vector<Token> outputQueue;
    stack<Token> operatorStack;
    try{

        for(int i = 0; i < tokens.size(); i++){

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
                if(operatorStack.size() > 0){
                    while(operatorStack.size() > 0 && operatorStack.top().type != TokenType::LPAREN) {
                        outputQueue.push_back(operatorStack.top());
                        operatorStack.pop();
                    }
                    if(operatorStack.top().type != TokenType::LPAREN){
                        throw std::logic_error("Przecinek poza funkcją");
                    }
                }
                if(operatorStack.size() == 0){
                    throw std::logic_error("Przecinek poza funkcją");
                }
            }

            else if(currentToken.type == TokenType::OPERATOR){
                while(operatorStack.size()>0 &&
                       (operatorStack.top().precedence > currentToken.precedence ||
                        (operatorStack.top().precedence == currentToken.precedence &&
                            operatorStack.top().value != "^"))){
                    outputQueue.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                operatorStack.push(currentToken);
            }

            else if(currentToken.type == TokenType::LPAREN){
                operatorStack.push(currentToken);
            }

            else if(currentToken.type == TokenType::RPAREN){
                if(operatorStack.top().type == TokenType::LPAREN){
                    throw std::logic_error("Puste wyrażenie");
                }

                while(operatorStack.size() > 0 && operatorStack.top().type != TokenType::LPAREN){
                    outputQueue.push_back(operatorStack.top());
                    operatorStack.pop();
                }
                if(operatorStack.top().type != TokenType::LPAREN){
                    throw std::logic_error("Blędnie użyte nawiasy");
                }
                operatorStack.pop();
                if(operatorStack.size() > 0 && operatorStack.top().type == TokenType::FUNCTION){
                    outputQueue.push_back(operatorStack.top());
                    operatorStack.pop();
                }
            }

        }

        while(operatorStack.size() > 0){
            if(operatorStack.top().type == TokenType::LPAREN || operatorStack.top().type == TokenType::RPAREN){
                throw std::logic_error("Błędnie użyte nawiasy");
            }
            outputQueue.push_back(operatorStack.top());
            operatorStack.pop();
        }

        return outputQueue;

    }catch(std::logic_error&e){
        std::cout<<"Bląd logiczny: " << e.what()<<std::endl;
        return{};
    }
    catch(...){
        std::cout<<"Nieznany wyjątek"<<std::endl;
        return{};
    }



}
