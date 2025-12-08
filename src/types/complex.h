#pragma once


class Complex
{
public:
    Complex(double r, double i);
    Complex add(const Complex& c) const;
    Complex sub(const Complex& c) const;
    Complex multi(const Complex& c) const;
    Complex div(const Complex& c) const;
    double magnitude() const;
    double angle() const;
    Complex conjugate() const;
private:
    double real;
    double imag;
};

