#include "../VectorHeader/Vector.hpp"
#include <iostream>


int main() {
    Vector<int> v = {1, 2, 3, 4, 5};
    
    v.push_back(33);
    std::cout << v.Size() << std::endl; 
    std::cout<<"Capacity"<< v.Capacity() << std::endl;
    auto it = v.end();
    std::cout << *it << std::endl; 
    std::cout << v.back() << std::endl; 
    
    

}

    
