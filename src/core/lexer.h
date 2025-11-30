#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <string>
#include <vector>
#pragma once

class Lexer
{
public:
    Lexer();
    std::vector<Token> tokenize(std::string input);
};

#endif
