/**
 * cx_sort.h
 *
 * Common sorting algorithms
 */

#ifndef CODX_SORT_H
#define CODX_SORT_H 1

#include <cstddef>
#include <functional>


namespace cx {

template <typename T, typename Comparison = std::less<T>>
void insertion_sort(T array[], std::size_t n, Comparison c = Comparison())
{
    for (std::size_t j = 2; j < n; ++j) {
        T key = array[j];
        int i = j - 1;

        while (i >= 0 && c(key, array[i])) {
            array[i+1] = array[i];
            --i;
        }

        array[i+1] = key;
    }
}

template <typename T>
int linear_search(const T array[], std::size_t n, const T value)
{
    for (int i = 0; i < n; ++i) {
        if (array[i] == value) {
            return i;
        }
    }

    return -1;
}

} /* end namespace cx */


#endif /* CODX_SORT_H */
