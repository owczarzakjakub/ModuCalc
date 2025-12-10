#include "statistics.h"
#include <algorithm>
#include <math.h>

Statistics::Statistics() {}

double Statistics::mean(const vector<double>& nums){
    int quantity = nums.size();
    double sum = 0;
    for(const double number : nums){
        sum += number;
    }
    return sum/quantity;
}

double Statistics::median(const vector<double> nums){
    vector<double> numsCopy = nums;
    std::sort(numsCopy.begin(), numsCopy.end());
    double result;
    if(nums.size() % 2 == 0){
        result = (numsCopy[numsCopy.size()/2] + numsCopy[numsCopy.size()/2 - 1])/2;
    }
    else{
        result = std::floor(numsCopy[numsCopy.size()/2]);
    }

    return result;
}

double Statistics::variance(const vector<double>& nums){
    double varMean = mean(nums);
    double sum = 0;
    for(const double number : nums){
        sum += pow(number-varMean, 2);
    }
    return sum/nums.size();
}

double Statistics::standard(const vector<double>& nums){
    return sqrt(variance(nums));
}
