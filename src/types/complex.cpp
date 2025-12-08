#include "complex.h"
#include <cmath>
#include <iostream>

using std::pow;

Complex::Complex(double r, double i):real(r), imag(i) {

}

Complex Complex::add(const Complex& c) const{
    double newReal = real + c.real;
    double newImag = imag + c.imag;

    return Complex(newReal, newImag);
}

Complex Complex::sub(const Complex& c) const{
    double newReal = real - c.real;
    double newImag = imag - c.imag;

    return Complex(newReal, newImag);
}

Complex Complex::multi(const Complex& c) const{
    double newReal = real * c.real - imag * c.imag;
    double newImag = real * c.imag + c.real * imag;

    return Complex(newReal, newImag);
}

Complex Complex::div(const Complex& c) const{
    double divider = pow(c.real, 2) + pow(c.imag, 2);
    if(divider == 0){
        throw std::runtime_error("Dzielenie przez zero.");
    }
    double newReal = (real * c.real + imag + c.imag) / divider;
    double newImag = (imag * c.real - real * c.imag) / divider;

    return Complex(newReal, newImag);
}

double Complex::magnitude() const{
    return std::sqrt(pow(real, 2) + pow(imag, 2));
}

double Complex::angle() const{
    return std::atan2(imag, real);
}

Complex Complex::conjugate() const{
    return Complex(real, -imag);
}
