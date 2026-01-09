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
        else if(token.type==TokenType::FUNCTION){
            if(stack.empty()) throw std::logic_error("Brak argumentow do funkcji");
            SymbolicNumber a=stack.top();
            stack.pop();
            if(a.coefX!=0) throw std::logic_error("Nie wolno robić funkcji trygonometrycznej z niewiadomej");
            double v=a.constant;
            double res=0;
            if(token.value=="sin") res=trig.sin(v);
            else if(token.value=="cos") res=trig.cos(v);
            else if(token.value=="tan") res=trig.tan(v);
            else if(token.value=="ctg") res=trig.ctg(v);
            else if(token.value=="asin") res=trig.asin(v);
            else if(token.value=="acos") res=trig.acos(v);
            else if(token.value=="atan") res=trig.atan(v);
            else if(token.value=="sqrt") res=sqrt(v);
            else if(token.value=="log") res=log10(v);
            else throw std::logic_error("Nieznana funkcja");
            stack.push(SymbolicNumber(0,res));
            }
            else{
                throw std::logic_error("Nieobslugiwany token");
            }
    }
    if(stack.size()!=1) throw std::logic_error("Bledne wyrazenie");
    return stack.top();
}
