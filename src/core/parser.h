#pragma once
#include "token.h"
#include <vector>

class Parser
{
public:
    Parser();
    std::vector<Token> parse(std::vector<Token> tokens);
};

