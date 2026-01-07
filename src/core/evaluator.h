#pragma once
#include <vector>
#include "token.h"
#include "../modules/trigonometry.h"
#include "../types/number.h"
class Evaluator
{
public:
    Evaluator();
    Number evaluate(const std::vector<Token>& postifix);
    double EquationWithOneVariable(const std::vector<Token>& tokens,const std::string& variableName="x");
private:
    Trigonometry trig;
};
