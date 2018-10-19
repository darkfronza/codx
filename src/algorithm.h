/**
 * algorithm.h
 *
 * Collection of useful algorithms.
 *
 * Author: Diego Fronza
 * darkfronza@gmail.com
 */

#ifndef CODX_ALGORITHM_H
#define CODX_ALGORITHM_H 1


#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

namespace cx {

/**
 * Computer prefix averages in range [first,last) and store results in out iterator.
 */
template <typename InputIt, typename OutputIt>
void prefix_averages(InputIt first, InputIt last, OutputIt out)
{
    typedef typename std::iterator_traits<InputIt>::value_type T;
    T curr_sum = 0;
    std::size_t i = 1;

    while (first != last) {
        curr_sum += *first;
        *out = static_cast<T>(curr_sum / i);

        ++first;
        ++i;
        ++out;
    }
}

/**
 * Twin strings algorithm.
 */
vector<string> twins(const vector<string>& a, const vector<string>& b) {
    vector<string> res;

    std::size_t min_index = a.size() < b.size() ? a.size() : b.size(); // container with less elements
    std::size_t max_index = a.size() > b.size() ? a.size() : b.size(); // container with more elements
    std::size_t i = 0;

    for (; i < min_index; ++i) { // iterate over common container lengths
        if (a[i].length() != b[i].length()) { // strings have different length, not twins
            res.push_back("No");
        } else if (a[i] == b[i]) { // are already equal
            res.push_back("Yes");
        } else {
            std::string a_even, a_odd, b_even, b_odd;
            // create a string with only even chars from a[i]
            for (int k = 0; k < a[i].length(); k += 2) {
                a_even += a[i][k];
            }

            // create a string with only odd chars from a[i]
            for (int k = 1; k < a[i].length(); k += 2) {
                a_odd += a[i][k];
            }

            // create a string with only even chars from b[i]
            for (int k = 0; k < b[i].length(); k += 2) {
                b_even += b[i][k];
            }

            // create a string with only odd chars from b[i]
            for (int k = 1; k < b[i].length(); k += 2) {
                b_odd += b[i][k];
            }

            // sort all strings
            std::sort(a_even.begin(), a_even.end());
            std::sort(a_odd.begin(), a_odd.end());
            std::sort(b_even.begin(), b_even.end());
            std::sort(b_odd.begin(), b_odd.end());

            if ((a_even == b_even) && (a_odd == b_odd)) {
                res.push_back("Yes");
            } else {
                res.push_back("No");
            }
        }
    }

    for (; i < max_index; ++i) { // some container exceeds the other in size, so all remaining items are not Twins
        res.push_back("No");
    }

    return res;
}

}
#endif
