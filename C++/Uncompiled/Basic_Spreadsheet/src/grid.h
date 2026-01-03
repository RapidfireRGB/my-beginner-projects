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
        sheet.resize(c);

        // This should correctly resize the vector.
        for (int i = 0; i < c; i++) {
            sheet[i].resize(r);
        }
    }

    // TODO add validation for expressions somewhere.

    // Returns the cell at a specific [column][row] position.
    [[nodiscard]] cell at(const int c, const int r) const {
        return sheet[c][r];
    }

    // Alternatively, use operator overloading (EX: sheet_name[column][row])
    std::vector<cell>& operator[](const int col) {
        return sheet[col];
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
        catch (std::invalid_argument&) {
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

    // TODO debug this
    // TODO maybe refactor this into separate functions; one that returns cell_address and one that does arithmetic
    [[nodiscard]] cell evaluate_expression(std::string cell_argument) const {

        // Defines two separate strings, which are the operands within an expression.
        // Used to fetch cell index positions.
        std::string first_operand;
        std::string second_operand;

        // Defines a new cell. Assumes cell_type::Expression. Sets contents equal to string parameter.
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

        // TODO THIS IS ALWAYS THROWING std::out_of_range
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
            first_operand = cell_argument.substr(0, 2);
            second_operand = cell_argument.substr(3, 2);
        }

        // If either substring is not a valid cell_address, return an empty cell. Else, function continues.
        if (!is_valid_syntax(first_operand)
            || !is_valid_syntax(second_operand)) {
            new_cell.clear();
            return new_cell;
        }
        // TODO remove after debugging
        std::cout << first_operand;
        std::cout << second_operand;

        // Construct a cell address, retrieve the index, then perform operations with the cell's value.
        const cell_address cell_1(first_operand);
        const cell_address cell_2(second_operand);
        // TODO remove after debugging
        std::cout << cell_1.col_dex;
        std::cout << cell_1.row_dex;
        std::cout << cell_2.col_dex;
        std::cout << cell_2.row_dex;

        // If operations can be performed, set value equal to new value after operations have been done,
        // Checks whether operator chars exist in cell_argument and does appropriate arithmetic with cell values.
        if (cell_argument.find('+') != std::string::npos) {
            new_cell.value = sheet[cell_1.col_dex][cell_1.row_dex].value
            + sheet[cell_2.col_dex][cell_2.row_dex].value;

        } else if (cell_argument.find('-') != std::string::npos) {
            new_cell.value = sheet[cell_1.col_dex][cell_1.row_dex].value
            - sheet[cell_2.col_dex][cell_2.row_dex].value;

        } else if (cell_argument.find('*') != std::string::npos) {
            new_cell.value = sheet[cell_1.col_dex][cell_1.row_dex].value
            * sheet[cell_2.col_dex][cell_2.row_dex].value;

        } else if (cell_argument.find('/') != std::string::npos) {
            new_cell.value = sheet[cell_1.col_dex][cell_1.row_dex].value
            / sheet[cell_2.col_dex][cell_2.row_dex].value;
        }
        // TODO remove after debugging
        std::cout << new_cell.value;
        new_cell.info();

        // TODO this is not returning for some reason
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

    // Prints a sheet's cells separated by whitespace
    void cells() const {
        for (int c = 0; c <= sheet.size(); c++) {
            for (int r = 0; r <= sheet.size(); r++) {
                sheet[c][r].info();
                std::cout << " ";
            }
        }
    }
};

#endif //BASIC_SPREADSHEET_GRID_H