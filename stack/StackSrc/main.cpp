#include "../StackHeader/Stack.h"

int main() {
    stack<int> s;
    s.push(55);
    std::cout << s << std::endl; 
    // don't check this code this code give you segmentation fault 
    // I don't know how fix this error 
    // s.push(55);
}
