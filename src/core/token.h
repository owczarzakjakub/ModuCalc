#pragma once
#include "TokenType.h"
#include <string>
#include "../modules/trigonometry.h"
#include <iostream>


class Token
{
public:
    Token(TokenType type, std::string& value, int precedence = 0);
    TokenType type;
    std::string value;
    int precedence = 0;
private:
    Trigonometry trig;
};
