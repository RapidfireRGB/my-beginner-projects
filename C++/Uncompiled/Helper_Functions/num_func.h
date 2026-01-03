#ifndef HELPERFUNCTIONS_NUM_FUNC_H
#define HELPERFUNCTIONS_NUM_FUNC_H
#include <iostream>
#include <string>
#include <vector>

// Checks if a positive integer is even. Returns bool.
inline bool iseven(const int n) {
    if (n > 1 && n % 2 == 0 || n == 0) {
        return true;
    }
    return false;
}

// Checks if a positive integer is odd. Returns bool.
inline bool isodd(const int n) {
    if (n >= 1 && !iseven(n)) {
        return true;
    }
    return false;
}

// Fetches the number of digits in an integer. Returns int.
inline int count_digits(const int n) {
    const std::string n_string = std::to_string(n);
    return n_string.length();
}

// Compares two values. Returns the greatest of the two. Accepts two double parameters and an optional default value.
// Returns double.
inline double greater(const double a, const double b, const double default_val = 0.0) {
    if (a > b) {
        return a;
    } else if (a < b) {
        return b;
    }
    return default_val;
}

// Sums contents of a vector of type double. Returns double.
inline double sum(const std::vector<double> &range) {
    double sum = 0.0;
    for (const double x : range) {
        sum += x;
    }
    return sum;
}

// Averages contents of a vector of type double. Returns double.
inline double mean(const std::vector<double> &range) {
    double const mean = sum(range) / range.size();
    if (range.empty()) {
        return 0.0;
    }
    return mean;
}

// Custom power function. Accepts two integers (base, exponent). Returns type long long.
inline long long power(const int a, const int b) {
    long long result = 1;
    for (int i = 1; i <= b; i++) {
        result *= a;
    }
    return result;
}

inline int square(const int n) {
    return n * n;
}

inline long long cube(const int n) {
    return n * n * n;
}

// Custom absolute value function. Returns type double.
inline double absval(const double n) {
    if (n >= 0.0) {
        return n;
    } else if (n < 0.0) {
        return n * -1.0;
    } else {
        return 0.0;
    }
}

// Divide a number by 100 to get its percentage representation. Returns type double.
inline double percent(const double a) {
    return a/100;
}

// Calculates percent change between two numbers. Accepts two doubles and returns double.
inline double percent_change(const double a, const double b) {
    if (b == 0) {
        return 0.0;
    }
    return (a-b)/b * 100;
}

// Returns the inverse of a given integer.
inline int inverse(const int n) {
    return 1/n;
}

// Calculates factorial of int n. Returns type long long.
inline long long factorial(const int n) {
    long long result = 1;
    if (n < 0) {
        return 0;
    }
    for (int i = n; i > 0; i--) {
        result *= i;
    }
    return result;
}
#endif //HELPERFUNCTIONS_NUM_FUNC_H