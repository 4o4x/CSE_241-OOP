#include "Iterable.h"
//#include "Iterable.cpp"
#include <memory>

#ifndef GTUVector_H
#define GTUVector_H

namespace sBurakYasar{


template <class T>
class GTUVector : public Iterable <T>{
    
    public:

    GTUVector(); //Default Constructor
    GTUVector(const GTUVector<T>& obj);//Copy Constructor
    GTUVector(GTUVector<T>&& obj); //Move Constructor
    
    GTUVector <T>& operator=(const GTUVector<T>&obj); //Copy assignment 
    GTUVector <T>& operator=(GTUVector<T>&&obj)noexcept; //Move assignment 

    ~GTUVector() = default; //destructor
    
    GTUVector(int s);
    bool empty()const;
    int size()const;
    void clear();
    
    typename Iterable<T> :: GTUIterator begin();
    typename Iterable<T> :: GTUIterator end();
    typename Iterable<T> :: GTUIteratorConst cbegin();
    typename Iterable<T> :: GTUIteratorConst cend();
    void erase(typename Iterable<T> :: GTUIterator position);

    void pr(){
        std::cout << std::endl << "count:" << vect.use_count()<<std::endl;
    }


    void add(T element);
    T& operator[](int n);

    private:


    std::shared_ptr<T[]> vect;
    int vectSize;
    //int VectCapacity;
    
};


}

#endif