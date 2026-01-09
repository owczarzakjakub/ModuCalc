#include "trigonometry.h"

Trigonometry::Trigonometry() {}

double Trigonometry::sin(double x){ return std::sin(toRad(x)); }
double Trigonometry::cos(double x){ return std::cos(toRad(x)); }
double Trigonometry::tan(double x){ return std::tan(toRad(x)); }
double Trigonometry::ctg(double x){ return 1.0 / std::tan(toRad(x)); }

double Trigonometry::asin(double x){ return toDeg(std::asin(x)); }
double Trigonometry::acos(double x){ return toDeg(std::acos(x)); }
double Trigonometry::atan(double x){ return toDeg(std::atan(x)); }


