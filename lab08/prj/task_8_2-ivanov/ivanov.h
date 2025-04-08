#ifndef IVANOV_H_INCLUDED
#define IVANOV_H_INCLUDED

#include <cmath>

inline double s_calculation(int x, int y, int z) {
    return z * sin(x * x * y) + sqrt(fabs(z - 12 * x)) / pow(y, 3);
}

#endif // IVANOV_H_INCLUDED
