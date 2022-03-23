#include "Iterable.h"
#include <memory>

#ifndef GTUIteratorConst_CPP
#define GTUIteratorConst_CPP

namespace sBurakYasar{

    template <class T>
    Iterable <T> :: GTUIteratorConst ::GTUIteratorConst(){
        p = NULL;
    }
    
    template <class T>
    Iterable <T> :: GTUIteratorConst ::GTUIteratorConst(T* ptr){
        p = ptr;
    }

    template <class T>
    const T& Iterable <T> :: GTUIteratorConst :: operator*()const{
        return *p;
    }
    
    template <class T>
    const T* Iterable <T> :: GTUIteratorConst :: operator->(){
        return p;
    }

    template <class T>
    typename Iterable <T> :: GTUIteratorConst Iterable <T> :: GTUIteratorConst :: operator+(int n){
        T * temp = p+n;
        return GTUIteratorConst(temp);
    }

    template <class T>
    int Iterable <T> :: GTUIteratorConst :: operator-(const GTUIteratorConst& obj){
        return p - obj.p;
    }

    template <class T>
    typename Iterable <T> :: GTUIteratorConst Iterable <T> :: GTUIteratorConst :: operator-(int n){
        return GTUIteratorConst(p-n);;
    }

    template <class T>
    typename Iterable <T> :: GTUIteratorConst Iterable <T> :: GTUIteratorConst :: operator++(){
        p++;
        return *this;
    }

    template <class T>
    typename Iterable <T> :: GTUIteratorConst Iterable <T> ::GTUIteratorConst :: operator++(int dummy){
       GTUIteratorConst temp = *this;
        p++;
         
        return temp;
    }

    template <class T>
    typename Iterable <T> :: GTUIteratorConst Iterable <T> :: GTUIteratorConst :: operator--(){
        p--;
        return *this;
    }

    template <class T>
    typename Iterable <T> :: GTUIteratorConst Iterable <T> :: GTUIteratorConst :: operator--(int dummy){
       GTUIteratorConst temp = *this;
        p--;
         
        return temp;
    }
    
    template <class T>
    bool Iterable <T> :: GTUIteratorConst :: operator==(const GTUIteratorConst& obj)const{
        if(p == obj.p){
            return true;
        }

        else return false;
    }

    template <class T>
    bool Iterable <T> :: GTUIteratorConst :: operator!=(const GTUIteratorConst& obj)const{
        if(*this == obj){
            return false;
        }

        else return true;
    }

    template <class T>
    bool Iterable <T> :: GTUIteratorConst :: operator<(const GTUIteratorConst& obj)const{
        if(p-obj.p < 0){
            return true;
        }

        else return false;
        
    }

    template <class T>
    bool Iterable <T> :: GTUIteratorConst :: operator>(const GTUIteratorConst& obj)const{
        if(p-obj.p > 0){
            return true;
        }

        else return false;
        
    }

    template <class T>
    bool Iterable <T> :: GTUIteratorConst :: operator>=(const GTUIteratorConst& obj)const{
        if(p-obj.p >= 0){
            return true;
        }

        else return false;
        
    }

    template <class T>
    bool Iterable <T> :: GTUIteratorConst :: operator<=(const GTUIteratorConst& obj)const{
        if(p-obj.p <= 0){
            return true;
        }

        else return false;   
    }
}

#endif