#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <vector> 

template<typename T>

class stack {
private:
     std::vector<T> ob;
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
 ~stack() noexcept;
 const stack& operator=(const stack<T>&);
 const stack& operator=(stack<T>&&);
 stack(std::initializer_list<T>);
 void push(const_referance );
 void pop();
 public:
 referance top();
 size_type size() const;
 void _swap(stack&);
 bool empty();
 
 referance operator[](size_type index);

};

template<typename T>
bool operator<( stack<T>& lhs,  stack<T>& rhs);

template<typename T>
bool operator<=( stack<T>& lhs, stack<T>& rhs);

template<typename T>
bool operator>( stack<T>& lhs, stack<T>& rhs);

template<typename T>
bool operator>=( stack<T>& lhs, stack<T>& rhs);

template<typename T>
bool operator==( stack<T>& lhs, stack<T>& rhs);

template<typename T>
bool operator!=( stack<T>& lhs,  stack<T>& rhs);

template<typename T>
std::ostream& operator<<(std::ostream& os , stack<T>& rhv);



#include "Stack.cpp"

#endif //  __STACK_H__

