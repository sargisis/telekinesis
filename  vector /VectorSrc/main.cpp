#include "Vector.h"
#include <iostream>

int main() {
     g3::vector<int> a = {1,2,3,4,5,6};
     for (auto it = a.crbegin(); it != a.crend(); ++it) {
        std::cout << *it << " " << std::flush;
     }
     std::cout << std::endl; 
    std::cout << "Insert vector " << std::endl;  
     a.insert(a.cbegin() + 2 , {10,20,30,40,50}); 
        for (auto it = a.cbegin(); it != a.cend(); ++it) {
        std::cout << *it << " " << std::flush; 
     }
    std::cout << "after insert vector " << std::endl;

    std::cout << "Erase this vector full"  << std::endl; 
    a.erase(a.cbegin() , a.cend());
    for (auto it = a.cbegin(); it != a.cend(); ++it) {
        std::cout << *it << " " << std::endl; 
    }

    std::cout << "New vector " << std::endl; 
    g3::vector<int> a1 = {1,2,3,4,5,6};
    for (auto it = a1.cbegin(); it != a1.cend(); ++it) {
        std::cout << *it << " " << std::flush;
    }
    std::cout << std::endl; 

    std::cout << "Add new elements " << std::endl; 
    a1.insert(a1.cbegin(), 5,33);
    for (auto it = a1.cbegin(); it != a1.cend(); ++it) {
        std::cout << *it << " " << std::flush;
    }
    std::cout << std::endl; 
    std::cout << "Ereased this vector " << std::endl; 
    a1.erase(a1.cbegin(), a1.cend());
    for (auto it = a1.cbegin(); it != a1.cend(); ++it) {
        std::cout << *it << " " << std::flush;
    }

}
