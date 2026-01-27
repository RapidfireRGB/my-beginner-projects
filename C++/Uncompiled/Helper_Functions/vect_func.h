#ifndef HELPERFUNCTIONS_VECT_FUNC_H
#define HELPERFUNCTIONS_VECT_FUNC_H
#include <iostream>
#include <vector>
#include <string>
#include <map>

// Prints contents of a vector.
template<typename T>
void print_vec(std::vector<T> range) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        std::cout << range[i];
    }
}

// Prints contents of a vector separated by linebreaks.
template <typename T>
void printbr_vec(std::vector<T> range) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        std::cout << range[i] << '\n';
    }
}

// Prints contents of a vector separated by n number of whitespaces (4 by default)
template <typename T>
void printtab_vec(std::vector<T> range, const short n=4) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        std::cout << range[i] << std::string(n, ' ');
    }
}

// Adds elements of two same type vectors and combines results into one vector.
template <typename T>
std::vector<T> add(const std::vector<T> &range_1, const std::vector<T> &range_2) {
    std::vector<T> new_vec;
    if (range_1.empty() && range_2.empty()) {
        return new_vec;
    }
    int end;
    if (range_1.size() > range_2.size()) {
        end = range_1.size()-1;
    } else {
        end = range_2.size()-1;
    }
    for (int i = 0; i <= end; i++) {
        new_vec.push_back(range_1[i] + range_2[i]);
    }
    return new_vec;
}

// Returns a reversed vector from another vector.
template <typename T>
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

// Returns a vector of all index positions of specified element.
template <typename T>
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

// Returns number of occurences of a given element in a vector.
template <typename T>
int quantity(const std::vector<T> &range, T element) {
    if (range.empty()) {
        return 0;
    }
    int quantity = 0;
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == element) {
            quantity++;
        }
    }
    return quantity;
}

// Returns bool of whether a vector contains a specified element.
template <typename T>
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

// Checks if an element is unique
template <typename T>
bool is_unique(const std::vector<T> &range, const T element) {
    if (range.empty() || !contains(range, element)) {
        return false;
    }
    if (quantity(range, element) == 1) {
        return true;
    }
    return false;
}

// Checks if an element is a duplicate
template <typename T>
bool is_duplicate(const std::vector<T> &range, T element) {
    if (range.empty() || !contains(range, element)) {
        return false;
    }
    if (quantity(range, element) > 1) {
        return true;
    }
    return false;
}

// Returns number of unique elements
template <typename T>
int count_unique(const std::vector<T> &range) {
    if (range.empty()) {
        return 0;
    }
    int count = 0;
    for (int i = 1; i <= range.size()-1; i++) {
        if (quantity(range, range[i]) == 1) {
            count++;
        }
    }
    return count;
}

// Returns number of duplicate elements
template <typename T>
int count_duplicate(const std::vector<T> &range) {
    if (range.empty()) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i <= range.size()-1; i++) {
        if (quantity(range, range[i]) > 1) {
            count++;
        }
    }
    return count;
}

// Returns same type vector containing only one occurrence per unique element.
template <typename T>
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

// Return a sub vector between two index positions.
template <typename T>
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

// Return a sub vector containing only elements which satisfy a defined condition.
template <typename T>
std::vector<T> filter(const std::vector<T> &range, const bool condition) {
    std::vector<T> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= range.size()-1; i++) {
         if (condition == true) {
             new_vec.push_back(range[i]);
         }
    }
    return new_vec;
}

// Return a sub vector containing elements which satisfy a condition between two index positions.
template <typename T>
std::vector<T> filter_slice(const std::vector<T> &range, const bool condition, int pos_1, int pos_2) {
    std::vector<T> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    if (pos_1 < 0) {
        pos_1 = 0;
    }
    if (pos_2 > range.size()-1) {
        pos_2 = range.size()-1;
    }
    for (int i = pos_1; i <= pos_2; i++) {
        if (condition == true) {
            new_vec.push_back(range[i]);
        }
    }
    return new_vec;
}

// Fills vector with a specified value.
template <typename T>
void fill(std::vector<T> range, T value) {
    for (int i = 0; i <= range.size()-1; i++) {
        range[i] = value;
    }
}

// Fills vector with value if condition is met.
template <typename T>
void fill_if(std::vector<T> range, T value, const bool condition) {
    for (int i = 0; i <= range.size()-1; i++) {
        if (condition == true) {
            range[i] = value;
        }
    }
}

// Fills vector with a value between two index positions.
template <typename T>
void fill_between(std::vector<T> range, T value, int pos_1, int pos_2) {
    if (pos_1 < 0) {
        pos_1 = 0;
    }
    if (pos_2 > range.size()-1) {
        pos_2 = range.size()-1;
    }
    for (int i = pos_1; i <= pos_2; i++) {
        range[i] = value;
    }
}

// Removes all occurrences of an element.
template <typename T>
void erase_all_of(std::vector<T> range, T element) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == element) {
            range.erase(range[i]);
            i--;
        }
    }
}

// Eliminates duplicate elements from a vector.
template <typename T>
void reduce(std::vector<T> range) {
    if (range.empty()) {
        return;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (!is_unique(range, range[i])) {
            range.erase(range[i]);
            i--;
        }
    }
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

// Returns a map of the frequency an element appears {key=element, value=frequency}
template <typename T>
std::map<T, int> frequency(const std::vector<T> &range) {
    std::map<T, int> new_map;
    if (range.empty()) {
        return new_map;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        new_map.insert(range[i], indices(range, range[i]).size());
    }
    return new_map;
}

// Checks whether a vector is sorted in ascending order.
template <typename T>
bool is_sorted_asc(const std::vector<T> &range) {
    if (range.empty()) {
        return false;
    }
    if (range.size() == 1) {
        return true;
    }
    for (int i = 0; i < range.size()-1; i++) {
        if (range[i] > range[i+1]) {
            return false;
        }
    }
    return true;
}

// Checks whether a vector is sorted in descending order.
template <typename T>
bool is_sorted_desc(const std::vector<T> &range) {
    if (range.empty()) {
        return false;
    }
    if (range.size() == 1) {
        return true;
    }
    for (int i = 0; i < range.size()-1; i++) {
        if (range[i] < range[i+1]) {
            return false;
        }
    }
    return true;
}

// Checks whether a string vector is sorted in alphabetical order.
inline bool is_sorted_alph(const std::vector<std::string> &str) {
    if (str.empty()) {
        return false;
    }
    if (str.size() == 1) {
        return true;
    }
    for (int i = 0; i < str.size()-1; i++) {
        if (str[i] > str[i+1]) {
            return false;
        }
    }
    return true;
}

#endif //HELPERFUNCTIONS_VECT_FUNC_H