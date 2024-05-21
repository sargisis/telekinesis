#include <iostream>
#include "../Headers/SpreadSheet.h" 

std::ostream& operator<<(std::ostream& out, const SpreadSheet& ob) {
    int width = 8; 
    double width_table = ob.col() * 9.1; 
    int h_line = 1;
    for (size_t i = 0; i < ob.row(); ++i) {
        for (size_t k = 0; k < width_table; ++k) {
            out << std::setw(1) << "-";
        }
        out << std::endl; 
        for (size_t j = 0; j < ob.col(); ++j) {
            out << std::setw(h_line) << "|" << std::setw(width) << std::left << ob.board_()[i][j];
        }
        out << std::setw(h_line) << "|";
        out << std::endl; 
    }

    for (size_t k = 0; k < width_table; ++k) {
        out << std::setw(1) << "-";
    }
    out << std::endl; 
    return out; 
}

int main() {
    // Create a 3x3 spreadsheet
    SpreadSheet sheet(3, 3);

    // Fill the spreadsheet with some values
    sheet[0][0] = Cell("A1");
    sheet[0][1] = Cell("B1");
    sheet[0][2] = Cell("C1");
    sheet[1][0] = Cell("A2");
    sheet[1][1] = Cell("B2");
    sheet[1][2] = Cell("C2");
    sheet[2][0] = Cell("A3");
    sheet[2][1] = Cell("B3");
    sheet[2][2] = Cell("C3");

    // Print the original spreadsheet
    std::cout << "Original Spreadsheet:" << std::endl;
    std::cout << sheet << std::endl;

    // Test mirroring horizontally
    sheet.mirrorH();
    std::cout << "Horizontally Mirrored Spreadsheet:" << std::endl;
    std::cout << sheet << std::endl;

    // Test mirroring vertically
    sheet.mirrorV();
    std::cout << "Vertically Mirrored Spreadsheet:" << std::endl;
    std::cout << sheet << std::endl;

    // Test rotating the spreadsheet
    sheet.rotate(1);
    std::cout << "Rotated Spreadsheet (90 degrees):" << std::endl;
    std::cout << sheet << std::endl;

    // Test removing a row
    sheet.removeRow(1);
    std::cout << "Spreadsheet after removing row 1:" << std::endl;
    std::cout << sheet << std::endl;

    // Test removing a column
    sheet.removeCol(1);
    std::cout << "Spreadsheet after removing column 1:" << std::endl;
    std::cout << sheet << std::endl;

    // Test resizing the spreadsheet
    sheet.resize(2, 2);
    std::cout << "Resized Spreadsheet (2x2):" << std::endl;
   std::cout << sheet << std::endl;

    return 0;
}