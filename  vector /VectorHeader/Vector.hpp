#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <initializer_list>

template<typename T>
class Vector {
private:
   using value_type = T;
   using referance = value_type&;
   using size_type = std::size_t;
   using const_referance = const value_type&;
   using difference_type = std::ptrdiff_t;
   using pointer = value_type*;
   using const_pointer = const value_type*;

   class Allocator {
    public:
        T* ptr = nullptr; 
    public:
        using value_type = T;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using size_type = std::size_t;
    public:
        Allocator() = default;
        Allocator(const Allocator& rhv) = default;
        virtual ~Allocator() = default;
    public:
        pointer allocate(size_type count );
        
        template<typename... Args>
        void constract(pointer ptr , Args... args);

        void deallocate(void* ptr , size_type count);

        template<typename... Args>
        void destroy(pointer ptr , Args... args);

        size_type max_size();
   };
   public:    
    class const_iterator {
        friend class Vector<value_type>;
    private:
        pointer p;
    protected:
         const_iterator(pointer ptr);
    public:
        const_iterator();
        const_iterator(const const_iterator& rhv);
        const_iterator(const_iterator&& rhv);

        ~const_iterator() noexcept;

        const const_iterator& operator=(const const_iterator& rhv);
        const const_iterator& operator=(const_iterator&& rhv);

        const_referance operator*() const;
        const_pointer operator->() const;

        const const_iterator operator+(size_type val) const;
        const const_iterator operator-(size_type val) const;
        const const_iterator& operator-=(size_type val) const;
        const const_iterator& operator+=(size_type val) const;
        const const_iterator& operator++();
        const const_iterator operator++(int);
        const const_iterator& operator--();
        const const_iterator operator--(int);

        const_referance operator[](size_type ind) const;

        bool operator==(const const_iterator& rhv) const;
        bool operator!=(const const_iterator& rhv) const;
        bool operator<(const const_iterator& rhv) const;
        bool operator>(const const_iterator& rhv) const;
        bool operator<=(const const_iterator& rhv) const;
        bool operator>=(const const_iterator& rhv) const;
        
    };
    class iterator : public const_iterator {
        friend class Vector<value_type>;
    private:
        pointer p;
    protected:
         iterator(pointer ptr);
    public:
        iterator();
        iterator(const iterator& rhv);
        iterator(iterator&& rhv);
        
        referance operator*();
        pointer operator->();
    };

    public:    
    class const_reverse_iterator {
        friend class Vector<value_type>;
    private:
        pointer p;
    protected:
        const_reverse_iterator(pointer ptr);
    public:
        const_reverse_iterator();
        const_reverse_iterator(const const_reverse_iterator& rhv);
        const_reverse_iterator(const_reverse_iterator&& rhv);

        ~const_reverse_iterator() noexcept;

        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv);
        const const_reverse_iterator& operator=(const_reverse_iterator&& rhv);

        const_referance operator*() const;
        const_pointer operator->() const;

        const const_reverse_iterator operator+(size_type val) const;
        const const_reverse_iterator operator-(size_type val) const;
        const const_reverse_iterator& operator-=(size_type val) const;
        const const_reverse_iterator& operator+=(size_type val) const;
        const const_reverse_iterator& operator++();
        const const_reverse_iterator operator++(int);
        const const_reverse_iterator& operator--();
        const const_reverse_iterator operator--(int);

        const_referance operator[](size_type ind) const;

        bool operator==(const const_reverse_iterator& rhv) const;
        bool operator!=(const const_reverse_iterator& rhv) const;
        bool operator<(const const_reverse_iterator& rhv) const;
        bool operator>(const const_reverse_iterator& rhv) const;
        bool operator<=(const const_reverse_iterator& rhv) const;
        bool operator>=(const const_reverse_iterator& rhv) const;
        
    };
    class reverse_iterator : public const_reverse_iterator {
        friend class Vector<value_type>;
    private:
            pointer p;
    protected:
         reverse_iterator(pointer ptr);
    public:
        reverse_iterator();
        reverse_iterator(const reverse_iterator& rhv);
        reverse_iterator(reverse_iterator&& rhv);
        
        referance operator*();
        pointer operator->();
    };

   public:
   Vector();
   
   ~Vector();
   
   Vector(std::initializer_list<T> initList);
   
   Vector(const_referance);
   
   Vector(const Vector& );
   
   Vector(Vector&& );
   
   const Vector& operator=(const Vector&);
   
   const Vector& operator=(Vector&&);  
   
    void push_back(const_referance);

    void pop_back(); 
  
    void recap()  noexcept;
    
    void insert(size_type , const_referance);
   
    void erase(size_type);
   
    void resize(value_type , const_referance);
   
    void clear() noexcept;
   
    void _swap( Vector&);
    
  const_pointer data() const;

  const_referance operator[](size_type) const; 
  
  const_referance front() const;  
  
  const_referance back() const; 
  
  const_referance at(size_type) const;
   
   referance front(); 
    
   referance back();
   
   referance operator[](size_type);

   referance at(size_type);

    pointer data(); 

   
   constexpr bool empty() const;
   
   constexpr size_t Size() const; 
   
   constexpr size_t max_size() const; 
   
   constexpr size_t Capacity() const; 
   
// Iterators

    const_iterator cbegin() const; //O(1)
    
    iterator begin(); //O(1)
    
    const_iterator cend() const; //O(1)
    
    iterator end(); //O(1)
    
    const_reverse_iterator rcbegin() const; //O(1)
    
    reverse_iterator rbegin(); //O(1)
    
    const_reverse_iterator rcend() const; //O(1)
    
    reverse_iterator rend(); //O(1)

    public:
    iterator insert(iterator pos, const_referance x);//O(n)

    void insert(iterator pos, const int n, const T& x); //O(n)

    template <typename InputIterator>

    void insert(iterator pos, InputIterator f, InputIterator l); //O(n)
    
    iterator erase(iterator pos); //O(n)
    iterator erase(iterator f, iterator l); //O(n)

   private:
   T* m_ptr; 
   size_t _size; 
   size_t _capacity;

};

template<typename T, typename U>
bool operator==(const Vector<T>& lhv , const Vector<U>& rhv);

template<typename T, typename U>
bool operator!=(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator>(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator>=(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator<(const Vector<T>& lhv, const Vector<U>& rhv);

template<typename T, typename U>
bool operator<=(const Vector<T>& lhv, const Vector<U>& rhv);


template<typename T>
std::ostream& operator<<(std::ostream& os , const Vector<T>& rhv);

#include "Vector.cpp"

#endif // VECTOR_HPP
