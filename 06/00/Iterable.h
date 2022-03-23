#include <memory>
#include <iterator> 

#ifndef ITERABLE_H
#define ITERABLE_H

namespace sBurakYasar{

template <class T>

class Iterable{

    public:

    class GTUIterator{
        
        public:
        
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = int;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;

        GTUIterator();
        GTUIterator(T* ptr);
        
        T& operator*()const;
        T* operator->();
        GTUIterator operator+(int n);
        friend GTUIterator operator+(int n,const GTUIterator& obj){return GTUIterator(obj.p + n);}
        GTUIterator operator-(int n);
        int operator-(const GTUIterator& obj);
        GTUIterator operator++();
        GTUIterator operator++(int dummy);
        GTUIterator operator--();
        GTUIterator operator--(int dummy);
        bool operator==(const GTUIterator& obj)const;
        bool operator!=(const GTUIterator& obj)const;
        bool operator<(const GTUIterator& ob)const;
        bool operator<=(const GTUIterator& ob)const;
        bool operator>(const GTUIterator& ob)const;
        bool operator>=(const GTUIterator& ob)const;
        GTUIterator operator+=(int n);
        GTUIterator operator-=(int n);
        
        private:
        
        T *p;
    };

    class GTUIteratorConst{
        public:
        
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = int;
        using value_type = T;
        using pointer = value_type*;
        using reference = value_type&;

        GTUIteratorConst();
        GTUIteratorConst(T* ptr);
        T* get()const;
        const T& operator*()const;
        const T* operator->();
        GTUIteratorConst operator+(int n);
        friend GTUIteratorConst operator+(int n,const GTUIteratorConst& obj){return GTUIteratorConst(obj.p + n);}
        GTUIteratorConst operator-(int n);
        int operator-(const GTUIteratorConst& obj);
        GTUIteratorConst operator++();
        GTUIteratorConst operator++(int dummy);
        GTUIteratorConst operator--();
        GTUIteratorConst operator--(int dummy);
        bool operator==(const GTUIteratorConst& obj)const;
        bool operator!=(const GTUIteratorConst& obj)const;
        bool operator<(const GTUIteratorConst& ob)const;
        bool operator<=(const GTUIteratorConst& ob)const;
        bool operator>(const GTUIteratorConst& ob)const;
        bool operator>=(const GTUIteratorConst& ob)const;
        GTUIteratorConst operator+=(int n);
        GTUIteratorConst operator-=(int n);

        private:
        
        T *p;
    };


    virtual bool empty()const = 0;
    virtual int size()const = 0;
    virtual void clear() = 0;

    virtual void erase(GTUIterator position) = 0; 
    virtual GTUIterator begin() = 0;
    virtual GTUIterator end() = 0;
    virtual GTUIteratorConst cbegin() = 0;
    virtual GTUIteratorConst cend() = 0;

};

}

#endif