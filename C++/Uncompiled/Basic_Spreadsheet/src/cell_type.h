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

    // TODO need function to perform operations on cells
    // TODO try operator overloading here.
    void add(const cell& operand) {
        if (type == cell_type::Empty
            || type == cell_type::Text
            || operand.type == cell_type::Empty
            || operand.type == cell_type::Text) {
            std::cerr << "You cannot evaluate Strings or Empty Cells.\n";
        }

        value = value + operand.value;

    }

    // TODO revisit these functions.
    //void sub(const cell& operand) {
        //value = value - operand.value;
    //}

    //void mult(const cell& operand) {
        //value = value * operand.value;
    //}

    //void div(const cell operand) {

    //}

    // Operator overloading for setting a cell equal to another.
    cell operator=(const cell& c) const {
        cell new_cell;
        new_cell.contents = c.contents;
        new_cell.value = c.value;
        new_cell.type = c.type;
        return new_cell;
    }



    // Helper function to see if two cells are the same type. Returns type bool.
    // Needed to do operations later.
    [[nodiscard]] bool same(const cell& operand) const {
        if (type == operand.type) {
            return true;
        }
        return false;
    }

    // Prints elements of a cell. Type void. Currently for debugging only.
    void info() const {
        if (type == cell_type::Empty) {
            std::cout << "Type: Empty\n";
        } else if (type == cell_type::Text) {
            std::cout << "Type: Text\n";
        } else if (type == cell_type::Value) {
            std::cout << "Type: Value\n";
        } else if (type == cell_type::Expression) {
            std::cout << "Type: Expression\n";
        } else {
            std::cout << "Type: Unknown\n";
        }
        std::cout << contents << "\n";
        std::cout << value << "\n";
    }

    // TODO add validate function to reassign cell type based on current content.
    // TODO add validation for expression syntax

};
// use this class to convert 'A1' to valid index for sheet vector
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
        row_dex = std::stoi(address);
    }

};
#endif //BASIC_SPREADSHEET_CELL_TYPE_H