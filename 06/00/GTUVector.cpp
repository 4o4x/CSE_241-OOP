#include "GTUVector.h"
#include <memory>

#ifndef GTUVector_CPP
#define GTUVector_CPP

namespace sBurakYasar{

    

    template <class T>
    GTUVector <T> :: GTUVector(){
        vectSize = 0;
        vect = NULL;
    }

    template <class T>
    GTUVector <T> :: GTUVector(GTUVector<T>&& obj){
        vect = obj.vect;
        vectSize = obj.vectSize;

        obj.vectSize = 0;
        obj.vect = NULL;
    }

    template <class T>
    GTUVector <T> :: GTUVector(const GTUVector<T>& obj){
        vect = obj.vect;
        vectSize = obj.vectSize;
    }

    template <class T>
    GTUVector <T>& GTUVector <T> :: operator=(const GTUVector<T>&obj){
        
        std::shared_ptr<T[]>  temp(new T[obj.size()]);
        vectSize = obj.vectSize;

        for(int i = 0; i<size();i++){
            temp[i] = obj.vect[i];
        }
        
        vect = temp;
        return *this;
    }

    template <class T>
    GTUVector <T>& GTUVector <T> :: operator=(GTUVector<T>&&obj)noexcept{
        
        vect = obj.vect;
        vectSize = obj.vectSize;
        
        obj.vect = NULL;
        obj.vectSize = 0;
        
        return *this;
    }


    template <class T>
    bool GTUVector <T> :: empty()const{
        if(size()== 0)
            return true;
        else return false;
    }

    template <class T>
    int GTUVector <T> :: size()const{
        return vectSize;
    }

    template <class T>
    void GTUVector <T> :: erase(typename Iterable<T> ::GTUIterator position){
        
        std::shared_ptr<T[]>  temp(new T[size()-1]);

        for(int i = 0,j=0; i<size();i++,j++){
            
            if(vect[i] == *position){
                --j;
                continue;
            }
                
            temp[j] = vect[i];
        }

        vect = temp;
    

        --vectSize;
    }

    template <class T>
    void GTUVector <T> :: clear(){
        if(size()!=0){
            vectSize = 0;
            vect = NULL;
        }
    }

    template <class T>
    typename Iterable<T> :: GTUIterator GTUVector <T> :: begin(){
        return typename Iterable<T> :: GTUIterator(&vect[0]);
    }

    template <class T>
    typename Iterable<T> :: GTUIterator GTUVector <T> :: end(){
        return typename Iterable<T> :: GTUIterator(&vect[size()]);
    }

    template <class T>
    typename Iterable<T> :: GTUIteratorConst GTUVector <T> :: cbegin(){
        return typename Iterable<T> :: GTUIteratorConst(&vect[0]);
    }

    template <class T>
    typename Iterable<T> :: GTUIteratorConst GTUVector <T> :: cend(){
        return typename Iterable<T> :: GTUIteratorConst(&vect[size()]);
    }

    template <class T>
    void GTUVector <T> :: add(T element){
       
        std::shared_ptr<T[]>  temp(new T[size()+1]);

        for(int i = 0; i<size();i++){
            temp[i] = vect[i];
        }

        temp[size()] = element;


        vect = temp;

        ++vectSize;
        
    }

    template <class T>
    T& GTUVector <T> :: operator[](int n){
        return vect[n];
    }


}
#endif