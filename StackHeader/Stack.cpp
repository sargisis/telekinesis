#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "Stack.h"

template<typename T , typename Container>

stack<T,Container>::stack() 
{} 

template<typename T , typename Container>
stack<T,Container>::stack(const stack& rhv) 

{
    ob = rhv.ob;
}

template<typename T , typename Container>
stack<T,Container>::stack(stack&& rhv) 

{
    ob = std::move(rhv.ob);
}

template<typename T , typename Container>
stack<T,Container>::~stack() {}

template<typename T , typename Container>
stack<T,Container>::stack(std::initializer_list<T> initlist)
   
{
    for(const T& val : initlist){
        push(val);
    }
}

template<typename T , typename Container>
const stack<T,Container>& stack<T,Container>::operator=(const stack& rhv){
    if (this != &rhv){
        
          for (const T& val : rhv){
              ob = rhv.ob;
          }
    }
     return *this; 
}

template<typename T , typename Container>
const stack<T,Container>& stack<T,Container>::operator=(stack&& rhv){
        if (this != &rhv){

            for (const T& val : rhv){
                ob = std::move(rhv.ob);
            }
        }
    return *this; 
}
template<typename T , typename Container>
stack<T,Container>::referance stack<T,Container>::top(){
    return ob.back();
}

template<typename T , typename Container>
void stack<T,Container>::swap(const stack& rhv){
     std::swap(ob , rhv.ob);
}

template<typename T , typename Container>
bool stack<T,Container>::empty() {
     return ob.size();
}


template<typename T , typename Container>
stack<T,Container>::size_type& stack<T,Container>::size(){
    return ob.size();
}

template<typename T , typename Container>
void stack<T,Container>::push(const_referance elem){
    ob.push_back(elem);
}

template<typename T , typename Container>
void stack<T,Container>::pop(){
    return ob.pop_back();
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator<(const stack<T,Container> lhs, const stack<U,Container> rhs){
    return compare(lhs, rhs) < 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator>(const stack<T,Container> lhs, const stack<U,Container> rhs){
    return compare(lhs, rhs) > 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator<=(const stack<T,Container> lhs, const stack<U,Container> rhs){
    return compare(lhs, rhs) <= 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator>=(const stack<T,Container> lhs, const stack<U,Container> rhs){
    return compare(lhs, rhs) >= 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator==(const stack<T,Container> lhs, const stack<U,Container> rhs){
    return compare(lhs, rhs) == 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator!=(const stack<T,Container> lhs, const stack<U,Container> rhs){
    return compare(lhs, rhs) != 0;
}

#endif // 