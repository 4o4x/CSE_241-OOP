#include "GTUArray.h"
#include <memory>

#ifndef GTUArray_CPP
#define GTUArray_CPP

namespace sBurakYasar{

    template <class T,int fixSize>
    GTUArray <T,fixSize> ::  GTUArray(){
        arraySize = fixSize;
        std::shared_ptr<T[]>  temp(new T[fixSize]);
        ptrArray = temp;
    }

    template <class T,int fixSize>
    GTUArray <T,fixSize> ::  GTUArray(GTUArray&& obj){
        ptrArray = obj.ptrArray;
        arraySize = obj.arraySize;

        obj.arraySize = 0;
        obj.ptrArray = NULL;
    }

    template <class T,int fixSize>
    GTUArray <T,fixSize> ::  GTUArray(const GTUArray& obj){
        ptrArray = obj.ptrArray;
        arraySize = obj.arraySize;
    }

    template <class T,int fixSize>
    GTUArray <T,fixSize>& GTUArray <T,fixSize> :: operator=(const GTUArray<T,fixSize>&obj){
        
        std::shared_ptr<T[]>  temp(new T[obj.size()]);
        arraySize = obj.arraySize;

        for(int i = 0; i<size();i++){
            temp[i] = obj.ptrArray[i];
        }
        
        ptrArray = temp;
        return *this;
    }

    template <class T,int fixSize>
    GTUArray <T,fixSize>& GTUArray <T,fixSize> :: operator=(GTUArray<T,fixSize>&&obj)noexcept{
        
        ptrArray = obj.ptrArray;
        arraySize = obj.arraySize;
        
        obj.ptrArray = NULL;
        obj.arraySize = 0;
        
        return *this;
    }

    template <class T,int fixSize>
    bool GTUArray <T,fixSize> :: empty()const{
        if(size()== 0)
            return true;
        else return false;
    }

    template <class T,int fixSize>
    int GTUArray <T,fixSize> :: size()const{
        return arraySize;
    }

    template <class T,int fixSize>
    void GTUArray <T,fixSize> :: erase(typename Iterable<T> ::GTUIterator position){
        
        std::shared_ptr<T[]>  temp(new T[size()-1]);

        for(int i = 0,j=0; i<size();i++,j++){
            
            if(ptrArray[i] == *position){
                --j;
                continue;
            }
                
            temp[j] = ptrArray[i];
        }

        ptrArray = temp;
    

        --arraySize;
    }

    template <class T,int fixSize>
    void GTUArray <T,fixSize> :: clear(){
        ptrArray = NULL;
        std::shared_ptr<T[]>  temp(new T[arraySize]);
        ptrArray = temp;
        
        
    }


    template <class T,int fixSize>
    T& GTUArray <T,fixSize> :: operator[](int n){
        return ptrArray[n];
    }

    template <class T,int fixSize>
    T& GTUArray <T,fixSize> :: at(int n){
        return ptrArray[n];
    }

    template <class T,int fixSize>
    T& GTUArray <T,fixSize> :: front(){
        return ptrArray[0];
    }

    template <class T,int fixSize>
    T& GTUArray <T,fixSize> :: back(){
        return ptrArray[size()-1];
    }

    template <class T,int fixSize>
    void GTUArray <T,fixSize> :: fill(T n){
        for(int i=0;i<size();i++){
            ptrArray[i] = n;
        }
    }

    template <class T,int fixSize>
    typename Iterable<T> :: GTUIterator GTUArray <T,fixSize> :: begin(){
        return typename Iterable<T> :: GTUIterator(&ptrArray[0]);
    }

    template <class T,int fixSize>
    typename Iterable<T> :: GTUIterator GTUArray <T,fixSize> :: end(){
        return typename Iterable<T> :: GTUIterator(&ptrArray[size()]);
    }

    template <class T,int fixSize>
    typename Iterable<T> :: GTUIteratorConst GTUArray <T,fixSize> :: cbegin(){
        return typename Iterable<T> :: GTUIteratorConst(&ptrArray[0]);
    }

    template <class T,int fixSize>
    typename Iterable<T> :: GTUIteratorConst GTUArray <T,fixSize> :: cend(){
        return typename Iterable<T> :: GTUIteratorConst(&ptrArray[size()]);
    }
}
#endif