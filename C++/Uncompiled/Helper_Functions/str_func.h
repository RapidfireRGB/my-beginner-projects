#ifndef HELPERFUNCTIONS_STR_FUNC_H
#define HELPERFUNCTIONS_STR_FUNC_H
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>

// Simple print function which accepts a single string parameter. Type void.
inline void print(const std::string &str) {
    std::cout << str;
}

// Print function with a line break. Accepts a string parameter. Type void.
inline void printbr(const std::string &str) {
    std::cout << str << "\n";
}

// Print function with n number of whitespaces at the end. Defaults to 4.
// Accepts type string and short. Type void.
inline void printtab(const std::string &str, const short n = 4) {
    std::cout << str << std::string(n, ' ');;
}

// Checks whether a string contains a specified char.
// Takes a string and a character for parameters, and returns a bool value.
inline bool contains(const std::string &str, const char character) {
    if (str.find(character) != std::string::npos) {
        return true;
    }
    return false;
}

// Strip whitespace out of a string. Returns a substring.
inline std::string strip(const std::string &str) {
    // Return an empty string if original string is empty.
    if (str.empty()) {
        return "";
    }
    std::string new_str = str;
    for (int i = 0; i <= str.size()-1; i++) {
        if (str[i] == ' ') {
            new_str.erase(i, 1);
            i--;
        }
    }
    return new_str;
}

// Returns longest of two strings.
inline std::string longest(std::string str_1, std::string str_2) {
    if (str_1.length() > str_2.length()) {
        return str_1;
    }
    if (str_2.length() > str_1.length()) {
        return str_2;
    }
    if (str_1.length() == str_2.length()) {
        return str_1;
    }
    return "";
}

// Returns shortest of two strings.
inline std::string shortest(std::string str_1, std::string str_2) {
    if (str_1.length() < str_2.length()) {
        return str_1;
    }
    if (str_2.length() < str_1.length()) {
        return str_2;
    }
    if (str_1.length() == str_2.length()) {
        return str_1;
    }
    return "";
}

// Returns a reversed string.
inline std::string reverse(const std::string &str) {
    std::string new_str;
    for (int i = str.length() - 1, loops = 0; i >= 0; i--, loops++) {
        new_str.insert(loops, 1, str[i]);
    }
    return new_str;
}

// Returns a string with substituted char. Takes string, desired char, and position in the string.
inline std::string substitute(const std::string &str, const char c, const int pos = 0) {
    std::string new_str = str;
    new_str[pos] = c;
    return new_str;
}

// Returns integer representation of a char.
inline int char_to_int(const char c) {
    std::map<char, int> nums = {
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
    const int n = nums[c];
    return n;
}

// Capitalizes a char. Accepts type char; returns type char.
inline char capchar(const char character) {
    for (int i = 0; i <= 25; i++) {
        constexpr std::array<char, 26> lowercase_chars = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
        };

        if (character == lowercase_chars[i]) {
            constexpr std::array<char, 26> uppercase_chars = {
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
            };
            return uppercase_chars[i];
        }
    }
    return character;
}

// Checks if the first character of a string is capitalized. Accepts string; returns type bool.
inline bool is_capitalized(const std::string &str) {
    for (int i = 0; i <= 25; i++) {
        constexpr std::array<char, 26> uppercase_chars = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
        };
        if (str[i] == uppercase_chars[i]) {
            return true;
        }
    }
    return false;
}

// Capitalizes a given string. Only uppercases the first char of the string. Takes string parameter and returns string.
inline std::string capitalize(std::string str) {
    if (str.empty()) return str;

    for (int i = 0; i <= 25; i++) {
        constexpr std::array<char, 26> lowercase_chars = {
            'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
        };
        constexpr std::array<char, 26> uppercase_chars = {
            'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
            'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
        };

        // Checks first char of input string for index of lowercase chars.
        // If one is found, replace it with an uppercase char and return a new string.
        if (str[0] == lowercase_chars[i]) {

            const char cap = uppercase_chars[i];
            const std::string capitalized{cap};

            std::string new_string = str.replace(0, 1, capitalized);
            return new_string;

        }
        if (str[0] == uppercase_chars[i]) {
            return str;
        }
    }

    // If no valid char is found and the string does not get changed, return the original string.
    return str;
}

// Uppercases entire string. Accepts string; returns type string.
inline std::string uppercase(std::string str) {
    std::string new_str;

    // For every character in input string, add corresponding uppercase character to an empty string.
    // Once the for loop ends, return the new string.
    for (int i = 0; i <= str.length(); i++) {
        new_str += capchar(str[i]);
        if (i == str.length()) {
            return new_str;
        }
        if (i == str.length() && new_str == "") {
            break;
        }
    }
    // If no chars can be capitalized, return the original string.
    return str;
}

// Converts a named number ('Zero', 'Seven', etc.) into its integer representation. Accepts string; returns int.
inline int word_to_int(const std::string &str) {
    std::map<std::string, int> nums = {
        {"Zero", 0},
        {"One", 1},
        {"Two", 2},
        {"Three", 3},
        {"Four", 4},
        {"Five", 5},
        {"Six", 6},
        {"Seven", 7},
        {"Eight", 8},
        {"Nine", 9},
        {"Ten", 10},
        {"Eleven", 11},
        {"Twelve", 12},
        {"Thirteen", 13},
        {"Fourteen", 14},
        {"Fifteen", 15},
        {"Sixteen", 16},
        {"Seventeen", 17},
        {"Eighteen", 18},
        {"Nineteen", 19},
        {"Twenty", 20}
    };
    try {
        return nums[str];
    } catch (...) {
        // Defaults to returning zero.
        return 0;
    }
}

// Converts a vector of chars to a string.
inline std::string vec_to_str(const std::vector<char> &chars) {
    std::string new_str;
    for (int i = 0; i <= chars.size(); i++) {
        new_str += chars[i];
    }
    return new_str;
}

// Returns a vector of each char of a string.
inline std::vector<char> str_to_char_vec(const std::string &str) {
    std::vector<char> chars;
    for (int i = 0; i < str.length(); i++) {
        chars.push_back(str[i]);
    }
    return chars;
}

// Return integer of # of vowels in a string.
inline int count_vowels(const std::string &str) {
    int vowel_count = 0;
    for (int i = 0; i <= str.size(); i++) {
        // Checks for j is not greater than array index range
        for (int j = 0; j <= 11; j++) {
            constexpr std::array<char, 12> vowels = {
                'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'
            };
            if (str[i] == vowels[j]) {
                vowel_count++;
            }
        }
    }
    return vowel_count;
}

// Return a substring containing only the vowels of a given string.
inline std::string extract_vowels(const std::string &str) {
    std::string new_str;
    for (int i = 0; i <= str.size(); i++) {
        // Checks for j is not greater than array index range
        for (int j = 0; j <= 11; j++) {
            constexpr std::array<char, 12> vowels = {
                'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'
            };
            if (str[i] == vowels[j]) {
                new_str += str[i];
            }
        }
    }
    return new_str;
}

// Returns an integer of # special chars in a given string.
inline int count_special_chars(const std::string &str) {
    int spec_char_count = 0;
    for (int i = 0; i <= str.size(); i++) {
        // Checks for j is not greater than array index range
        for (int j = 0; j <= 29; j++) {
            constexpr std::array<char, 30> special_chars = {
                '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '{', '[', ']', '}',
                '|', '.', ',', ';', ':', '<', '>', '/', '?', '`', '~', '"'
            };
            if (str[i] == special_chars[j]) {
                spec_char_count++;
            }
        }
    }
    return spec_char_count;
}

// Returns number of ints in a string
inline int count_ints(const std::string &str) {
    int count = 0;
    for (int i = 0; i <= str.size(); i++) {
        // Checks for j is not greater than array index range
        for (int j = 0; j <= 9; j++) {
            constexpr std::array<char, 10> ints = {
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
            };
            if (str[i] == ints[j]) {
                count++;
            }
        }
    }
    return count;
}

// Returns a substring with only the integers of a given string.
inline std::string extract_ints(const std::string &str) {
    std::string new_str;
    for (int i = 0; i <= str.size(); i++) {
        for (int j = 0; j <= 9; j++) {
            constexpr std::array<char, 10> ints = {
                '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
            };
            if (str[i] == ints[j]) {
                new_str += str[i];
            }
        }
    }
    return new_str;
}

// Returns the sum of all integers within a string.
inline int sum_ints_from_string(const std::string &str) {
    int sum = 0;
    const std::string temp = extract_ints(str);
    for (int i = 0; i <= temp.size(); i++) {
        sum += char_to_int(temp[i]);
    }
    return sum;
}

// Returns a rearranged substring given 2 positions (first char position, second char position).
inline std::string rearrange(std::string str, const int pos_1, const int pos_2) {
    if (pos_2 <= pos_1) {
        return str;
    }
    std::string new_str = str;
    const char char_1 = new_str[pos_1];
    const char char_2 = new_str[pos_2];

    new_str.erase(pos_1, 1);
    // Minus 1 here to account for now having 1 less char
    new_str.erase(pos_2-1, 1);

    new_str.insert(pos_1, 1, char_2);
    new_str.insert(pos_2, 1, char_1);

    return new_str;
}

// Helper function to rearrange a string for a given permutation of a string.
// Takes string, storage vector, and optional starting position (defaults to 0).
inline void permute(const std::string &str, std::vector<std::string> &output, const int pos=0) {
    // Bounds checking.
    if (pos == str.length() - 1) {
        output.push_back(str);
        return;
    }
    // Recursive loop calls function until i reaches string bounds.
    for (int i = pos; i < str.length(); i++) {
        std::string new_str = rearrange(str, pos, i);
        permute(new_str, output, pos + 1);
    }
}

// Returns a vector of all possible permutations of a string.
inline std::vector<std::string> permutations(const std::string &str) {
    std::vector<std::string> permutations;
    // Call to permute function to store permutations in the vector
    permute(str, permutations);
    // Should return a vector with size of factorial str.size()
    return permutations;
}


#endif //HELPERFUNCTIONS_STR_FUNC_H