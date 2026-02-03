#ifndef HELPERFUNCTIONS_PAIR_FUNC_H
#define HELPERFUNCTIONS_PAIR_FUNC_H
#include <utility>
#include <tuple>
#include <map>
#include <functional>

// Returns a new pair with first and second elements exchanged.
template <typename T1, typename T2>
std::pair<T1, T2> transpose(const std::pair<T1, T2> &pair) {
    std::pair<T1, T2> new_pair(pair.second, pair.first);
    return new_pair;
}

// Returns a new pair with first and second elements exchanged if a condition is met. Else, return a copy.
template <typename T1, typename T2>
std::pair<T1, T2> transpose_if(const std::pair<T1, T2> &pair, const bool condition) {
    std::pair<T1, T2> new_pair = pair;
    if (condition == true) {
        new_pair.first = pair.second;
        new_pair.second = pair.first;
    }
    return new_pair;
}

// Checks if pair with same type elements have equal elements.
template <typename T>
bool has_symmetry(const std::pair<T, T> &pair) {
    if (pair.first == pair.second) {
        return true;
    }
    return false;
}

// Replaces first element with specified value
template <typename T1, typename T2>
void replace_first(std::pair<T1, T2> pair, const T1 value) {
    pair.first = value;
}

// Replaces second element with specified value
template <typename T1, typename T2>
void replace_second(std::pair<T1, T2> pair, const T2 value) {
    pair.second = value;
}

// Compares first value in two pairs.
template <typename T1, typename T2, typename T3>
bool is_first_equal(const std::pair<T1, T2> &pair_1, const std::pair<T1, T3> &pair_2) {
    if (pair_1.first == pair_2.first) {
        return true;
    }
    return false;
}

// Compares second value in two pairs.
template <typename T1, typename T2, typename T3>
bool is_second_equal(const std::pair<T1, T2> &pair_1, const std::pair<T3, T2> &pair_2) {
    if (pair_1.second == pair_2.second) {
        return true;
    }
    return false;
}

// Compares both values in a pair.
template <typename T1, typename T2>
bool is_equal(const std::pair<T1, T2> &pair_1, const std::pair<T1, T2> &pair_2) {
    if (pair_1.first == pair_2.first
        && pair_1.second == pair_2.second) {
        return true;
    }
    return false;
}

// Rearranges elements between two pairs in a cross fashion (x1 <-> y2; y1 <-> x2)
template <typename T1, typename T2, typename T3, typename T4>
void cross(std::pair<T1, T2> pair_1, std::pair<T3, T4> pair_2) {
    T1 temp_x = pair_1.first;
    T2 temp_y = pair_1.second;
    pair_1.first = pair_2.second;
    pair_1.second = pair_2.first;
    pair_2.first = temp_y;
    pair_2.second = temp_x;
}

// Returns a tuple of a pair's elements.
template <typename T1, typename T2>
std::tuple<T1, T2> pair_to_tuple(const std::pair<T1, T2> &pair) {
    std::tuple<T1, T2> new_tuple(pair.first, pair.second);
    return new_tuple;
}

// Sorts a pair in descending order
template <typename T>
void sort_desc(std::pair<T, T> pair) {
    if (pair.first < pair.second) {
        std::swap(pair.first, pair.second);
    }
}

// Sorts a pair in ascending order
template <typename T>
void sort_asc(std::pair<T, T> pair) {
    if (pair.first > pair.second) {
        std::swap(pair.first, pair.second);
    }
}

// Inserts a pair's elements into a map.
template <typename T1, typename T2>
void add_to_map(const std::pair<T1, T2> &pair, std::map<T1, T2> map) {
    map.insert(pair.first, pair.second);
}

// Make a pair from a function's input and output
template <typename T1, typename T2>
std::pair<T1, T2> io_pair(std::function<T2(T1)> func, T1 input) {
    std::pair<T1, T2> new_pair(input, func(input));
    return new_pair;
}

// Returns the percent change between a pair's elements.
template <typename T>
T percent_change(const std::pair<T, T> &pair) {
    if (pair.second == 0) {
        return 0;
    }
    T result = (pair.first - pair.second)/pair.second * 100;
    return result;
}

// Applies a transformation function to both elements of a pair.
template <typename T1, typename T2, typename T3>
void transform_pair(std::pair<T1, T2> pair, std::function<T3(T1, T2)> func) {
    func(pair.first, pair.second);
}



#endif //HELPERFUNCTIONS_PAIR_FUNC_H