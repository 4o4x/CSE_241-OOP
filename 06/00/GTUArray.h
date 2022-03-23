#include "Iterable.h"
#include <memory>

#ifndef GTUARRAY_H
#define GTUARRAY_H

namespace sBurakYasar{


template <class T,int fixSize>
class GTUArray : public Iterable <T>{
    
    public:

    GTUArray();
    GTUArray(const GTUArray& obj);//Copy Constructor
    GTUArray(GTUArray&& obj); //Move Constructor

    GTUArray <T,fixSize>&  operator=(const GTUArray<T,fixSize>&obj); //Copy assignment 
    GTUArray <T,fixSize>&  operator=( GTUArray<T,fixSize>&&obj)noexcept; //Move assignment

    bool empty()const;
    int size()const;
    void erase(typename Iterable<T> ::GTUIterator position);
    void clear();
    typename Iterable<T> :: GTUIterator begin();
    typename Iterable<T> :: GTUIterator end();
    typename Iterable<T> :: GTUIteratorConst cbegin();
    typename Iterable<T> :: GTUIteratorConst cend();
    //void search(T element);

    bool isThere(T element)const;
    void del(T element);
    T& operator[](int n);
    T& at(int n);
    T& front();
    T& back();
    //T* data()noexcept;
    void fill(T n);

    void swap(GTUArray& obj);

    private:

    std::shared_ptr<T[]> ptrArray;
    int arraySize;
    
    
};


}

#endif