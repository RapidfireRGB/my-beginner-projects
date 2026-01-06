#ifndef BASIC_SPREADSHEET_CELL_TYPE_H
#define BASIC_SPREADSHEET_CELL_TYPE_H

#include <iostream>
#include <string>
#include <map>

// Defining types of content in cells
enum class cell_type {
    Empty, Text, Value, Expression
    //TODO add comparison type
};

struct cell {
    cell_type type = cell_type::Empty;
    std::string contents;
    double value = 0.0;

    // Clear the contents of a cell and set the type to empty.
    void clear() {
        contents.clear();
        value = 0.0;
        type = cell_type::Empty;
    }

    // Write contents to a cell and determine its appropriate type (ex: if it has '=', convert it to Expression).
    void write(const std::string& input) {
        contents = input;

        if (contents.empty()) {
            type = cell_type::Empty;

        } else if (contents[0] == '=') {
            type = cell_type::Expression;

        } else {
            try {
                value = std::stod(contents);
                type = cell_type::Value;
            }
            catch (...) {
                type = cell_type::Text;
            }
        }
    }

    // Operator overloading for setting a cell equal to another.
    cell& operator=(const cell& c) {
        if (this != &c) {
            type = c.type;
            contents = c.contents;
            value = c.value;
        }
        return *this;
    }

    // Comparison '==' overloading
    bool operator==(const cell& c) const {
        if (value == c.value) {
            return true;
        }
        return false;
    }

    // Comparison '!=' overloading
    bool operator!=(const cell& c) const {
        if (value == c.value) {
            return false;
        }
        return true;
    }

    // Comparison '>' overloading
    bool operator>(const cell& c) const {
        if (value > c.value) {
            return true;
        }
        return false;
    }

    // Comparison '>=' overloading
    bool operator>=(const cell& c) const {
        if (value > c.value || value == c.value) {
            return true;
        }
        return false;
    }

    // Comparison '<' overloading
    bool operator<(const cell& c) const {
        if (value < c.value) {
            return true;
        }
        return false;
    }

    // Comparison '<=' overloading
    bool operator<= (const cell& c) const {
        if (value < c.value || value == c.value) {
            return true;
        }
        return false;
    }

    // Helper function to see if two cells are the same type. Returns type bool.
    [[nodiscard]] bool same(const cell& operand) const {
        if (type == operand.type) {
            return true;
        }
        return false;
    }

    // Prints elements of a cell, separated by vertical bars '|'. Type void.
    void info() const {
        std::string typestring;

        if (type == cell_type::Empty) {
            typestring = "Type: Empty";
        } else if (type == cell_type::Text) {
            typestring = "Type: Text";
        } else if (type == cell_type::Value) {
            typestring = "Type: Value";
        } else if (type == cell_type::Expression) {
            typestring = "Type: Expression";
        }

        std::cout << "|" << "'" << typestring << "'";
        std::cout << "'" << contents << "'";
        std::cout << "'" << value << "'" << "|";
    }

    // TODO add validate function to reassign cell type based on current content.
};
// Use this class to convert 'A1' to valid index for sheet vector
struct cell_address {
    int col_dex;
    int row_dex;

    // Constructs an address from "A1", "B22" etc.
    // See 'is_valid_syntax()' in spreadsheet to validate.
    explicit cell_address(std::string address) {
        // map to check char and "convert" it to int.
        // TODO expand later if I want double chars 'AA1', 'AB10' etc
        std::map<char, int> position_index {
                {'A', 0},
                {'B', 1},
                {'C', 2},
                {'D', 3},
                {'E', 4},
                {'F', 5},
                {'G', 6},
                {'H', 7},
                {'I', 8},
                {'J', 9},
                {'K', 10},
                {'L', 11},
                {'M', 12},
                {'N', 13},
                {'O', 14},
                {'P', 15},
                {'Q', 16},
                {'R', 17},
                {'S', 18},
                {'T', 19},
                {'U', 20},
                {'V', 21},
                {'W', 22},
                {'X', 23},
                {'Y', 24},
                {'Z', 25}
        };
        col_dex = position_index[address.front()];
        address.erase(0, 1);
        // Minus 1 for accurate index position
        row_dex = std::stoi(address) - 1;
    }

    // Converts a cell's sheet index '[column][row]' to a cell address. Accepts two integers. returns type cell_address.
    static cell_address index_to_address(const int c, const int r) {
        std::map<int, char> char_index {
                {0, 'A'},
                {1, 'B'},
                {2, 'C'},
                {3, 'D'},
                {4, 'E'},
                {5, 'F'},
                {6, 'G'},
                {7, 'H'},
                {8, 'I'},
                {9, 'J'},
                {10, 'K'},
                {11, 'L'},
                {12, 'M'},
                {13, 'N'},
                {14, 'O'},
                {15, 'P'},
                {16, 'Q'},
                {17, 'R'},
                {18, 'S'},
                {19, 'T'},
                {20, 'U'},
                {21, 'V'},
                {22, 'W'},
                {23, 'X'},
                {24, 'Y'},
                {25, 'Z'}
        };

        // Defines column and row, then concatenates them into a new string.
        const char cell_column = char_index[c];
        // Plus 1 for accurate row number
        const int cell_row = r + 1;
        const std::string address_string = cell_column + std::to_string(cell_row);

        // Defines a cell address from the string and returns it.
        const cell_address address(address_string);
        return address;
    }
};
#endif //BASIC_SPREADSHEET_CELL_TYPE_H