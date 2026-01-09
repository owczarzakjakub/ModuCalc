#pragma once
#include <vector>
#include "vector.h"
class Matrix{
public:
    Matrix(int rows,int cols);
    Matrix(const std::vector<std::vector<double>>& data);

    int getRows() const;
    int getCols() const;
    double get(int r, int c) const;
    void set(int r, int c, double value);



    Matrix add(const Matrix& m) const;
    Matrix sub(const Matrix& m) const;
    Matrix multi(const Matrix& m) const;

    Matrix transpose() const;
    std::vector<double> row(int r) const;
    std::vector<double> col(int c) const;


private:
    std::vector<std::vector<double>> data;
    int rows;
    int cols;
};
