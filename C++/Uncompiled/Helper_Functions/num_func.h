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

// Returns the sign of a integer.
inline int sign(const int n) {
    if (n == 0) {
        return 0;
    }
    if (n > 0) {
        return 1;
    }
    if (n < 0) {
        return -1;
    }
    // Defaults to returning zero.
    return 0;
}

// Returns true if integer n is divisible by specified number
inline bool divisible_by(const int n, const int divisor) {
    if (n % divisor == 0) {
        return true;
    }
    return false;
}

// If integer n is evenly divisible by 10, return true
inline bool divisible_10(const int n) {
    if (n % 10 == 0) {
        return true;
    }
    return false;
}

// Returns greatest common divisor with specified starting point.
// EX: start=50 -> return value between (1-50)
inline int gcd(const int n, const int start=10) {
    for (int i = start; n % i != 0 && i > 0; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

// Returns greatest common divisor of a number (1-20).
inline int gcd_20(const int n) {
    for (int i = 20; n % i != 0 && i > 0; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

// Returns least common multiple with specified end point.
inline int lcm(const int n, const int end=10) {
    if (end == 0) {
        return 0;
    }
    if (n % 2 == 0) {
        return 2;
    }
    for (int i = 2; n % i != 0 && i <= end; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

// Returns Least common multiple betwen (1-20).
inline int lcm_20(const int n) {
    if (n % 2 == 0) {
        return 2;
    }
    for (int i = 2; n % i != 0 && i <= 20; i++) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

// Returns true if prime and false if not.
inline bool is_prime(const int n) {
    if (sign(n) == -1) {
        return false;
    }
    if (n == 0 || n == 1) {
        return false;
    }
    const int lcm_check = lcm(n, n);
    if (lcm_check > 1) {
        return false;
    }
    if (lcm_check == 1 || lcm_check == n) {
        return true;
    }
    return false;
}

// Returns a rounded floating point number to the specified decimal place.
//inline double round_dbl(const double n, int places) {

//}

//inline float round_flt()

// Returns the maximum value in a vector.
inline int vec_int_max(const std::vector<int> &range) {
    if (range.empty()) {
        return 0;
    }
    int max = range[0];
    for (int i = 1; i <= range.size()-1; i++) {
        if (range[i] > max) {
            max = range[i];
        }
    }
    return max;
}

// Returns the minimum value in a vector.
inline int vec_int_min(const std::vector<int> &range) {
    if (range.empty()) {
        return 0;
    }
    int min = range[0];
    for (int i = 1; i <= range.size()-1; i++) {
        if (range[i] < min) {
            min = range[i];
        }
    }
    return min;
}

// Returns the maximum value in a vector.
inline double vec_dbl_max(const std::vector<double> &range) {
    if (range.empty()) {
        return 0.0;
    }
    double max = range[0];
    for (int i = 1; i <= range.size()-1; i++) {
        if (range[i] > max) {
            max = range[i];
        }
    }
    return max;
}

// Returns the minimum value in a vector.
inline double vec_dbl_min(const std::vector<double> &range) {
    if (range.empty()) {
        return 0.0;
    }
    double min = range[0];
    for (int i = 1; i <= range.size()-1; i++) {
        if (range[i] < min) {
            min = range[i];
        }
    }
    return min;
}

// Returns clamped value to a range.
inline int clamp_int(const std::vector<int> &range, const int n) {
    if (range.empty()) {
        return 0;
    }
    const int min = vec_int_min(range);
    const int max = vec_int_max(range);
    if (n <= min) {
        return min;
    }
    if (n >= max) {
        return max;
    }
    if (n > min && n < max) {
        return n;
    }
    return 0;
}

// Returns clamped value to a range. If below minimum, return minimum. If above maximum, return maximum. Else returns value.
inline double clamp_dbl(const std::vector<double> &range, const double n) {
    if (range.empty()) {
        return 0.0;
    }
    const double min = vec_dbl_min(range);
    const double max = vec_dbl_max(range);
    if (n <= min) {
        return min;
    }
    if (n >= max) {
        return max;
    }
    if (n > min && n < max) {
        return n;
    }
    return 0.0;
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

// Returns square of int n.
inline int square(const int n) {
    return n * n;
}

// Returns cube of int n.
inline long long cube(const int n) {
    return n * n * n;
}

// Returns absolute value of a double.
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