#include "QuadraticEquation.h"

#include <vector>
#include <cmath>

std::vector<double> QuadraticEquation::solve(double a, double b, double c)
{
    if (FP_ZERO == std::fpclassify(b))
    {
        double tmp = 0 - c/a;

        if (tmp < 0)
        {
            return {};
        }
        else
        {
            auto x = sqrtf(tmp);
            return {x, -x};
        }
    }

    auto d = pow(b, 2) - 4*a*c;
    if (FP_ZERO == std::fpclassify(d))
    {
        double x = - b / (2 * a);
        return {x, x};
    }

    return {0, 0};
}
