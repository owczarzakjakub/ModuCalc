#include "solver.h"
#include <stack>
#include <stdexcept>
#include <cmath>
#include <iostream>
Solver::Solver() {}
SymbolicNumber Solver::solve(const std::vector<Token>& postfix){
    std::stack<SymbolicNumber> stack;
    for(const Token& token : postfix){
        if(token.type==TokenType::NUMBER){
            stack.push(SymbolicNumber(0,std::stod(token.value)));
        }
        else if(token.type==TokenType::VARIABLE){
            stack.push(SymbolicNumber(1,0));
        }
        else if(token.type==TokenType::OPERATOR){
            if(stack.size()<2) throw std::logic_error("Za mało argumentów");
            SymbolicNumber b=stack.top(); stack.pop();
            SymbolicNumber a=stack.top(); stack.pop();
            SymbolicNumber result;
            if(token.value=="+"){
                result.coefX=a.coefX+b.coefX;
                result.constant=a.constant+b.constant;
            }
            else if(token.value=="-"){
                result.coefX=a.coefX-b.coefX;
                result.constant=a.constant-b.constant;
            }
            else if(token.value=="*"){
                if((a.coefX != 0 && b.coefX != 0)) throw std::logic_error("Maksymalny stopien równania : 1");
                result.coefX = a.coefX * b.constant + a.constant * b.coefX;
                result.constant = a.constant * b.constant;
            }
            else if(token.value == "/") {
                if(b.coefX != 0) throw std::logic_error("Dzielenie przez niewiadomą");
                result.coefX = a.coefX / b.constant;
                result.constant = a.constant / b.constant;
            }
            else throw std::logic_error("Nieznany operator");
            stack.push(result);
            }
            else{
                throw std::logic_error("Nieobługiwany token");
            }
    }
    if(stack.size()!=1) throw std::logic_error("Błędne wyrażenie");
    return stack.top();
}
