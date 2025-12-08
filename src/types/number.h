#pragma once
#include <string>

using std::string;

class Number
{
public:
    Number(double v = 0.0);
    double getValue() const;
    double add(const Number& other)const;
    double sub(const Number& other) const;
    double multi(const Number& other) const;
    double div(const Number& other) const;
    bool equal(const Number& other) const;
    string toString() const;
private:
    double value;
};

