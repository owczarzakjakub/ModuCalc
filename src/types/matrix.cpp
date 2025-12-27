#include "matrix.h"
#include <stdexcept>


Matrix::Matrix(int r,int c):rows(r), cols(c) {
    data.resize(r,std::vector<double>(c,0.0));
}


Matrix::Matrix(const std::vector<std::vector<double>>& d) {
    rows=d.size();
    cols=d[0].size();
    data=d;
}

int Matrix::getRows() const{return rows;}
int Matrix::getCols() const{return cols;}

Matrix Matrix::add(const Matrix& m) const{
    if(rows!=m.rows || cols!=m.cols) throw std::logic_error("Zły rozmiar macierzy");
    Matrix result(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result.data[i][j]=data[i][j]+m.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::sub(const Matrix& m) const{
    if(rows!=m.rows || cols!=m.cols) throw std::logic_error("Zły rozmiar macierzy");
    Matrix result(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            result.data[i][j]=data[i][j]-m.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::multi(const Matrix& m) const{
    if(rows!=m.rows || cols!=m.cols) throw std::logic_error("Zły rozmiar macierzy");
    Matrix result(rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            for(int k=0;k<cols;k++){
                result.data[i][j]=data[i][k]*m.data[k][j];
            }
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
    return data[r];
}
std::vector<double> Matrix::col(int c) const{
    std::vector<double> result(rows);
    for(int i=0;i<rows;i++){
        result[i]=data[i][c];
    }
    return result;
}
