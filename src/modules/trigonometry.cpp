#include "trigonometry.h"
#include <math.h>

Trigonometry::Trigonometry() {}

double Trigonometry::sin(double x){
    return std::sin(x);
}

double Trigonometry::cos(double x){
    return std::cos(x);
}

double Trigonometry::tan(double x){
    return std::tan(x);
}

double Trigonometry::ctg(double x){
    return 1/tan(x);
}

double Trigonometry::asin(double x){
    return std::asin(x);
}


double Trigonometry::acos(double x){
    return std::acos(x);
}

double Trigonometry::atan(double x){
    return std::atan(x);
}

