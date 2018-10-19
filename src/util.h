#ifndef CODX_UTIL_H
#define CODX_UTIL_H 1

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

namespace cx {

template <typename Container>
void dump_container(const Container &cont, const std::string &sep=" ", std::ostream &os=std::cout)
{
    auto endp = std::end(cont);
    auto start = std::begin(cont);

    while (start != endp) {
        os << *start;

        if (++start != endp) {
            os << sep;
        }
    }

    os << std::endl;
}

/* String utilities */
namespace str {

    /* trim leading and ending chars from string str*/
    std::string trim(const std::string &str, const std::string &chars=" ")
    {
        if (auto start = str.find_first_not_of(chars); start != std::string::npos) {
            auto end = str.find_last_not_of(chars);

            return str.substr(start, end - start + 1);
        } else {
            return std::string{};
        }
    }

    std::string trim_left(const std::string &str, const std::string &chars=" ")
    {
        if (auto start = str.find_first_not_of(chars); start != std::string::npos) {
            return str.substr(start);
        } else {
            return std::string{};
        }
    }

    std::string trim_right(const std::string &str, const std::string &chars=" ")
    {
        if (auto endp = str.find_last_not_of(chars); endp != std::string::npos) {
            return str.substr(0, endp + 1);
        } else {
            return std::string{};
        }
    }

    void remove_all(std::string &str, const std::string &chars)
    {
        auto p = std::remove_if(begin(str), end(str), [&chars](const char c)
        {
            return chars.find(c) != std::string::npos;
        });

        str.erase(p, std::end(str));
    }

} // end namespace cx::str

namespace vec {

    template <typename T>
    void remove(std::vector<T> &v, const T &value)
    {
        v.erase(std::remove(std::begin(v), std::end(v), value));
    }

    template <typename T>
    void remove_all(std::vector<T> &v, const T &value)
    {
        v.erase(std::remove(begin(v), end(v), value), std::end(v));
    }

    template <typename T, typename Pred>
    void remove_all_if(std::vector<T> &v, Pred p)
    {
        v.erase(std::remove_if(begin(v), end(v), p), std::end(v));
    }
}


} // end namespace cx


#endif /* CODX_UTIL_H */
