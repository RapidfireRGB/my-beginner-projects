#ifndef BASIC_SPREADSHEET_METHODS_H
#define BASIC_SPREADSHEET_METHODS_H

// Backup of previous method of spreadsheet class ---------------------------------
    // Takes char 'A1', 'C5' etc and translates that into index position of a cell.
    // TODO revise and set return type.
    [[nodiscard]] cell char_column_index(const std::string& cell_position) const {
        const char letter = cell_position.front();
        int number = std::stoi(&cell_position[1]);

        // If length is greater than 2, create a new string without the first char and set number equal to that string.
        if (cell_position.length() > 2) {
            std::string temp = cell_position;
            temp.erase(0);
            number = std::stoi(temp);
            //~temp();
        }


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

        // Subtract 1 here to fetch index position
        return sheet[position_index[letter]][number-1];
    }
// ---------------------------------------------------------------------------------
#endif //BASIC_SPREADSHEET_METHODS_H