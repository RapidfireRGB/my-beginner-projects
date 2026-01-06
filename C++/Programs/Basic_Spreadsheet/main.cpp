#include <iostream>
//#include "src/cell_type.h"
#include "src/grid.h"
//#include "src/commands.h"
#include <string>

int main() {
    int user_c;
    int user_r;

    // user-defined dimensions for a spreadsheet
    std::cout << "Define the columns of a spreadsheet: \n";
    std::cin >> user_c;

    std::cout << "Define the rows of a spreadsheet: \n";
    std::cin >> user_r;

    spreadsheet user_sheet(user_c, user_r);

    // check if user wants to do input
    char response;
    std::cout << "Do you want to input a value to a cell?\n";
    std::cin >> response;

    if (response == 'y') {
        // accept string 'A1', 'B5' etc
        std::string user_cell_address;
        std::cout << "Which cell?\n";
        std::cin >> user_cell_address;

        // early termination
        if (!user_sheet.has_cell(user_cell_address)
            || !user_sheet.is_valid_syntax(user_cell_address)) {
            std::cout << "That cell doesn't exist or was not typed correctly.\n";
            return 0;
        }

        // accept string to write to specified cell's contents.
        std::string cell_contents;
        std::cout << "Enter cell contents: \n";
        std::cin >> cell_contents;


    }

    // Linebreak for readability
    std::cout << "\n\n";



    // print spreadsheet
    user_sheet.cells();
    return 0;
}