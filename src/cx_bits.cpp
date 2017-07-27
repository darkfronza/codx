#include "cx_bits.h"

#include <iostream>
#include <sstream>

namespace cx {

void dump_bits(const void *data, std::size_t size)
{
    unsigned char *p = ((unsigned char *)data) + (size - 1);

    std::stringstream ss;

    while (size) {
        unsigned char mask = 1u << 7;

        while (mask) {
            ss << ((*p & mask) ? '1': '0');
            mask >>= 1;
        }

        --size;
//        if (size != 0) {
//            ss << '.';
//        }

        p--;
    }

    std::cout << ss.str() << std::endl;
}

void sum_bits(unsigned char *out, unsigned char *src1, unsigned char *src2, std::size_t n)
{
    std::uint16_t carry = 0u, pcarry = 0u;

    for (int i = 0; i < n; i++) {
        carry = *src1++ + *src2++ + pcarry;
        *out++ = carry & 0xff;
        pcarry = (carry >> 8);
    }

    if (pcarry) {
        *out = 1;
    }
}

}
