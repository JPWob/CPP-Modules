#include "PmergeMe.hpp"


bool parse_positive_int(const char* str, unsigned int& out) {
    if (!str || *str == '\0') {
        return false; // empty string
    }

    unsigned int val = 0;
    for (const char* p = str; *p != '\0'; ++p) {
        if (*p < '0' || *p > '9') {
            return false; // rejects '-', '+', spaces, letters
        }
        unsigned int digit = static_cast<unsigned int>(*p - '0');
        if (val > (std::numeric_limits<int>::max() - digit) / 10) { // use UINT_MAX if you want full unsigned int range
            return false; // overflow
        }
        val = val * 10 + digit;
    }

    out = val;
    return true;
}

double get_time_us() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<double>(tv.tv_sec) * 1000000.0 + static_cast<double>(tv.tv_usec);
}
