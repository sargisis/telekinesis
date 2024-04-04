#include "Task1.hpp"

class T{
    public:
    T() {
        std::cout << "Constructor call" << std::endl;
    }
    ~T() {
        std::cout << "Destructor call" << std::endl; 
    }
};

int main() {
    T ob; 
    T* Ival = _new<T>();
    _delete<T>(Ival);

    const size_t size = 3;
    T* arr = _new_in_array<T>(size);
    _delete_in_array<T>(arr , size);

}