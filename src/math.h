#ifndef CODX_MATH_H
#define CODX_MATH_H

#include <cstddef>

namespace cx {

template <typename T>
const T pow(const T base, std::size_t exp)
{
    if (exp == 0) {
        return T(1);
    } else if (exp & 1) {
        T y = pow(base, (exp - 1) >> 1);
        return base * y * y;
    } else {
        T y = pow(base, (exp >> 1));
        return y * y;
    }
}

}

#endif // MATH_H
