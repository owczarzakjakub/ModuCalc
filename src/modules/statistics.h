#pragma once
#include <vector>

using std::vector;

class Statistics
{
public:
    Statistics();
    double mean(const vector<double>& nums);
    double median(const vector<double> nums);
    double variance (const vector<double>& nums);
    double standard (const vector<double>& nums);
};

