#include "TokenType.h"
#include <iostream>
#pragma once

class Token
{
public:
    Token(TokenType type, std::string& value, int precedence = 0);
    TokenType type;
    std::string value;
    int precedence = 0;
};
