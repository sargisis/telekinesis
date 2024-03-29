#include "../VectorHeader/Vector.hpp"

int main(){
    Vector<int> v = {3,4,2,1,6};
    
   std::cout << v << std::endl; 

    v.insert(3,2);
  std::cout << v << std::endl; 

    v.erase(2);
    v.print();

    v.push_back(44);
    std::cout << v << std::endl; 
    v.pop_back();
    std::cout << v << std::endl; 
    
}