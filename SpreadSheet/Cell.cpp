#include "../Headers/Cell.h"

Cell::operator int(){
    return std::stoi(storage);
}

Cell::operator double(){
    return std::stod(storage);
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
    
        rhv.storage = nullptr;
    }
    return *this;     
}

Cell::~Cell() noexcept {}


std::ostream& operator<<(std::ostream& os , const Cell& rhv){
   
    os << (rhv);
    return os; 
}

std::istream& operator>>(std::istream& os , Cell& rhv){
    os >> (rhv);
    return os; 
}

