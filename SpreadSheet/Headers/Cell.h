#ifndef __CELL_H_
#define __CELL_H_

#include <iostream>
#include <string>
#include <ostream>
#include <istream>

class Cell {
private:
    std::string storage; 
public:
    Cell();
    operator int();
    operator double();
    operator std::string();
    Cell(Cell&& rhv);
    Cell(const Cell& rhv);
    const Cell& operator=(const Cell& rhv);
    const Cell& operator=(Cell&& rhv);
    Cell(int v); 
    Cell(double d);
    Cell(std::string s);
    std::string getValue() const {
        return storage;
    }
    
   friend std::istream& operator>>(std::istream &is , Cell& rhv);
    ~Cell() ;
};
std::ostream& operator<<(std::ostream& os , const Cell& rhv);
std::istream& operator>>(std::istream& os ,  Cell& rhv);



#endif //