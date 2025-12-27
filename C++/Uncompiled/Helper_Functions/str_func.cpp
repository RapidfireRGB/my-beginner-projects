#include <iostream>
#include <string>
#include <array>
#include <vector>

// Simple print function which accepts a single string parameter. Type void.
void print(const std::string &str) {
    std::cout << str;
}

// Print function with a line break. Accepts a string parameter. Type void.
void printbr(const std::string &str) {
    std::cout << str << "\n";
}

// Print function with n number of whitespaces at the end. Defaults to 4.
// Accepts type string and short. Type void.
void printtab(const std::string &str, const short n = 4) {
    std::cout << str << std::string(n, ' ');;
}

// Checks whether a string contains a specified char.
// Takes a string and a character for parameters, and returns a bool value.
bool contains(const std::string &str, const char character) {
    if (str.find(character) != std::string::npos) {
        return true;
    }
    return false;
}

// Capitalizes a char. Accepts type char; returns type char.
char capchar(const char character) {
    const std::array<char, 26> uppercase_chars = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    const std::array<char, 26> lowercase_chars = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };
    for (int i = 0; i <= 25; i++) {
        if (character == lowercase_chars[i]) {
            return uppercase_chars[i];
        }
    }
    return character;
}

// Checks if the first character of a string is capitalized. Accepts string; returns type bool.
bool is_capitalized(const std::string &str) {
    const std::array<char, 26> uppercase_chars = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    for (int i = 0; i <= 25; i++) {
        if (str[i] == uppercase_chars[i]) {
            return true;
        }
    }

    return false;
}

// Capitalizes a given string. Only uppercases the first char of the string. Takes string parameter and returns string.
std::string capitalize(std::string str) {

    if (str.empty()) return str;

    // Defining arrays of each char to check against within the for loop.
    const std::array<char, 26> uppercase_chars = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };
    const std::array<char, 26> lowercase_chars = {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };

    for (int i = 0; i <= 25; i++) {

        // Checks first char of input string for index of lowercase chars.
        // If one is found, replace it with an uppercase char and return a new string.
        if (str[0] == lowercase_chars[i]) {

            const char cap = uppercase_chars[i];
            const std::string capitalized{cap};

            std::string new_string = str.replace(0, 1, capitalized);
            return new_string;

        } else if (str[0] == uppercase_chars[i]) {
            return str;
        }

    }

    // If no valid char is found and the string does not get changed, return the original string.
    return str;
}

// Uppercases entire string. Accepts string; returns type string.
std::string uppercase(std::string str) {

    std::string new_str;
    for (int i = 0; i <= str.length(); i++) {
        new_str += capchar(str[i]);
        if (i == str.length()) {
            return new_str;
        }
    }

    return str;
}

// Should find all possible combinations of a string. Accepts string; returns vector<string>.
// TODO finish.
std::vector<std::string> find_permutations(std::string str) {
    std::vector<std::string> permutations;


    return permutations;
}

// Converts a named number ('Zero', 'Seven', etc.) into its integer representation. Accepts string; returns int.
int word_to_int(const std::string &str) {
    const std::array<std::string, 11> named_numbers = {
        "Zero", "One", "Two", "Three", "Four", "Five",
        "Six", "Seven", "Eight", "Nine", "Ten"
    };
    const std::array<int, 11> int_numbers = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };

    for (int i = 0; i <= 10; i++) {
        if (str == named_numbers[i]) {
            return int_numbers[i];
        }
    }

    // Defaults to returning zero.
    return 0;
}

// Should convert a string with multiple words
//std::string title(std::string str) {


//}