#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <iostream>


template<typename T , typename Container = std::vector<T>>
class queue {
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
 queue();
 queue(const queue&);
 queue(queue&&);
 ~queue();
 const queue& operator=(const queue<T,Container>&);
 const queue& operator=(queue<T,Container>&&);
 queue(std::initializer_list<T>);
 void push(const_referance);
 void pop();
 public:
 value_type& front();
 size_type& size();
 void swap(const queue&);
 bool empty();
 
};

template<typename T , typename Container = std::vector<T>>
bool operator<(const queue<T,Container> lhs, const queue<T,Container> rhs);

template<typename T , typename Container = std::vector<T>>
bool operator<=(const queue<T,Container> lhs, const queue<T,Container> rhs);

template<typename T , typename Container = std::vector<T>>
bool operator>(const queue<T,Container> lhs, const queue<T,Container> rhs);

template<typename T , typename Container = std::vector<T>>
bool operator>=(const queue<T,Container> lhs, const queue<T,Container> rhs);

template<typename T , typename Container = std::vector<T>>
bool operator==(const queue<T,Container> lhs, const queue<T,Container> rhs);

template<typename T , typename Container = std::vector<T>>
bool operator!=(const queue<T,Container> lhs, const queue<T,Container> rhs);

#include "Queue.hpp"

#endif //  __STACK_H__

