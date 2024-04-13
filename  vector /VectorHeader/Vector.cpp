#ifndef VECTOR_CPP
#define VECTOR_CPP
#include "Vector.hpp"

// begin Allocator 
template<typename T>
Vector<T>::pointer Vector<T>::Allocator::allocate(size_type count ) {
    ptr = ::operator new(count);
}

template<typename T>
template<typename... Args>
void Vector<T>::Allocator::constract(pointer ptr , Args... args) {
    std::construct_at(ptr , std::forward<Args>(args)...);
}

template<typename T>
void Vector<T>::Allocator::deallocate(void* ptr , size_type count) 
{
    
}

template<typename T>
template<typename... Args>
void Vector<T>::Allocator::destroy(pointer ptr , Args... args) {
    std::destroy_at(ptr , std::forward<Args>(args)...);
} 

template<typename T>
Vector<T>::size_type Vector<T>::Allocator::max_size() {
    return ptr / sizeof(m_ptr);
}
// begin const_iterator 
template<typename T>
Vector<T>::const_iterator::const_iterator(pointer ptr)
    : p{ptr}
{}

template<typename T>
Vector<T>::const_iterator::const_iterator() 
    : p{nullptr}
{}

template<typename T>
Vector<T>::const_iterator::const_iterator(const const_iterator& rhv)
    : p{rhv.p}
{}

template<typename T>
Vector<T>::const_iterator::const_iterator(const_iterator&& rhv)
    : p{std::move(rhv.p)}
{}

template<typename T>
Vector<T>::const_iterator::~const_iterator() noexcept {
    delete p;
    p = nullptr;
}

template<typename T>
const Vector<T>::const_iterator& Vector<T>::const_iterator::operator=(const const_iterator& rhv) {
    p = rhv.p;

    return *this;  
}

template<typename T>
const Vector<T>::const_iterator& Vector<T>::const_iterator::operator=(const_iterator&& rhv) {
    p = std::move(rhv.p);
    return *this;
}

template<typename T>
Vector<T>::const_referance Vector<T>::const_iterator::operator*() const {
    return *p;
}

template<typename T>
Vector<T>::const_pointer Vector<T>::const_iterator::operator->() const {
    return p; 
}

template<typename T>
const Vector<T>::const_iterator Vector<T>::const_iterator::operator+(size_type val) const {
    const_iterator result = *this; 
    result.p += val; 
    return result; 
}

template<typename T>
const Vector<T>::const_iterator Vector<T>::const_iterator::operator-(size_type val ) const {
    const_iterator result = *this; 
    result.p -= val; 
    return result;
}

template<typename T>
const Vector<T>::const_iterator& Vector<T>::const_iterator::operator-=(size_type val) const {
    p -= val; 
    return *this; 
}

template<typename T>
const Vector<T>::const_iterator& Vector<T>::const_iterator::operator+=(size_type val) const {
    p += val; 
    return *this; 
}

template<typename T>
const Vector<T>::const_iterator& Vector<T>::const_iterator::operator++() {
    ++p; 
    return *this; 
}

template<typename T>
const Vector<T>::const_iterator Vector<T>::const_iterator::operator++(int) {
    int tmp = *this; 
    ++(*this);
    return tmp; 
}

template<typename T>
const Vector<T>::const_iterator& Vector<T>::const_iterator::operator--() {
    --p;
    return *this; 
}

template<typename T>
const Vector<T>::const_iterator Vector<T>::const_iterator::operator--(int) {
    int tmp = *this; 
    --(*this); 
    return tmp; 
}

template<typename T>
Vector<T>::const_referance Vector<T>::const_iterator::operator[](size_type ind) const {
    return p[ind];
}

template<typename T>
bool Vector<T>::const_iterator::operator==(const const_iterator& rhv) const {
    return p == rhv.p;
}

template<typename T>
bool Vector<T>::const_iterator::operator!=(const const_iterator& rhv) const {
    return p != rhv.p;
}

template<typename T>
bool Vector<T>::const_iterator::operator<(const const_iterator& rhv) const {
    return p < rhv.p;
}

template<typename T>
bool Vector<T>::const_iterator::operator<=(const const_iterator& rhv) const {
    return p <= rhv.p;
}

template<typename T>
bool Vector<T>::const_iterator::operator>(const const_iterator& rhv) const {
    return p > rhv.p;
}

template<typename T>
bool Vector<T>::const_iterator::operator>=(const const_iterator& rhv) const {
    return p >= rhv.p;
}
// end const_iterator 

// begin iterator
template<typename T>
Vector<T>::iterator::iterator(pointer ptr) 
  :  p{ptr}
{}

template<typename T>
Vector<T>::iterator::iterator()
    : p{nullptr}
{}

template<typename T>
Vector<T>::iterator::iterator(const iterator& rhv)
    : p{rhv.p}
{}

template<typename T>
Vector<T>::iterator::iterator(iterator&& rhv)
    : p{std::move(rhv.p)}
{}

template<typename T>
Vector<T>::referance Vector<T>::iterator::operator*() {
    return *p;
}

template<typename T>
Vector<T>::pointer Vector<T>::iterator::operator->() {
    return p;
}
// end iterator 

// begin const_reverse_iterator 
template<typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(pointer ptr)
 :  p{ptr}
{}

template<typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator() 
    : p{nullptr}
{}

template<typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(const const_reverse_iterator& rhv) 
    : p{rhv.p}
{}

template<typename T>
Vector<T>::const_reverse_iterator::const_reverse_iterator(const_reverse_iterator&& rhv) 
    : p{std::move(rhv.p)}
{}

template<typename T>
Vector<T>::const_reverse_iterator::~const_reverse_iterator() noexcept
{
    delete p; 
    p = nullptr;
}

template<typename T>
const Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator=(const const_reverse_iterator& rhv) {
    p = rhv.p;
    return *this; 
}

template<typename T>
const Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator=(const_reverse_iterator&& rhv) {
    p = std::move(rhv.p);
    return *this;
}

template<typename T>
Vector<T>::const_referance Vector<T>::const_reverse_iterator::operator*() const {
    return *p;
}

template<typename T>
Vector<T>::const_pointer Vector<T>::const_reverse_iterator::operator->() const {
    return p;
}

template<typename T>
const Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator+(size_type val) const {
   const_reverse_iterator result = *this; 
   result.p += val; 
   return result; 
}

template<typename T>
const Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator-(size_type val) const {
   const_reverse_iterator result = *this; 
   result.p -= val; 
   return result; 
}

template<typename T>
const Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator+=(size_type val) const {
   p+= val;
   return *this;  
}

template<typename T>
const Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator-=(size_type val) const {
   p-= val;
   return *this;  
}

template<typename T>
const Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator++()  {
   ++p; 
   return *this;
}

template<typename T>
const Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator++(int)  {
   int tmp = *this; 
   ++(*this);
   return tmp; 
}

template<typename T>
const Vector<T>::const_reverse_iterator& Vector<T>::const_reverse_iterator::operator--()  {
  --p;
  return *this; 
}

template<typename T>
const Vector<T>::const_reverse_iterator Vector<T>::const_reverse_iterator::operator--(int)  {
  int tmp = *this; 
  --(*this); 
  return tmp;  
}

template<typename T>
Vector<T>::const_referance Vector<T>::const_reverse_iterator::operator[](size_type ind) const {
    return p[ind];
}

template<typename T>
bool Vector<T>::const_reverse_iterator::operator==(const const_reverse_iterator& rhv) const {
    return p == rhv.p;
}

template<typename T>
bool Vector<T>::const_reverse_iterator::operator!=(const const_reverse_iterator& rhv) const {
    return p != rhv.p;
}

template<typename T>
bool Vector<T>::const_reverse_iterator::operator<(const const_reverse_iterator& rhv) const {
    return p < rhv.p;
}

template<typename T>
bool Vector<T>::const_reverse_iterator::operator<=(const const_reverse_iterator& rhv) const {
    return p <= rhv.p;
}

template<typename T>
bool Vector<T>::const_reverse_iterator::operator>(const const_reverse_iterator& rhv) const {
    return p > rhv.p;
}

template<typename T>
bool Vector<T>::const_reverse_iterator::operator>=(const const_reverse_iterator& rhv) const {
    return p >= rhv.p;
}
// end const_reverse_iterator 

// begin reverse_iterator
template<typename T>
Vector<T>::reverse_iterator::reverse_iterator(pointer ptr)
    : p{ptr}
{}

template<typename T>
Vector<T>::reverse_iterator::reverse_iterator()
    : p{nullptr}
{}

template<typename T>
Vector<T>::reverse_iterator::reverse_iterator(const reverse_iterator& rhv)
    : p{rhv.p}
{}

template<typename T>
Vector<T>::reverse_iterator::reverse_iterator( reverse_iterator&& rhv)
    : p{std::move(rhv.p)}
{}
// end reverse_iterator 


template<typename T>
Vector<T>::referance Vector<T>::reverse_iterator::operator*() {
    return *p;
}

template<typename T>
Vector<T>::pointer Vector<T>::reverse_iterator::operator->() {
    return p;
}

template<typename T>
Vector<T>::const_iterator Vector<T>::cbegin() const {
    return const_iterator(m_ptr);
}

template<typename T>
Vector<T>::iterator Vector<T>::begin() {
    return iterator(m_ptr);
}

template<typename T>
Vector<T>::const_iterator Vector<T>::cend() const {
    return const_iterator(m_ptr + _size);
}

template<typename T>
Vector<T>::iterator Vector<T>::end()  {
   return iterator(m_ptr + _size);
}

template<typename T>
Vector<T>::const_reverse_iterator Vector<T>::rcbegin() const  {
    return const_reverse_iterator();
}

template<typename T>
Vector<T>::reverse_iterator Vector<T>::rbegin()  {
    return reverse_iterator(m_ptr - 1);
}

template<typename T>
Vector<T>::const_reverse_iterator Vector<T>::rcend() const {
    return const_reverse_iterator(begin() - 1);
}

template<typename T>
Vector<T>::reverse_iterator Vector<T>::rend() {
   return reverse_iterator(begin() - 1);
}


template<typename T>
Vector<T>::Vector() 
: m_ptr(nullptr)
, _size{0}
, _capacity{1}
{}

template<typename T>
Vector<T>::~Vector() { clear();}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> initList)
    : _size(initList.size()), _capacity(initList.size()), m_ptr(new T[initList.size()]) {
    std::copy(initList.begin(), initList.end(), m_ptr);
}

template<typename T>
Vector<T>::Vector(const_referance val ) :
  Vector(val , val , new T[_capacity])
{}

template<typename T>
Vector<T>::Vector(const Vector& rhv) 
    : Vector(rhv._size , rhv._capacity) 
{
    m_ptr = new T[_capacity];
    for (size_t i = 0; i < _size; ++i){
        m_ptr[i] = rhv.m_ptr[i];
    }
}

template<typename T>
Vector<T>::Vector(Vector&& rhv) : 
Vector (std::move(rhv._size) ,
        std::move(rhv._capacity) , 
        std::move(rhv.m_ptr)) {
    rhv._size = 0; 
    rhv._capacity = 0;
    rhv.m_ptr = nullptr; 
}

template<typename T>
const Vector<T>& Vector<T>::operator=(const Vector& rhv) {
    if (this != &rhv) {
    this->clear();
    _size = rhv._size;
    _capacity = rhv._capacity;
    m_ptr = rhv.m_ptr;
    }
    return *this; 
}

template<typename T>
const Vector<T>& Vector<T>::operator=(Vector&& rhv) {
    if (this != &rhv) {
    this->clear();
    _size = std::move(rhv._size);
    _capacity = std::move(rhv._capacity);
    m_ptr = std::move(rhv.m_ptr);

    _size = 0; 
    _capacity = 0; 
    m_ptr = nullptr; 
    }
    return *this; 
}

template<typename T>
Vector<T>::const_referance Vector<T>::operator[](size_type index) const  {
    
    return m_ptr[index];
}

template<typename T>
Vector<T>::referance Vector<T>::operator[](size_type index)  {
    return m_ptr[index];
}

template<typename T>
void Vector<T>::push_back(const_referance val){
    recap();
    m_ptr[++_size] = val; 
    // ++_size;
}

template<typename T>
void Vector<T>::pop_back()  {
    if (_size >  0){
        --_size;
    }
}

template<typename T>
Vector<T>::const_referance Vector<T>::front() const {
    return m_ptr[0];
}

template<typename T>
Vector<T>::referance Vector<T>::front() {
    return m_ptr[0];
}

template<typename T>
Vector<T>::const_referance Vector<T>::back() const {
    return m_ptr[_size - 1];
}

template<typename T>
Vector<T>::referance Vector<T>::back() {
     return m_ptr[_size - 1];
}

template<typename T>
void Vector<T>::recap() noexcept {
    if (_size == _capacity){
        _capacity *= 2;

        T* tmp = new T[_capacity];
        for (size_t i = 0; i < _size; ++i){
            tmp[i] = m_ptr[i]; 
        }
        delete[] m_ptr;
        m_ptr = tmp;
        tmp = nullptr; 
    }
}

template<typename T>
Vector<T>::const_referance Vector<T>::at(size_type index) const {
  
    return m_ptr[index];
}

template<typename T>
Vector<T>::referance Vector<T>::at(size_type index)  {
    
    return m_ptr[index];
}


template<typename T>
constexpr bool Vector<T>::empty() const {
    return _size == 0;
}

template<typename T>
constexpr Vector<T>::size_type Vector<T>::Size() const {
    return _size; 
}

template<typename T>
constexpr Vector<T>::size_type Vector<T>::max_size() const {
    return std::max(_size) / sizeof(T);
}

template<typename T>
constexpr Vector<T>::size_type Vector<T>::Capacity() const {
    return _capacity; 
}

template<typename T>
Vector<T>::const_pointer Vector<T>::data() const {
    return m_ptr;
}

template<typename T>
Vector<T>::pointer Vector<T>::data() {
    return m_ptr;
}

template<typename T>
void Vector<T>::clear() noexcept {
    _size = 0; 
    _capacity = 0; 
    delete[] m_ptr;
    m_ptr = nullptr; 
}


template<typename T>
void Vector<T>::insert(size_type index , const_referance val){
    if (index >= _size || index < 0){
        throw std::out_of_range("index of bounds");
    }
     recap();
     for (size_t i = _size; i >= index; --i){
        m_ptr[i] = m_ptr[i - 1];
     }
     m_ptr[index] = val; 
     ++_size; 
}

template<typename T>
void Vector<T>::erase(size_type index ) {
    for (size_t i = index; i < _size - 1; ++i){
        m_ptr[i] = m_ptr[i + 1];
    }
    --_size; 
}

template<typename T>
void Vector<T>::resize(value_type newsize , const_referance val ){
    if (newsize < _size) {
        _size = newsize;   
    }else if (newsize > _size){
        if (newsize > _capacity){
            _capacity = newsize * 2; 
        
         T* tmp = new T[_capacity];
         for (size_t i = 0; i < _size; ++i){
            tmp[i] = m_ptr[i];
         }
          delete[] m_ptr;
          m_ptr = tmp; 
          tmp = nullptr;
        }
       for (size_t i = _size; i < newsize; ++i){
          m_ptr[i] = val; 
       }
       _size = newsize;
    }

}
template<typename T>
Vector<T>::iterator Vector<T>::insert(iterator pos , const_referance x) {
    if (pos >= _size || pos , 0){
        throw std::out_of_range("Index of bounds");
    }
    recap();
    for (size_t i = _size; i >= pos; --i){
        m_ptr[i] = m_ptr[i - 1];
    }
    m_ptr[pos] = x; 
    ++_size; 
}

template<typename T>
void Vector<T>::insert(iterator pos, const int n, const T& x) {
    // implementation code 
}

template<typename T>
template<typename InputIterator>
void Vector<T>::insert(iterator pos , InputIterator f , InputIterator l) {
    // implementation code 
}

template<typename T>
Vector<T>::iterator Vector<T>::erase(iterator pos){
    // implementation code 
}

template<typename T>
Vector<T>::iterator Vector<T>::erase(iterator f , iterator l) {
    // implementation code 
}

template<typename T , typename U>
bool operator==(const Vector<T>& lhv , const Vector<U>& rhv) {
    return lhv.size() == rhv.size();
}
template<typename T , typename U>
bool operator!=(const Vector<T>& lhv , const Vector<U>& rhv) {
    return lhv.size() != rhv.size();
}
template<typename T , typename U>
bool operator>=(const Vector<T>& lhv , const Vector<U>& rhv) {
    return lhv.size() >= rhv.size();
}
template<typename T , typename U>
bool operator>(const Vector<T>& lhv , const Vector<U>& rhv) {
    return lhv.size() > rhv.size();
}
template<typename T , typename U>
bool operator<=(const Vector<T>& lhv , const Vector<U>& rhv) {
    return  lhv.size() <= rhv.size();
}
template<typename T , typename U>
bool operator<(const Vector<T>& lhv , const Vector<U>& rhv) {
    return lhv.size() < rhv.size();
}

template<typename T>
void Vector<T>::_swap( Vector& ob){
    std::swap(m_ptr , ob.m_ptr);
}

template<typename T>
std::ostream& operator<<(std::ostream& os , const Vector<T>& rhv){
    for(size_t i = 0; i < rhv.Size(); ++i){
        os << rhv[i] << " ";
    }
    return os; 
}
#endif // VECTOR_HPP