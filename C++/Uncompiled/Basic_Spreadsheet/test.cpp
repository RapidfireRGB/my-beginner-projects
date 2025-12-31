//#include <iostream>
#include "src/cell_type.h"
#include "src/grid.h"


spreadsheet sheet_1(10, 10);
cell cell_1;

int main() {
    cell_1.value = 10.5;
    cell_1.contents = "Hello World";
    cell_1.type = cell_type::Expression;
    cell_1.info();
    return 0;
}