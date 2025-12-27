#include "number.h"
#include <iostream>
#include <string>

using std::string;

Number::Number(double v):value(v){};
double Number::toDouble() const{
    return value;
}
double Number::getValue() const {
    return value;
}

Number Number::operator+(const Number& other) const {
    return value + other.value;
}

Number Number::operator-(const Number& other) const{
    return value - other.value;
}

Number Number::operator*(const Number& other) const{
    return value * other.value;
}

Number Number::operator/(const Number& other) const{
    if(other.value == 0){
        throw std::runtime_error("Dzielenie przez zero");
    }
    return value/other.value;
}

bool Number::operator==(const Number& other) const{
    if(value == other.value){
        return true;
    }
    else{
        return false;
    }
}

string Number::toString() const{
    return std::to_string(value);
}




