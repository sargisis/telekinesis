#ifndef __QUEUE__HPP__
#define __QUEUE__HPP__

#include "Queue.h"


template<typename T , typename Container>

queue<T,Container>::queue() 
{} 

template<typename T , typename Container>
queue<T,Container>::queue(const queue& rhv) 
{
    ob = rhv.ob;
}

template<typename T , typename Container>
queue<T,Container>::queue(queue&& rhv) 

{
    ob = std::move(rhv.ob);
}

template<typename T , typename Container>
queue<T,Container>::~queue() {}

template<typename T , typename Container>
queue<T,Container>::queue(std::initializer_list<T> initlist)
   
{
    for(const T& val : initlist){
        push(val);
    }
}

template<typename T , typename Container>
const queue<T,Container>& queue<T,Container>::operator=(const queue& rhv){
    if (this != &rhv){
        
          for (const T& val : rhv){
              ob = rhv.ob;
          }
    }
     return *this; 
}

template<typename T , typename Container>
const queue<T,Container>& queue<T,Container>::operator=(queue&& rhv){
        if (this != &rhv){

            for (const T& val : rhv){
                ob = std::move(rhv.ob);
            }
        }
    return *this; 
}
template<typename T , typename Container>
queue<T,Container>::referance queue<T,Container>::front(){
    return ob.front();
}

template<typename T , typename Container>
void queue<T,Container>::swap(const queue& rhv){
     std::swap(ob , rhv.ob);
}

template<typename T , typename Container>
bool queue<T,Container>::empty() {
     return ob.size();
}


template<typename T , typename Container>
queue<T,Container>::size_type& queue<T,Container>::size(){
    return ob.size();
}

template<typename T , typename Container>
void queue<T,Container>::push(const_referance elem){
    ob.push_back(elem);
}

template<typename T , typename Container>
void queue<T,Container>::pop(){
    return ob.pop_back();
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator<(const queue<T,Container> lhs, const queue<U,Container> rhs){
    return compare(lhs, rhs) < 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator>(const queue<T,Container> lhs, const queue<U,Container> rhs){
    return compare(lhs, rhs) > 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator<=(const queue<T,Container> lhs, const queue<U,Container> rhs){
    return compare(lhs, rhs) <= 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator>=(const queue<T,Container> lhs, const queue<U,Container> rhs){
    return compare(lhs, rhs) >= 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator==(const queue<T,Container> lhs, const queue<U,Container> rhs){
    return compare(lhs, rhs) == 0;
}

template<typename T , typename Container = std::vector<T> , typename U>
bool operator!=(const queue<T,Container> lhs, const queue<U,Container> rhs){
    return compare(lhs, rhs) != 0;
}

#endif // 
