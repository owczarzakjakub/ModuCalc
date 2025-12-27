#include "vector.h"
#include <cmath>
#include <stdexcept>

Vector::Vector(const std::vector<double>& values):data(values){

}
Vector Vector::add(const Vector& v) const {
    if (data.size() != v.data.size()) throw std::logic_error("Zły rozmiar wektorów");
    std::vector<double> result;
    for (int i = 0; i < data.size(); i++) {
        result.push_back(data[i] + v.data[i]);
    }

    return Vector(result);
}

Vector Vector::sub(const Vector& v) const {
    if (data.size() != v.data.size()) throw std::logic_error("Zły rozmiar wektorów");

    std::vector<double> result;
    for (int i = 0; i < data.size(); i++) {
        result.push_back(data[i] - v.data[i]);
    }

    return Vector(result);
}

double Vector::length() const{
    double sum=0;
    for(double x : data){
        sum+=x*x;
    }
    return sqrt(sum);
}

double Vector::dot(const Vector& v) const{
    if(data.size()!=v.data.size()) throw std::logic_error("ZŁy rozmiar wektorów");
    double sum=0;
    for(int i=0;i<data.size();i++){
        sum+=data[i]*v.data[i];
    }
    return sum;
}
