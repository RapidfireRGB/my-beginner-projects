//#include <iostream>
#include "src/cell_type.h"
#include "src/grid.h"

spreadsheet sheet_1(3, 3);
cell cell_2;

int main() {
    sheet_1[0][0].write("10");
    sheet_1[1][1].write("15");
    sheet_1[2][2].write("=A1+B2");
    cell_2 = sheet_1.evaluate_expression(sheet_1[2][2].contents);
    sheet_1[0][0].info();
    sheet_1[1][1].info();
    cell_2.info();

    return 0;
}