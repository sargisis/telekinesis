#include "Vector.h"

int main() {
    g3::vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    a.push_back(55);
    // a.insert(a.cbegin() + 5, {1,2,3,4,5}); // rebuild all insert 
    for (auto it = a.cbegin(); it != a.cend(); ++it) {
        std::cout << *it << " " << std::endl;  
    }

}