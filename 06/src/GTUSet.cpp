#include "GTUSet.h"
#include <memory>

#ifndef GTUSet_CPP
#define GTUSet_CPP

namespace sBurakYasar{

template <class T>
GTUSet <T> ::  GTUSet(){
    setSize = 0;
    ptrSet = NULL;
}

template <class T>
GTUSet <T> :: GTUSet(GTUSet&& obj){
    ptrSet = obj.ptrSet;
    setSize = obj.setSize;

    obj.setSize = 0;
    obj.ptrSet = NULL;
}

template <class T>
GTUSet <T> :: GTUSet(GTUSet& obj){
    ptrSet = obj.ptrSet;
    setSize = obj.setSize;
}

template <class T>
GTUSet <T>& GTUSet <T> :: operator=(const GTUSet<T>&obj){
    
    std::shared_ptr<T[]>  temp(new T[obj.size()]);
    setSize = obj.setSize;

    for(int i = 0; i<size();i++){
        temp[i] = obj.ptrSet[i];
    }
    
    ptrSet = temp;
    return *this;
}

template <class T>
GTUSet <T>& GTUSet <T> :: operator=(GTUSet<T>&&obj)noexcept{
    
    ptrSet = obj.ptrSet;
    setSize = obj.setSize;
    
    obj.ptrSet = NULL;
    obj.setSize = 0;
    
    return *this;
}

template <class T>
bool GTUSet <T> :: empty()const{
    if(size()== 0)
        return true;
    else return false;
}

template <class T>
int GTUSet <T> :: size()const{
    return setSize;
}

template <class T>
void GTUSet <T> :: erase(typename Iterable<T> ::GTUIterator position){
    
    std::shared_ptr<T[]>  temp(new T[size()-1]);

    for(int i = 0,j=0; i<size();i++,j++){
        
        if(ptrSet[i] == *position){
            --j;
            continue;
        }
            
        temp[j] = ptrSet[i];
    }

    ptrSet = temp;
    
    --setSize;
}

template <class T>
void GTUSet <T> :: clear(){
    if(size()!=0){
        setSize = 0;
        ptrSet = NULL;
    }
}

template <class T>
typename Iterable<T> :: GTUIterator GTUSet <T> :: begin(){
    return typename Iterable<T> :: GTUIterator(&ptrSet[0]);
}

template <class T>
typename Iterable<T> :: GTUIterator GTUSet <T> :: end(){
    return typename Iterable<T> :: GTUIterator(&ptrSet[size()]);
}

template <class T>
typename Iterable<T> :: GTUIteratorConst GTUSet <T> :: cbegin(){
    return typename Iterable<T> :: GTUIteratorConst(&ptrSet[0]);
}

template <class T>
typename Iterable<T> :: GTUIteratorConst GTUSet <T> :: cend(){
    return typename Iterable<T> :: GTUIteratorConst(&ptrSet[size()]);
}

template <class T>
typename Iterable<T> :: GTUIterator GTUSet <T> :: search(T element){
    
    for(int i=0;i<size();i++){
        if(ptrSet[i] == element)
            return &ptrSet[i];
    }
}


template <class T>
void GTUSet <T> :: add(T element){
    
    if(isThere(element))
        return;
    
    
    if(empty()){
        ptrSet.reset(new T[1]);
        ptrSet[0] = element;
    }
    
    else{
        std::shared_ptr<T[]>  temp(new T[size()+1]);

        for(int i = 0; i<size();i++){
            temp[i] = ptrSet[i];
        }

        temp[size()] = element;


        ptrSet = temp;

        
    }

    ++setSize;
    
}

template <class T>
GTUSet<T>  GTUSet<T> :: unionSet(const GTUSet<T> &obj)const{
    
    GTUSet <T> temp;

    if(empty()){
        temp = obj;
        return temp;
    }

    else if(obj.empty()){
        temp = *this;
        return temp;
    }

    else{
        
        temp = obj;

        for(int i = 0; i<size();i++){
            temp.add(ptrSet[i]);
        }

        return temp;
    }
    
}

template <class T>
bool GTUSet <T> :: isThere(T element)const{
    for(int i=0; i<size();i++){
        if(ptrSet[i] == element) return true;
    }
    return false;
}

template <class T>
void GTUSet <T> :: del(T element){
    
    if(!isThere(element))
        return;

    if(size() == 1){
        ptrSet.reset();
    }

    else{
        
        std::shared_ptr<T[]>  temp(new T[size()-1]);

        for(int i = 0,j=0; i<size();i++,j++){
            
            if(ptrSet[i] == element){
                --j;
                continue;
            }
                
            temp[j] = ptrSet[i];
        }

        ptrSet = temp;
    }

    --setSize;

}

template <class T>
GTUSet<T>  GTUSet <T> :: intersectSet(const GTUSet<T> &obj)const{
    GTUSet<T>temp;

    if(empty() || obj.empty()){
            return temp;
    }

    else{
            
        for(int i = 0; i<size() ; i++){
            if(obj.isThere(ptrSet[i]))
                temp.add(ptrSet[i]);
            }

            return temp;
        }


}


}

#endif