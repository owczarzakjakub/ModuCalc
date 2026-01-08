#ifndef SOLVER_H
#define SOLVER_H
#include <vector>
#include "token.h"
#include "../modules/trigonometry.h"
#include "../types/number.h"
struct SymbolicNumber{
    double coefX;
    double constant;
    SymbolicNumber(double c=0,double k=0):coefX(c),constant(k){}
};

class Solver
{
public:
    Solver();
    SymbolicNumber solve(const std::vector<Token>& postfix);
private:
    Trigonometry trig;
};

#endif // SOLVER_H
