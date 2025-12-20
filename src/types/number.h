#pragma once
#include <string>

using std::string;

class Number
{
public:
    Number(double v = 0.0);
    double toDouble() const;
    std::string toString() const;
    double getValue() const;

    Number operator+(const Number& other)const;
    Number operator-(const Number& other) const;
    Number operator*(const Number& other) const;
    Number operator/(const Number& other) const;
    bool operator==(const Number& other) const;

private:
    double value;
};

