#ifndef HELPERFUNCTIONS_NUM_FUNC_H
#define HELPERFUNCTIONS_NUM_FUNC_H
#include <iostream>
#include <string>
#include <vector>

// Checks if a positive integer is even. Returns bool.
inline bool is_even(const int n) {
    if (n > 1 && n % 2 == 0 || n == 0) {
        return true;
    }
    return false;
}

// Checks if a positive integer is odd. Returns bool.
inline bool is_odd(const int n) {
    if (n >= 1 && !is_even(n)) {
        return true;
    }
    return false;
}

// Returns the next even integer of a given integer.
inline int next_even(const int n) {
    if (is_even(n)) {
        return n + 2;
    }
    return n + 1;
}

// Returns the next odd integer of a given integer.
inline int next_odd(const int n) {
    if (is_odd(n)) {
        return n + 2;
    }
    return n + 1;
}

// Returns the previous even integer of a given integer.
inline int last_even(const int n) {
    if (is_even(n) && (n-2) > 0) {
        return n - 2;
    }
    if (is_even(n) && (n-2) <= 0) {
        return 0;
    }
    return n - 1;
}

// Returns the last odd integer of a given integer.
inline int last_odd(const int n) {
    if (is_odd(n) && (n-2) > 0) {
        return n - 2;
    }
    if (is_odd(n) && (n-2) <= 0) {
        return 0;
    }
    return n - 1;
}

// Returns the number of digits in an integer.
inline int count_digits_int(const int n) {
    const std::string n_string = std::to_string(n);
    return n_string.length();
}

// Returns the number of digits in a double.
inline int count_digits_dbl(const double n) {
    std::string n_string = std::to_string(n);
    n_string.erase(n_string.find('.'), 1);
    return n_string.length();
}

// Returns the number of digits in a float.
inline int count_digits_flt(const float n) {
    std::string n_string = std::to_string(n);
    n_string.erase(n_string.find('.'), 1);
    return n_string.length();
}

// Compares two values. Returns the greatest of the two. Accepts two double parameters and an optional default value.
// Returns double.
inline double greater(const double a, const double b, const double default_val = 0.0) {
    if (a > b) {
        return a;
    }
    if (a < b) {
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
    }
    if (n < 0.0) {
        return n * -1.0;
    }
    return 0.0;
}

// Divide a number by 100 to get its percentage representation. Returns type double.
inline double percent(const double a) {
    return a/100;
}

// Calculates percent change between two numbers. Accepts two doubles and returns double.
inline double percent_change(const double a, const double b) {
    // Cannot divide by zero.
    if (b == 0) {
        return 0.0;
    }
    return (a-b)/b * 100;
}

// Returns the inverse of a given integer.
inline int inverse(const int n) {
    // Cannot divide by zero.
    if (n == 0) {
        return 0;
    }
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

// Counts every number up to given int and returns a vector with that sequence.
inline std::vector<int> sequence(const int n) {
    std::vector<int> sequenced_ints;
    for (int i = 0; i < n; i++) {
        sequenced_ints.push_back(i + 1);
    }
    return sequenced_ints;
}

// Takes an integer, counts down from that integer until 0, exclusive. Returns a vector with those values as its elements.
inline std::vector<int> reverse_sequence(const int n) {
    std::vector<int> sequenced_ints;
    for (int i = n; i > 0; i--) {
        sequenced_ints.push_back(i);
    }
    return sequenced_ints;
}

#endif //HELPERFUNCTIONS_NUM_FUNC_H