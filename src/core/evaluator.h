#pragma once
#include <vector>
#include <stack>
#include "token.h"
#include "../types/number.h"
class Evaluator
{
public:
    Evaluator();
    Number evaluate(const std::vector<Token>& postifix);
};

