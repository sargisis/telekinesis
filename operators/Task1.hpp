#include <iostream>
#include <cstdlib>
#include <stdexcept>


void* operator_new(size_t size){
    void* p = malloc(size);
    if (p == nullptr){
        throw std::bad_alloc();
    }
    return p; 
}

template<typename T>
T* _new() {
    void* p = operator_new(sizeof(T));
    return new(p) T;
}

template<typename T>
T* _new_in_array(size_t size) {
    void* p1 = operator_new(sizeof(T) * size);
    T* arr = static_cast<T*>(p1);
    for (size_t i = 0; i < size; ++i ){
        T();
    }
    return arr;
}



void operator_delete(void *p) noexcept {
    free(p);
}

template<typename T>
void _delete(T* p) noexcept {
    if (p != nullptr) {
        p->~T();
        return operator_delete(p);
    }
}

template<typename T>
void _delete_in_array(T* arr , size_t size){
    if (arr != nullptr ){
        for (size_t i = 0; i < size; ++i){
            arr[i].~T();
        }
        return operator_delete(arr);
    }
    else {
        std::exception();
    }
}

