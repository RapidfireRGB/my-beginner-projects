#ifndef HELPERFUNCTIONS_VECT_FUNC_H
#define HELPERFUNCTIONS_VECT_FUNC_H
#include <iostream>
#include <vector>
#include <string>
#include <map>

template<typename T>
// Prints contents of a vector.
void print_vec(std::vector<T> range) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        std::cout << range[i];
    }
}

template <typename T>
// Prints contents of a vector separated by linebreaks.
void printbr_vec(std::vector<T> range) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        std::cout << range[i] << "\n";
    }
}

template <typename T>
// Prints contents of a vector separated by n number of whitespaces (4 by default)
void printtab_vec(std::vector<T> range, const short n=4) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        std::cout << range[i] << std::string(n, ' ');
    }
}

template <typename T>
// Returns a reversed vector from another vector.
std::vector<T> reverse(const std::vector<T> &range) {
    std::vector<T> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = range.size()-1; i >= 0; --i) {
        new_vec.push_back(range[i]);
    }
    return new_vec;
}

template <typename T>
// Returns a vector of all index positions of specified element.
std::vector<T> indices(const std::vector<T> &range, const T element) {
    std::vector<T> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == element) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

template <typename T>
// Returns bool of whether a vector contains a specified element.
bool contains(const std::vector<T> &range, const T element) {
    if (range.empty()) {
        return false;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == element) {
            return true;
        }
    }
    return false;
}

template <typename T>
// Checks if an element is unique
bool is_unique(std::vector<T> range, T element) {
    if (range.empty() || !contains(range, element)) {
        return false;
    }
    if (indices(range, element).size() > 1) {
        return true;
    }
    return false;
}

template <typename T>
// Returns number of unique elements
int count_unique(std::vector<T> range) {
    if (range.empty()) {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= range.size()-1; i++) {
        if (indices(range, range[i]).size() == 1) {
            count++;
        }
    }
    return count;
}

template <typename T>
// Returns same type vector containing only one occurrence per unique element.
std::vector<T> unique(const std::vector<T> &range) {
    std::vector<T> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    new_vec.push_back(range[0]);
    for (int i = 1; i <= range.size()-1; i++) {
        if (!contains(new_vec, range[i])) {
            new_vec.push_back(range[i]);
        }
    }
    return new_vec;
}

template <typename T>
// Return a sub vector between two index positions.
std::vector<T> slice(const std::vector<T> &range, int pos_1, int pos_2) {
    std::vector<T> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    // Bounds checking.
    if (pos_1 < 0) {
        pos_1 = 0;
    }
    if (pos_2 > range.size()-1) {
        pos_2 = range.size()-1;
    }
    for (int i = pos_1; i <= pos_2; i++) {
        new_vec.push_back(range[i]);
    }
    return new_vec;
}

template <typename T>
// Return a sub vector containing only elements which satisfy a defined condition.
std::vector<T> filter(const std::vector<T> &range, const bool condition) {
    std::vector<T> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= range.size()-1 && condition == true; i++) {
        new_vec.push_back(range[i]);
    }
    return new_vec;
}

// Returns a vector of converted int->bool values.
// EX: 1 -> true; 0 -> false
inline std::vector<bool> vec_int_to_bool(const std::vector<int> &range) {
    std::vector<bool> booleans;
    if (range.empty()) {
        return booleans;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == 1) {
            booleans.push_back(true);
        }
        if (range[i] == 0) {
            booleans.push_back(false);
        }
    }
    return booleans;
}

// Returns a vector of converted bool->int values.
// EX: true -> 1; false -> 0
inline std::vector<int> vec_bool_to_int(const std::vector<bool> &booleans) {
    std::vector<int> new_vec;
    if (booleans.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= booleans.size(); i++) {
        if (booleans[i] == true) {
            new_vec.push_back(1);
        }
        if (booleans[i] == false) {
            new_vec.push_back(0);
        }
    }
    return new_vec;
}

// Returns a vector of converted char->int values
inline std::vector<int> vec_char_to_int(const std::vector<char> &chars) {
    std::vector<int> new_vec;
    if (chars.empty()) {
        return new_vec;
    }
    std::map<char, int> conversion = {
        {'0', 0},
        {'1', 1},
        {'2', 2},
        {'3', 3},
        {'4', 4},
        {'5', 5},
        {'6', 6},
        {'7', 7},
        {'8', 8},
        {'9', 9}
    };
    for (int i = 0; i <= chars.size()-1; i++) {
        new_vec.push_back(conversion[chars[i]]);
    }
    return new_vec;
}

// Returns a string made of all elements from a char vector
inline std::string vec_char_to_strl(const std::vector<char> &chars) {
    if (chars.empty()) {
        return "";
    }
    std::string new_str;
    for (int i = 0; i <= chars.size()-1; i++) {
        new_str += chars[i];
    }
    return new_str;
}

template <typename T>
// Returns a map of the frequency an element appears {key=element, value=frequency}
std::map<T, int> frequency(std::vector<T> range) {
    std::map<T, int> new_map;
    if (range.empty()) {
        return new_map;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        new_map.insert(range[i], indices(range, range[i]).size());
    }
    return new_map;
}

#endif //HELPERFUNCTIONS_VECT_FUNC_H