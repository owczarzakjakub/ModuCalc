#include "matrix.h"
#include <stdexcept>
#include <vector>

Matrix::Matrix(int r,int c):rows(r), cols(c) {
    data.resize(r,std::vector<double>(c,0.0));
}

Matrix::Matrix(const std::vector<std::vector<double>>& d) {
    rows=d.size();
    if (rows > 0)
        cols=d[0].size();
    else
        cols = 0;
    data=d;
}

int Matrix::getRows() const{return rows;}
int Matrix::getCols() const{return cols;}

Matrix Matrix::add(const Matrix& m) const{
    if(rows!=m.rows || cols!=m.cols) throw std::logic_error("Zły rozmiar macierzy do dodawania");
    Matrix result(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result.data[i][j]=data[i][j]+m.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::sub(const Matrix& m) const{
    if(rows!=m.rows || cols!=m.cols) throw std::logic_error("Zły rozmiar macierzy do odejmowania");
    Matrix result(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result.data[i][j]=data[i][j]-m.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::multi(const Matrix& m) const{

    if(cols != m.rows) throw std::logic_error("Zły rozmiar macierzy do mnożenia");

    Matrix result(rows, m.cols);


    for(int i=0; i<rows; i++){
        for(int j=0; j<m.cols; j++){
            double sum = 0.0;
            for(int k=0; k<cols; k++){
                sum += data[i][k] * m.data[k][j];
            }
            result.data[i][j] = sum;
        }
    }
    return result;
}

Matrix Matrix::transpose() const{
    Matrix result(cols,rows);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result.data[j][i]=data[i][j];
        }
    }
    return result;
}

std::vector<double> Matrix::row(int r) const{
    if (r >= 0 && r < rows) return data[r];
    return {};
}

std::vector<double> Matrix::col(int c) const{
    std::vector<double> result;
    if (c >= 0 && c < cols) {
        result.resize(rows);
        for(int i=0;i<rows;i++){
            result[i]=data[i][c];
        }
    }
    return result;
}

double Matrix::get(int r, int c) const
{
    if (r >= 0 && r < rows && c >= 0 && c < cols)
        return data[r][c];
    return 0.0;
}

void Matrix::set(int r, int c, double value)
{
    if (r >= 0 && r < rows && c >= 0 && c < cols)
        data[r][c] = value;
}
