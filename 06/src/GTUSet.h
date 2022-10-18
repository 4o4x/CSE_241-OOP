#include "Iterable.h"
#include <memory>

#ifndef GTUSet_H
#define GTUSet_H

namespace sBurakYasar{


template <class T>
class GTUSet : public Iterable <T>{
    
    public:

    GTUSet();
    GTUSet(GTUSet& obj);//Copy Constructor
    GTUSet(GTUSet&& obj); //Move Constructor

    GTUSet <T>& operator=(const GTUSet<T>&obj); //Copy assignment 
    GTUSet <T>& operator=(GTUSet<T>&&obj)noexcept; //Move assignment 

    bool empty()const;
    int size()const;
    void erase(typename Iterable<T> ::GTUIterator position);
    void clear();
    typename Iterable<T> :: GTUIterator begin();
    typename Iterable<T> :: GTUIterator end();
    typename Iterable<T> :: GTUIteratorConst cbegin();
    typename Iterable<T> :: GTUIteratorConst cend();
    typename Iterable<T> :: GTUIterator search (T element);

    bool isThere(T element)const;
    void add(T element);
    void del(T element);

    GTUSet<T> intersectSet(const GTUSet<T> &obj)const;
    
    GTUSet<T> unionSet(const GTUSet<T> &obj)const;

    private:

    std::shared_ptr<T[]> ptrSet;
    int setSize;
    
    
};


}

#endif