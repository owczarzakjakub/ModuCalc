#pragma once
#include "Token.h"
#include <vector>

class Parser
{
public:
    Parser();
    std::vector<Token> parse(std::vector<Token> tokens);
};

