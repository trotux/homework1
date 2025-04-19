#include "QuadraticEquation.h"

#include <vector>
#include <cmath>
#include <stdexcept>

std::vector<double> QuadraticEquation::solve(double a, double b, double c)
{
    if (FP_NAN == std::fpclassify(a) ||
        FP_INFINITE == std::fpclassify(a) ||
        FP_NAN == std::fpclassify(b) ||
        FP_INFINITE == std::fpclassify(b) ||
        FP_NAN == std::fpclassify(c) ||
        FP_INFINITE == std::fpclassify(c))
    {
         throw std::runtime_error("bad values");
    }

    double epsilon = 0.001;
    if (FP_ZERO == std::fpclassify(a))
    {
         throw std::runtime_error("\"a\" should no be equal zero");
    }

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

    if ((d - 0) < epsilon)
    {
        double x = - b / (2 * a);
        return {x, x};
    }

    return {0, 0};
}
