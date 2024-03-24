#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>

template<typename T , typename Container = std::vector<T>>

class stack {
private:
     Container ob;
public:
  using value_type = T;
  using size_type = std::size_t;
  using referance = value_type&;
  using const_referance = const value_type&;
  using pointer = value_type*;
  using const_pointer = const value_type*;
public:
 stack();
 stack(const stack&);
 stack(stack&&);
 ~stack();
 const stack& operator=(const stack<T,Container>&);
 const stack& operator=(stack<T,Container>&&);
 stack(std::initializer_list<T>);
 void push(const_referance);
 void pop();
 public:
 value_type& top();
 size_type& size();
 void swap(const stack&);
 bool empty();
 
};

template<typename T , typename Container = std::vector<T> , typename U>
bool operator<(const stack<T,Container> lhs, const stack<U,Container> rhs);

template<typename T , typename Container = std::vector<T> , typename U>
bool operator<=(const stack<T,Container> lhs, const stack<U,Container> rhs);

template<typename T , typename Container = std::vector<T> , typename U>
bool operator>(const stack<T,Container> lhs, const stack<U,Container> rhs);

template<typename T , typename Container = std::vector<T> , typename U>
bool operator>=(const stack<T,Container> lhs, const stack<U,Container> rhs);

template<typename T , typename Container = std::vector<T> , typename U>
bool operator==(const stack<T,Container> lhs, const stack<U,Container> rhs);

template<typename T , typename Container = std::vector<T> , typename U>
bool operator!=(const stack<T,Container> lhs, const stack<U,Container> rhs);

#include "Stack.cpp"

#endif //  __STACK_H__

