#ifndef BASIC_SPREADSHEET_GRID_H
#define BASIC_SPREADSHEET_GRID_H

#include "cell_type.h"
#include <vector>
#include <string>
#include <array>
#include <algorithm>
#include <cctype>

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

    // Returns the cell at a specific [column][row] position.
    // TODO see if operator overloading is possible instead.
    [[nodiscard]] cell at(const int c, const int r) const {
        return sheet[c][r];
    }

    // Helper function to check if a cell position is typed correctly. Returns type bool.
    static bool is_valid_syntax(const std::string& cell_position) {
        // Must have at least one char and at least one int; anything less is invalid.
        if (cell_position.length() < 2) {
            return false;
        }

        // If string to int conversion raises an error, return false.
        // TODO when sheet exceeds 99x99 cells, this block must be updated.
        try {
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
        catch (...) {
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

    // TODO add function to evaluate 'A1 + B1' etc
    // TODO add validation for expressions somewhere.

    // ex "A1 + B2"
    // ex "B7 - C10"
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
        if (cell_argument.find('+') != cell_argument.npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            + at(cell_2.col_dex, cell_2.row_dex).value;

        } else if (cell_argument.find('-') != cell_argument.npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            - at(cell_2.col_dex, cell_2.row_dex).value;

        } else if (cell_argument.find('*') != cell_argument.npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            * at(cell_2.col_dex, cell_2.row_dex).value;

        } else if (cell_argument.find('/') != cell_argument.npos) {
            new_cell.value = at(cell_1.col_dex, cell_1.row_dex).value
            / at(cell_2.col_dex, cell_2.row_dex).value;
        }

        return new_cell;
    }

};



#endif //BASIC_SPREADSHEET_GRID_H