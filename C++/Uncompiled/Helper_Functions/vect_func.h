#ifndef HELPERFUNCTIONS_VECT_FUNC_H
#define HELPERFUNCTIONS_VECT_FUNC_H
#include <vector>
#include <string>
#include <map>

// Returns a reversed int vector from another vector.
inline std::vector<int> int_reverse(const std::vector<int> &range) {
    std::vector<int> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = range.size()-1; i >= 0; i--) {
        new_vec.push_back(range[i]);
    }
    return new_vec;
}

// Returns a reversed double vector from another vector.
inline std::vector<double> dbl_reverse(const std::vector<double> &range) {
    std::vector<double> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = range.size()-1; i >= 0; i--) {
        new_vec.push_back(range[i]);
    }
    return new_vec;
}

// Returns a reversed char vector from another vector.
inline std::vector<char> char_reverse(const std::vector<char> &chars) {
    std::vector<char> new_vec;
    if (chars.empty()) {
        return new_vec;
    }
    for (int i = chars.size()-1; i >= 0; i--) {
        new_vec.push_back(chars[i]);
    }
    return new_vec;
}

// Returns a reversed bool vector from another vector.
inline std::vector<bool> bool_reverse(const std::vector<bool> &booleans) {
    std::vector<bool> new_vec;
    if (booleans.empty()) {
        return new_vec;
    }
    for (int i = booleans.size()-1; i >= 0; i--) {
        new_vec.push_back(booleans[i]);
    }
    return new_vec;
}

// Returns int vector of all index positions of int element.
inline std::vector<int> int_indices(const std::vector<int> &range, const int n) {
    std::vector<int> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == n) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

// Returns int vector of all index positions of double element.
inline std::vector<int> dbl_indices(const std::vector<double> &range, const double n) {
    std::vector<int> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == n) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

// Returns int vector of all index positions of string element.
inline std::vector<int> str_indices(const std::vector<std::string> &str, const std::string &element) {
    std::vector<int> new_vec;
    if (str.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= str.size()-1; i++) {
        if (str[i] == element) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

// Returns int vector of all index positions of char element.
inline std::vector<int> char_indices(const std::vector<char> &chars, const char element) {
    std::vector<int> new_vec;
    if (chars.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= chars.size()-1; i++) {
        if (chars[i] == element) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

// Returns int vector of all index positions of bool element.
inline std::vector<int> bool_indices(std::vector<bool> booleans, const bool value) {
    std::vector<int> new_vec;
    if (booleans.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        if (booleans[i] == value) {
            new_vec.push_back(i);
        }
    }
    return new_vec;
}

// Returns bool of whether an int vector contains a specified element.
inline bool int_contains(const std::vector<int> &range, const int n) {
    if (range.empty()) {
        return false;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == n) {
            return true;
        }
    }
    return false;
}

// Returns bool of whether a string vector contains a specified element.
inline bool str_contains(const std::vector<std::string> &str, const std::string &element) {
    if (str.empty()) {
        return false;
    }
    for (int i = 0; i <= str.size()-1; i++) {
        if (str[i] == element) {
            return true;
        }
    }
    return false;
}

// Returns bool of whether a double vector contains a specified element.
inline bool dbl_contains(const std::vector<double> &range, const double n) {
    if (range.empty()) {
        return false;
    }
    for (int i = 0; i <= range.size()-1; i++) {
        if (range[i] == n) {
            return true;
        }
    }
    return false;
}

// Return bool of whether a char vector contains a specified element
inline bool char_contains(const std::vector<char> &chars, const char element) {
    if (chars.empty()) {
        return false;
    }
    for (int i = 0; i <= chars.size()-1; i++) {
        if (chars[i] == element) {
            return true;
        }
    }
    return false;
}

// Return bool of whether a bool vector contains a specified element
inline bool bool_contains(const std::vector<bool> &booleans, const bool value) {
    if (booleans.empty()) {
        return false;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        if (booleans[i] == value) {
            return true;
        }
    }
    return false;
}

// Returns same type vector containing only one occurrence per int element.
inline std::vector<int> int_unique(const std::vector<int> &range) {
    std::vector<int> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    new_vec.push_back(range[0]);
    for (int i = 1; i <= range.size()-1; i++) {
        if (!int_contains(new_vec, range[i])) {
            new_vec.push_back(range[i]);
        }
    }
    return new_vec;
}

// Returns same type vector containting only one occurrence per string element.
inline std::vector<std::string> str_unique(const std::vector<std::string> &str) {
    std::vector<std::string> new_vec;
    if (str.empty()) {
        return new_vec;
    }
    new_vec.push_back(str[0]);
    for (int i = 1; i <= str.size()-1; i++) {
        if (!str_contains(new_vec, str[i])) {
            new_vec.push_back(str[i]);
        }
    }
    return new_vec;
}

// Returns same type vector containing only one occurrence per double element.
inline std::vector<double> dbl_unique(const std::vector<double> &range) {
    std::vector<double> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    new_vec.push_back(range[0]);
    for (int i = 1; i <= range.size()-1; i++) {
        if (!dbl_contains(new_vec, range[i])) {
            new_vec.push_back(range[i]);
        }
    }
    return new_vec;
}

// Returns same type vector containing only one occurrence per char element.
inline std::vector<char> char_unique(const std::vector<char> &chars) {
    std::vector<char> new_vec;
    if (chars.empty()) {
        return new_vec;
    }
    new_vec.push_back(chars[0]);
    for (int i = 1; i <= chars.size()-1; i++) {
        if (!char_contains(new_vec, chars[i])) {
            new_vec.push_back(chars[i]);
        }
    }
    return new_vec;
}

// Return a sub vector between two index positions.
inline std::vector<int> int_slice(const std::vector<int> &range, int pos_1, int pos_2) {
    std::vector<int> new_vec;
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

// Return a sub vector between two index positions.
inline std::vector<std::string> str_slice(const std::vector<std::string> &str, int pos_1, int pos_2) {
    std::vector<std::string> new_vec;
    if (str.empty()) {
        return new_vec;
    }
    // Bounds checking.
    if (pos_1 < 0) {
        pos_1 = 0;
    }
    if (pos_2 > str.size()-1) {
        pos_2 = str.size()-1;
    }
    for (int i = pos_1; i <= pos_2; i++) {
        new_vec.push_back(str[i]);
    }
    return new_vec;
}

// Return a sub vector between two index positions
inline std::vector<double> dbl_slice(const std::vector<double> &range, int pos_1, int pos_2) {
    std::vector<double> new_vec;
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

// Return a sub vector between two index positions
inline std::vector<char> char_slice(const std::vector<char> &chars, int pos_1, int pos_2) {
    std::vector<char> new_vec;
    if (chars.empty()) {
        return new_vec;
    }
    // Bounds checking.
    if (pos_1 < 0) {
        pos_1 = 0;
    }
    if (pos_2 > chars.size()-1) {
        pos_2 = chars.size()-1;
    }
    for (int i = pos_1; i <= pos_2; i++) {
        new_vec.push_back(chars[i]);
    }
    return new_vec;
}

// Returns number of 'true' in a bool vector
inline int count_trues(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i <= booleans.size()-1; i++) {
        if (booleans[i] == true) {
            count++;
        }
    }
    return count;
}

// Returns number of 'false' in a bool vector
inline int count_falses(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return 0;
    }
    int count = 0;
    for (int i = 0; i <= booleans.size()-1; i++) {
        if (booleans[i] == false) {
            count++;
        }
    }
    return count;
}

// Returns bool vector with most elements set to 'true'
inline std::vector<bool> most_true(std::vector<bool> vec_1, std::vector<bool> vec_2) {
    const int trues_1 = count_trues(vec_1);
    const int trues_2 = count_trues(vec_2);
    if (trues_1 > trues_2) {
        return vec_1;
    }
    if (trues_2 > trues_1) {
        return vec_2;
    }
    return vec_1;
}

// Returns bool vector with most elements set to 'false'
inline std::vector<bool> most_false(std::vector<bool> vec_1, std::vector<bool> vec_2) {
    const int falses_1 = count_falses(vec_1);
    const int falses_2 = count_falses(vec_2);
    if (falses_1 > falses_2) {
        return vec_1;
    }
    if (falses_2 > falses_1) {
        return vec_2;
    }
    return vec_1;
}

// Returns index position of first 'true' found in bool vector. If none, return 0.
inline int first_true(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return 0;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        if (booleans[i] == true) {
            return i;
        }
    }
    return 0;
}

// Returns index position of first 'false' found in bool vector. If none, return 0.
inline int first_false(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return 0;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        if (booleans[i] == false) {
            return i;
        }
    }
    return 0;
}

// Returns index position of last 'true' found in bool vector. If none, return 0.
inline int last_true(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return 0;
    }
    for (int i = booleans.size()-1; i >= 0; i--) {
        if (booleans[i] == true) {
            return i;
        }
    }
    return 0;
}

// Returns index position of last 'false' found in bool vector. If none, return 0.
inline int last_false(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return 0;
    }
    for (int i = booleans.size()-1; i >= 0; i--) {
        if (booleans[i] == false) {
            return i;
        }
    }
    return 0;
}

// Sets all values in bool vector to true. Type void.
inline void set_true(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        booleans[i] = true;
    }
}

// Sets all values in bool vector to false. Type void.
inline void set_false(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        booleans[i] = false;
    }
}

// Set an entire bool vector's elements to their opposite values. Type void.
inline void flip_all(std::vector<bool> booleans) {
    if (booleans.empty()) {
        return;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        if (booleans[i] == true) {
            booleans[i] = false;
        } else if (booleans[i] == false) {
            booleans[i] = true;
        }
    }
}

// Set a bool vector's values to their opposite between two given positions. Type void.
inline void flip_range(std::vector<bool> booleans, int pos_1=0, int pos_2=3) {
    if (booleans.empty()) {
        return;
    }
    // Bounds checking.
    if (pos_1 < 0) {
        pos_1 = 0;
    }
    if (pos_2 > booleans.size()-1) {
        pos_2 = booleans.size()-1;
    }
    for (int i = pos_1; i <= pos_2; i++) {
        if (booleans[i] == true) {
            booleans[i] = false;
        } else if (booleans[i] == false) {
            booleans[i] = true;
        }
    }
}

// Set entire bool vector to true or false.
inline void assign_all(std::vector<bool> booleans, const bool value) {
    if (booleans.empty()) {
        return;
    }
    for (int i = 0; i <= booleans.size()-1; i++) {
        booleans[i] = value;
    }
}

// Set to true or false within a specified index range (0-3 by default) Type void.
inline void assign_range(std::vector<bool> booleans, const bool value, int pos_1=0, int pos_2=3) {
    if (booleans.empty()) {
        return;
    }
    // Bounds checking.
    if (pos_1 < 0) {
        pos_1 = 0;
    }
    if (pos_2 > booleans.size()-1) {
        pos_2 = booleans.size()-1;
    }
    for (int i = pos_1; i <= pos_2; i++) {
        if (booleans[i] != value) {
            booleans[i] = value;
        }
    }
}

// Return a sub vector containing only elements which satisfy a defined condition.
inline std::vector<int> int_filter(const std::vector<int> &range, const bool condition) {
    std::vector<int> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= range.size()-1 && condition == true; i++) {
        new_vec.push_back(range[i]);
    }
    return new_vec;
}

// Return a sub vector containing only elements which satisfy a defined condition
inline std::vector<std::string> str_filter(const std::vector<std::string> &str, const bool condition) {
    std::vector<std::string> new_vec;
    if (str.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= str.size()-1 && condition == true; i++) {
        new_vec.push_back(str[i]);
    }
    return new_vec;
}

// Return a sub vector containing only elements which satisfy a defined condition
inline std::vector<double> dbl_filter(const std::vector<double> &range, const bool condition) {
    std::vector<double> new_vec;
    if (range.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= range.size()-1 && condition == true; i++) {
        new_vec.push_back(range[i]);
    }
    return new_vec;
}

// Return a sub vector containing only elements which satisfy a defined condition
inline std::vector<char> char_filter(const std::vector<char> &chars, const bool condition) {
    std::vector<char> new_vec;
    if (chars.empty()) {
        return new_vec;
    }
    for (int i = 0; i <= chars.size()-1 && condition == true; i++) {
        new_vec.push_back(chars[i]);
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

#endif //HELPERFUNCTIONS_VECT_FUNC_H