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
    Cell(Cell&& rhv);
    Cell(const Cell& rhv);
    const Cell& operator=(const Cell& rhv);
    const Cell& operator=(Cell&& rhv);
    

    ~Cell() noexcept;
};
std::ostream& operator<<(std::ostream& os , const Cell& rhv);
std::istream& operator>>(std::istream& os ,  Cell& rhv);



#endif //