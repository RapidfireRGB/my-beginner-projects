#ifndef BASIC_SPREADSHEET_GRID_H
#define BASIC_SPREADSHEET_GRID_H

#include "cell_type.h"
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <cctype>
#include <map>

struct spreadsheet {
    std::vector<std::vector<cell>> sheet;
    int column;
    int row;

    // Define dimensions of a sheet. Also resizes the vector.
    spreadsheet(const int c, const int r) : column(c), row(r) {
        // TODO do proper 2d vector resizing with a for loop
        sheet.resize(c);

        // This should correctly resize the vector.
        for (int i = 0; i < c; i++) {
            sheet[i].resize(r);
        }
    }

    // TODO add validation for expressions somewhere.

    // Returns the cell at a specific [column][row] position.
    // TODO see if operator overloading is possible instead.
    [[nodiscard]] cell at(const int c, const int r) const {
        return sheet[c][r];
    }

    // TODO maybe move this to cell_address class
    // Helper function to check if a cell position is typed correctly. Returns type bool.
    static bool is_valid_syntax(const std::string& cell_position) {
        // Must have at least one char and at least one int; anything less is invalid.
        if (cell_position.length() < 2) {
            return false;
        }

        // If string to int conversion raises an error, return false.
        // TODO when sheet exceeds 99x99 cells, this block must be updated.
        try {
            // Creates a temporary copy of original string to check length after first char has been erased.
            std::string temp = cell_position;
            temp.erase(0,1);

            // If there are more than 3 total chars, return false.
            // "A100" = false;  "A10B" = false;  "B25" = function continues
            if (temp.length() > 2) {
                return false;
            }

            // If this line raises an error, return false. Else, function continues.
            std::stoi(temp);
        }
        catch (std::invalid_argument) {
            return false;
        }

        // If a valid char is found, return true.
        for (int i = 0; i <= 25; i++) {
            constexpr std::array<char, 26> valid_chars = {
                'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
            };
            if (cell_position[0] == valid_chars[i]) {
                return true;
            }
        }
        // If for loop completes without finding a match, return false.
        return false;
    }

    // TODO test this entire function
    // TODO maybe refactor this into separate functions; one that returns cell_address and one that does arithmetic
    [[nodiscard]] cell evaluate_expression(std::string cell_argument) const {

        // Defines two separate strings, which are the operands within an expression.
        // Used to fetch cell index positions.
        std::string first_operand;
        std::string second_operand;

        // Defines a new cell. Assumes cell_type::Expression. Sets contents equal to string parameter.
        // If operations can be performed, set value equal to new value after operations have been done,
        // Else, return an empty cell.
        cell new_cell;
        new_cell.type = cell_type::Expression;
        new_cell.contents = cell_argument;

        // Erase whitespace from initial string.
        cell_argument.erase(
            std::remove_if(
                cell_argument.begin(),
                cell_argument.end(), ::isspace),
                cell_argument.end());

        // Erase '='; should be left with 'A1+B2' at this point
        cell_argument.erase(0, 1);

        // TODO revisit this; find a better method
        // put a try for here to check each operation
        try {
            // When an operation is found, everything to the left becomes first_operand.
            // Everything to the right of the operator become second_operand.
            for (size_t i = 0; i <= 3; i++) {
                constexpr std::array<char, 4> operations {
                    '+', '-', '*', '/'
                };

                first_operand = cell_argument.substr(
                    0,
                    cell_argument.find(operations[i]));

                second_operand = cell_argument.substr(
                    cell_argument.find(operations[i]),
                    cell_argument.length() - first_operand.length());
            }
        } catch (...) {
            // do something if no operation found
        }

        // If either substring is not a valid cell_address, return an empty cell. Else, function continues.
        if (!is_valid_syntax(first_operand)
            || !is_valid_syntax(second_operand)) {
            new_cell.clear();
            return new_cell;
        }

        // Construct a cell address, retrieve the index, then perform operations with the cell's value.
        const cell_address cell_1(first_operand);
        const cell_address cell_2(second_operand);

        // Checks whether operator chars exist in cell_argument and does appropriate arithmetic with cell values.
        if (cell_argument.find('+') != std::string::npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            + at(cell_2.col_dex, cell_2.row_dex).value;

        } else if (cell_argument.find('-') != std::string::npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            - at(cell_2.col_dex, cell_2.row_dex).value;

        } else if (cell_argument.find('*') != std::string::npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            * at(cell_2.col_dex, cell_2.row_dex).value;

        } else if (cell_argument.find('/') != std::string::npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            / at(cell_2.col_dex, cell_2.row_dex).value;
        }

        return new_cell;
    }

    // Checks if a string cell position exists in a sheet. Returns type bool.
    [[nodiscard]] bool has_cell(const std::string& cell_position) const {

        // First, checks if the string has valid syntax. If not, return false. Else, function continues.
        if (!is_valid_syntax(cell_position)) {
            return false;
        }

        const cell_address target_cell(cell_position);

        try {
            // If this cell is out of range, return false. Else, return true.
            cell range_check = sheet.at(target_cell.col_dex).at(target_cell.row_dex);

        } catch (const std::out_of_range&) {
            return false;
        }
        return true;
    }

    // Converts a cell's sheet index '[column][row]' to a cell address. Accepts two integers. returns type cell_address.
    [[nodiscard]] cell_address index_to_address(const int c, const int r) {
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
        const int cell_row = r + 1;
        const std::string address_string = cell_column + std::to_string(cell_row);

        // Defines a cell address from the string and returns it.
        const cell_address address(address_string);
        return address;
    }

    // Prints whitespace separated columns and linebreak separated rows representing sheet contents. Type void.
    // Displays cells by their respective cell address 'A1' etc
    void cells() {
        // insert cell address to string conversion. then input string to has_cell() within for loop.
        for (int i = 0; i <= sheet.size(); i++) {
            // insert conversion from cell index to cell address string here

        }
    }

};

#endif //BASIC_SPREADSHEET_GRID_H