#pragma once
#include "evaluator.h"
#include <stack>
#include <cmath>
#include <stdexcept>

Evaluator::Evaluator() {}

Number Evaluator::evaluate(const std::vector<Token>& postfix){
    std::stack<Number> stack;

for(const Token& token : postfix){
    if(token.type==TokenType::NUMBER){
        stack.push(Number(std::stod(token.value)));
    }
    else if(token.type == TokenType::OPERATOR){
        if(stack.size()<2) throw std::logic_error("Za mało argumentów");
        Number b=stack.top(); stack.pop();
        Number a=stack.top(); stack.pop();

        if(token.value=="+") stack.push(a+b);
        else if(token.value=="-") stack.push(a-b);
        else if(token.value=="*") stack.push(a*b);
        else if(token.value=="/"){
            if(b.toDouble()==0) throw std::logic_error("Dzielenie przez zero");
            stack.push(a/b);
        }
        else if(token.value=="^") stack.push(Number(std::pow(a.toDouble(),b.toDouble())));
        else throw std::logic_error("Nieznany operator");
    }
    else if(token.type==TokenType::FUNCTION){
        if(stack.empty()) throw std::logic_error("Brak argumentu do funkcji");
        Number a =stack.top(); stack.pop();
        if(token.value=="sin") stack.push(Number(std::sin(a.toDouble())));
        else if(token.value=="cos") stack.push(Number(std::cos(a.toDouble())));
        else if(token.value=="sqrt") stack.push(Number(std::sqrt(a.toDouble())));
        else if(token.value=="log") stack.push(Number(std::log(a.toDouble())));
        else std::logic_error("Nieznana funkcja");
    }
    else{
        throw std::logic_error("Nieobsługiwany token");
    }
    if(stack.size()!=1) throw std::logic_error("Błędne wyrażenie");

    return stack.top();
}
}
