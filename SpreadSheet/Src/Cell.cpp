#include "../Headers/Cell.h"

Cell::operator int(){
    return std::stoi(storage);
}

Cell::operator double(){
    return std::stod(storage);
}

Cell::operator std::string(){
    return static_cast<Cell>(storage);
}

Cell::Cell(int v) {
    storage = v;
}

Cell::Cell(double d){
    storage = d; 
}

Cell::Cell(std::string s){
    storage = s;
}

Cell::Cell(Cell&& rhv) 
: storage(std::move(rhv.storage))

{}

Cell::Cell() 
:  storage{""}

{}


Cell::Cell(const Cell& rhv) 
: storage{rhv.storage} 
{}


const Cell& Cell::operator=(const Cell& rhv){
    if (this != &rhv){
        storage = rhv.storage;
    }
    return *this; 
}

const Cell& Cell::operator=(Cell&& rhv){
    if (this != &rhv){
        storage = std::move(rhv.storage);
    
    }
    return *this;     
}

Cell::~Cell() noexcept {}


std::ostream& operator<<(std::ostream& os , const Cell& rhv){
    os << rhv.getValue();
    return os; 
}

std::istream& operator>>(std::istream& is , Cell& rhv){
    is >> rhv.storage;
    return is; 
}

