#include "../Headers/Cell.h"

std::ostream& operator<<(std::ostream& out , const std::vector<int>& ob) {
    for (auto& i : ob) {
        out << i << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in , std::vector<int>& ob) {
    ob.clear();
    int var = 0; 
    while (in >> var) {
        ob.push_back(var);
    }
    return in;
}

Cell::Cell() 
 : value{""}
{}

Cell::Cell(const Cell& rhv) 
    : value{rhv.value}
{}

Cell::Cell(Cell&& rhv) 
    : value{std::move(rhv.value)}
{}

Cell::Cell(int val) 
    : value{std::to_string(val)}
{}

Cell::Cell(double val) 
    : value{std::to_string(val)}
{}

Cell::Cell(char val) 
    : value(std::to_string(val))
{}

Cell::Cell(bool val) 
{  
    std::stringstream ss;
    ss << std::boolalpha << val;
    value = ss.str();
}

Cell::Cell(std::string val) {
    value = val; 
}

Cell::Cell(const std::vector<int>& val){
    std::stringstream word;
    for (const auto& elem : val) {
        word << elem << ' '; 
    }
    value = word.str();
}

const Cell& Cell::operator=(const Cell& rhv) {
    if  (this != &rhv) {
        value = rhv.value;
    }
    return *this; 
}

const Cell& Cell::operator=(Cell&& rhv) {
    if (this != &rhv) {
        value = std::move(rhv.value);
    }
    return *this; 
}

const Cell& Cell::operator=(int rhv) {
    value = std::to_string(rhv);
    return *this; 
}

const Cell& Cell::operator=(double rhv) {
    value = std::to_string(rhv);
    return *this; 
}

const Cell& Cell::operator=(char rhv) {
    value = std::to_string(rhv);
    return *this; 
}

const Cell& Cell::operator=(bool rhv) {
    value = (rhv == true) ? "false" : "true";
    return *this; 
}

const Cell& Cell::operator=(std::string rhv) {
    value = rhv;
    return *this; 
}

const Cell& Cell::operator=(const std::vector<int>& rhv) {
    std::stringstream word; 
    for (const auto& elem : rhv) {
        word << elem << " ";
    }
    value = word.str();
    return *this; 
}

Cell::operator int() const {
    return std::stoi(value);
}

Cell::operator double() const {
    return std::stod(value);
}

Cell::operator char() const {
    return value[0];
}

Cell::operator bool() const {
    return !value.empty();
}

Cell::operator std::string() const {
    return value; 
}

Cell::operator std::vector<int>() const {
    std::vector<int> tmp; 
    tmp.push_back(std::stoi(value));
    return tmp; 
}


bool operator==(const Cell& lhv , const Cell& rhv) {

    return (static_cast<std::string>(lhv) == static_cast<std::string>(rhv));
}

bool operator!=(const Cell& lhv , const Cell& rhv) {
    return (static_cast<std::string>(lhv) != static_cast<std::string>(rhv));
}

std::ostream& operator<<(std::ostream& out , const Cell& ob) {
    out << static_cast<std::string>(ob);
    return out; 
}

std::istream& operator>>(std::istream& in , Cell& ob) {
    in >> ob;
    return in;
}