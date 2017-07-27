#ifndef CODX_UTIL_H
#define CODX_UTIL_H

#include <string>
#include <iostream>

namespace cx {

template <typename Container>
void dump_values(const Container& c, const std::string& sep = " ")
{
    auto end = cend(c);
    --end;

    for (auto ci = cbegin(c); ci != cend(c); ++ci) {
        std::cout << *ci;

        if (ci != end) {
            std::cout << sep;
        }
    }

    std::cout << std::endl;
}

template <typename T>
void dump_array(const T array[], std::size_t size, const std::string& sep = " ")
{
    for (std::size_t i = 0; i < size; i++) {
        std::cout << array[i];

        if (i < (size-1)) {
            std::cout << sep;
        }
    }

    std::cout << std::endl;
}

}

#endif /* CODX_UTIL_H */
