#include "token.h"

Token::Token(TokenType type, std::string& value, int precedence):type(type), value(value), precedence(precedence){};

