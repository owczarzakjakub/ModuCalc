#ifndef VECTOR_H
#define VECTOR_H
#pragma once
#include <vector>

class Vector
{
public:
    Vector(const std::vector<double>& values);
    Vector add(const Vector& v) const;
    Vector sub(const Vector& v) const;

    double length() const;
    double dot(const Vector& v) const;

private:
    std::vector<double> data;
};

#endif // VECTOR_H
