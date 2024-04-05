#include <iostream>
#include "../Headers/SpreadSheet.h" // Assuming SpreadSheet.h contains the SpreadSheet class definition

int main() {
    // Create a new spreadsheet with 3 rows and 4 columns
    SpreadSheet table(5,5);

    // Add some data to the table
    
    table.add_colum(3,3,"Hi");
    table.add_row(2,3,"Hi");
    table.delete_colum(2);
    table.delete_row(1);
    table.resize_row(2);
    table.resize_colum(2);
    table.resize(2,3);
    
    // Print the table
    table.print();

    return 0;
}
