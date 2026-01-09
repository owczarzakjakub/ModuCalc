#pragma once
#include <cmath>
class Trigonometry
{
public:
    Trigonometry();
    double sin(double x);
    double cos(double x);
    double tan(double x);
    double ctg(double x);
    double asin(double x);
    double acos(double x);
    double atan(double x);

private:
    constexpr static double PI=3.14159265358979323846;
    double toRad(double deg){ return deg * PI / 180.0; }
    double toDeg(double rad){ return rad * 180.0 / PI; }
};
