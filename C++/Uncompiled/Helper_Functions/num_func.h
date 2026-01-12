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

// Returns the sign of a number.
template <typename T>
int sign(const T n) {
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

// Returns true if number n is divisible by specified number
template <typename T>
bool divisible_by(const T n, const int divisor) {
    if (n % divisor == 0) {
        return true;
    }
    return false;
}

// If number n is evenly divisible by 10, return true
template <typename T>
bool divisible_10(const T n) {
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

// Returns the maximum value in a subscripatable container.
template <typename T>
int maximum(const T &container) {
    if (container.empty()) {
        return 0;
    }
    int max = container[0];
    for (int i = 1; i <= container.size()-1; i++) {
        if (container[i] > max) {
            max = container[i];
        }
    }
    return max;
}

// Returns the minimum value in a subscritptable container.
template <typename T>
int minimum(const T &container) {
    if (container.empty()) {
        return 0;
    }
    int min = container[0];
    for (int i = 1; i <= container.size()-1; i++) {
        if (container[i] < min) {
            min = container[i];
        }
    }
    return min;
}

// Returns clamped value to a range.
template <typename T, typename N>
N clamp_int(const T &container, const N n) {
    if (container.empty()) {
        return 0;
    }
    const N min = minimum(container);
    const N max = maximum(container);
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

// Returns the number of digits in an integer.
inline int count_digits_int(const int n) {
    const std::string n_string = std::to_string(n);
    return n_string.length();
}

// Returns the number of digits in a floating point number.
template <typename F>
int count_digits_flt(const F n) {
    std::string n_string = std::to_string(n);
    n_string.erase(n_string.find('.'), 1);
    return n_string.length();
}

// Compares two values. Returns the greatest of the two. Accepts two numerical parameters and an optional default value.
template <typename T>
T greater(const T a, const T b, const T default_val = 0) {
    if (a > b) {
        return a;
    }
    if (a < b) {
        return b;
    }
    return default_val;
}

// Sums contents of a container of numerical values.
template <typename T, typename N>
N sum(const T &container) {
    N sum = 0;
    for (const N element : container) {
        sum += element;
    }
    return sum;
}

// Averages contents of a container of numerical values.
template <typename T, typename N>
N mean(const T &container) {
    const N mean = sum(container) / container.size();
    if (container.empty()) {
        return 0;
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

// Returns square of n.
template <typename T>
T square(const T n) {
    return n * n;
}

// Returns cube of n.
template <typename T>
T cube(const T n) {
    return n * n * n;
}

// Returns absolute value of n.
template <typename T>
double absval(const T n) {
    if (n >= 0.0) {
        return n;
    }
    if (n < 0.0) {
        return n * -1.0;
    }
    return 0;
}

// Divide a number by 100 to get its percentage representation. Returns type double.
template <typename T>
double percent(const T a) {
    return a/100;
}

// Calculates percent change between two numbers.
template <typename T>
double percent_change(const T a, const T b) {
    // Cannot divide by zero.
    if (b == 0) {
        return 0;
    }
    return (a-b)/b * 100;
}

// Returns the inverse of a given number.
template <typename T>
double inverse(const T n) {
    // Cannot divide by zero.
    if (n == 0) {
        return 0;
    }
    return 1/n;
}

// Calculates factorial of n. Returns type long long.
template <typename T>
long long factorial(const T n) {
    long long result = 1;
    if (n < 0) {
        return 0;
    }
    for (int i = n; i > 0; --i) {
        result *= i;
    }
    return result;
}

// Counts every number up to given int and returns a vector with that sequence.
inline std::vector<int> sequence(const int n) {
    std::vector<int> sequenced_ints;
    sequenced_ints.reserve(n);
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