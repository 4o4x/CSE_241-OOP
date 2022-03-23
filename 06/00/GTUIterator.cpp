#include "Iterable.h"
#include <memory>

#ifndef GTUIterator_CPP
#define GTUIterator_CPP

namespace sBurakYasar{

    template <class T>
    Iterable <T> :: GTUIterator :: GTUIterator(){
        p = NULL;
    }
    
    template <class T>
    Iterable <T> :: GTUIterator :: GTUIterator(T* ptr){
        p = ptr;
    }

    template <class T>
    T& Iterable <T> :: GTUIterator :: operator*()const{
        return *p;
    }
    
    template <class T>
    T* Iterable <T> :: GTUIterator :: operator->(){
        return p;
    }

    template <class T>
    typename Iterable <T> :: GTUIterator Iterable <T> :: GTUIterator :: operator+(int n){
        T * temp = p+n;
        return GTUIterator(temp);
    }

    template <class T>
    int Iterable <T> :: GTUIterator :: operator-(const GTUIterator& obj){
        return p - obj.p;
    }

    template <class T>
    typename Iterable <T> :: GTUIterator Iterable <T> :: GTUIterator :: operator-(int n){
        return GTUIterator(p-n);
    }

    template <class T>
    typename Iterable <T> :: GTUIterator Iterable <T> :: GTUIterator :: operator++(){
        p++;
        return *this;
    }

    template <class T>
    typename Iterable <T> :: GTUIterator Iterable <T> :: GTUIterator :: operator++(int dummy){
        GTUIterator temp = *this;
        p++;
         
        return temp;
    }

    template <class T>
    typename Iterable <T> :: GTUIterator Iterable <T> :: GTUIterator :: operator--(){
        p--;
        return *this;
    }

    template <class T>
    typename Iterable <T> :: GTUIterator Iterable <T> :: GTUIterator :: operator--(int dummy){
        GTUIterator temp = *this;
        p--;
         
        return temp;
    }
    
    template <class T>
    bool Iterable <T> :: GTUIterator :: operator==(const GTUIterator& obj)const{
        if(p == obj.p){
            return true;
        }

        else return false;
    }

    template <class T>
    bool Iterable <T> :: GTUIterator :: operator!=(const GTUIterator& obj)const{
        if(*this == obj){
            return false;
        }

        else return true;
    }

    template <class T>
    bool Iterable <T> :: GTUIterator :: operator<(const GTUIterator& obj)const{
        if(p-obj.p < 0){
            return true;
        }

        else return false;
        
    }

    template <class T>
    bool Iterable <T> :: GTUIterator :: operator>(const GTUIterator& obj)const{
        if(p-obj.p > 0){
            return true;
        }

        else return false;
        
    }

    template <class T>
    bool Iterable <T> :: GTUIterator :: operator>=(const GTUIterator& obj)const{
        if(p-obj.p >= 0){
            return true;
        }

        else return false;
        
    }

    template <class T>
    bool Iterable <T> :: GTUIterator :: operator<=(const GTUIterator& obj)const{
        if(p-obj.p <= 0){
            return true;
        }

        else return false;   
    }
}

#endif