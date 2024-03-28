#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "Stack.h"

template<typename T>
stack<T>::stack()  
   
{}

template<typename T>
stack<T>::stack(const stack& rhv)  
 : stack()
{
    this->ob = rhv.ob;
}

template<typename T>
stack<T>::stack(stack&& rhv) 
    : stack()
{
    this->ob = std::move(rhv.ob);
}

template<typename T>
stack<T>::~stack() noexcept 
{}

template<typename T>
stack<T>::stack(std::initializer_list<T> initlist)        
{
    for(const T& val : initlist){
        this->ob.push_back(val);
    }
}
template<typename T>
const stack<T>& stack<T>::operator=(const stack& rhv){
    if (this != &rhv){
        ob = rhv.ob;
    }
    return *this; 
}

template<typename T>
const stack<T>& stack<T>::operator=(stack&& rhv){
    if (this != &rhv){
        ob = std::move(rhv.ob);
    }
    return *this; 
}

template<typename T>
stack<T>::referance stack<T>::top(){
   
    return ob.back();
}

template<typename T>
void stack<T>::_swap(const stack& rhv){
    std::swap(ob , rhv.ob); // Here is error
}

template<typename T>
bool stack<T>::empty() {
    return !ob.empty();
}

template<typename T>
stack<T>::size_type stack<T>::size() const {
    return ob.size();
}

template<typename T>
void stack<T>::push(const_referance elem){
    ob.push_back(elem);
}

template<typename T>
void stack<T>::pop(){
    if (!ob.empty()) {
        ob.pop_back();
    }
}

template<typename T>
stack<T>::referance stack<T>::operator[](size_type index) {
    return ob[index];
}

template<typename T>
bool operator<( stack<T>& lhs,  stack<T> &rhs){
     return lhs.size() < rhs.size(); 
}

template<typename T>
bool operator<=( stack<T>& lhs,  stack<T>& rhs){
     return lhs.size() <= rhs.size();
}

template<typename T>
bool operator>( stack<T>& lhs,  stack<T>& rhs){
    return  lhs.size() > rhs.size();
}

template<typename T>
bool operator>=( stack<T>& lhs,  stack<T>& rhs){
    return lhs.size() >= rhs.size();
}

template<typename T>
bool operator==( stack<T>& lhs,  stack<T>& rhs){
    return lhs.size() == rhs.size();     
}

template<typename T>
bool operator!=( stack<T>& lhs,  stack<T>& rhs){
    return lhs.size() != rhs.size();
}

template<typename T>
std::ostream& operator<<(std::ostream& os , stack<T>& rhv){
    for (size_t i = 0; i < rhv.size(); ++i){
        os << rhv[i] << " ";
    }
    return os; 
}


#endif // STACK_HPP__
