
#ifndef CODX_BITS_H
#define CODX_BITS_H 1

#include <cstddef>

namespace cx {

void dump_bits(const void *data, std::size_t size);

void sum_bits(unsigned char *out, unsigned char *src1, unsigned char *src2, std::size_t n);

} /* end namespace cx */


#endif /* CODX_BITS_H */
