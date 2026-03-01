#pragma once


class Complex
{
public:
    int size() const { return 2; }
    double get(int i) const {
        if (i == 0) return real;
        if (i == 1) return imag;
        return 0;
    }
    Complex(double r, double i);
    double getReal() const { return real; }
    double getImag() const { return imag; }
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

