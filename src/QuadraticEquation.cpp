#include "QuadraticEquation.h"

#include <vector>
#include <cmath>

std::vector<double> QuadraticEquation::solve(double a, double b, double c)
{
    if (FP_ZERO == std::fpclassify(b))
    {
        if ((0 - c/a) < 0)
        {
            return {};
        }
    }
    return {0, 0};
}
