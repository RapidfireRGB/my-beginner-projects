#ifndef HELPERFUNCTIONS_BOOL_FUNC_H
#define HELPERFUNCTIONS_BOOL_FUNC_H
#include <string>
#include <vector>

// Function to 'flip' the value of a boolean.
inline void toggle(bool value) {
    if (value == true) {
        value = false;
    } else if (value == false) {
        value = true;
    }
}

// Returns true if two boolean values are different. If not, returns false.
inline bool bool_xor(const bool bool_1, const bool bool_2) {
    if (bool_1 != bool_2) {
        return true;
    }
    return false;
}

// Returns string 'True' or 'False'
inline std::string bool_to_str(const bool value) {
    if (value == true) {
        return "True";
    }
    return "False";
}

// Returns int '1' or '0'
inline int bool_to_int(const bool value) {
    if (value == true) {
        return 1;
    }
    return 0;
}

// Returns true if two booleans are equal, or false if not.
inline bool bool_equal(const bool bool_1, const bool bool_2) {
    if (bool_1 == bool_2) {
        return true;
    }
    return false;
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

// Returns true if all elements in bool vector are true.
inline bool all_true(const std::vector<bool> &booleans) {
    if (booleans.empty()) {
        return false;
    }
    if (const int trues = count_trues(booleans); trues == booleans.size()) {
        return true;
    }
    return false;
}

// Returns true if any elements in bool vector are true
inline bool any_true(const std::vector<bool> &booleans) {
    if (booleans.empty()) {
        return false;
    }
    if (const int trues = count_trues(booleans); trues > 0) {
        return true;
    }
    return false;
}

// Returns true if no elements in bool vector are true
inline bool none_true(const std::vector<bool> &booleans) {
    if (booleans.empty()) {
        return true;
    }
    if (const int trues = count_trues(booleans); trues > 0) {
        return false;
    }
    return true;
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

#endif //HELPERFUNCTIONS_BOOL_FUNC_H