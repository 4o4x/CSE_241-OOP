#include <iostream>
#include <vector>
#include "dayofyearset.h"

using namespace std;
namespace sBurakYasar{

    int DayofYearSet :: totalDoy = 0;

    /*Default argument constructor*/
    DayofYearSet :: DayofYear :: DayofYear(int d,int m ){
        
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //number of days in months

        if(m<0 || m>12){ //checks if input is valid
            cout << endl << "Invalid month vaule" << endl;
            exit(1); 
        }

        if(d < 0 || d > arrMonth[m-1]){ //checks if input is valid
            cout << endl << "Invalid day vaule" << endl;
            exit(1); 
        }

        day = d;
        month = m;
    }

    void DayofYearSet :: DayofYear :: setDay(int d){
        
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //number of days in months
        
        if(d < 0 || d > arrMonth[month-1]){ //checks if input is valid
            cout << endl << "Invalid day vaule" << endl;
            exit(1); 
        }

        day = d;
    }

    void DayofYearSet :: DayofYear :: setMonth(int m){

        if(m<0 || m>12){  //checks if input is valid
            cout << endl << "Invalid month vaule" << endl;
            exit(1); 
        }

        month = m;
    }

    void DayofYearSet :: DayofYear :: setAll(int d,int m){
        
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; //number of days in months
        
        

        if(m<0 || m>12){ //checks if input is valid
            cout << endl << "Invalid month vaule" << endl;
            exit(1); 
        }

        if(d < 0 || d > arrMonth[m-1]){ //checks if input is valid
            cout << endl << "Invalid day vaule" << endl;
            exit(1); 
        }

        day = d;
        month = m;

    }
    
    /*Getters*/
    int DayofYearSet :: DayofYear :: getDay()const{return day;} 
    int DayofYearSet :: DayofYear :: getMonth()const{return month;}

    bool DayofYearSet :: DayofYear :: operator ==(const DayofYear& other){ //checks if dayofyears are same
        if(day == other.day && month == other.month) return true;
        else return false;
    }

    ostream& operator<<(ostream &out,const DayofYearSet :: DayofYear& input){ //ostream operator overloading for dayofyear
        out << endl << "Day:" << input.getDay() << endl <<  "Month:" << input.getMonth() << endl;
        return out;
    }

    /*Constructor*/
    DayofYearSet :: DayofYearSet(){
        daySet = nullptr;
        setSize = 0; 
    }

    DayofYearSet :: DayofYearSet(const vector<DayofYear> &input){
        
        setSize = 0;

        if(input.empty()){
            daySet = nullptr;    
        }

        else{
            for(int i=0 ; i< input.size(); i++){
                add(input[i]); 
            }            
        }
    }

    DayofYearSet :: ~DayofYearSet(){
        
        if(!(daySet == nullptr))
        delete []daySet;
        totalDoy = totalDoy - setSize;
    }

    DayofYearSet :: DayofYearSet(const DayofYearSet& other){
        
        if(other.empty()){
            daySet = nullptr;
            setSize = 0;
        }

        else{
            
            daySet = new DayofYear[other.size()];
                
            for(int i=0;i<other.size();i++){
                daySet[i] = other[i];
            }
            setSize = other.size();
            totalDoy +=setSize;
        }

    }

    const DayofYearSet DayofYearSet :: operator=(const DayofYearSet& other){
        
        if(other.empty()){
            daySet = nullptr;
            setSize = 0;
        }

        else{
            
            daySet = new DayofYear[other.size()];
                
            for(int i=0;i<other.size();i++){
                daySet[i] = other[i];
            }
            setSize = other.size();
            totalDoy +=setSize;
        }

        return *this;
    }

    int DayofYearSet :: size()const{return setSize;}

    void DayofYearSet :: add(const DayofYear& input){
        
        if(empty()){
            daySet = new DayofYear[1];
            daySet[0] = input;
            setSize++;
            totalDoy++;
        }

        else if(!isThere(input)){
            
            DayofYear * temp = new DayofYear[setSize+1];
            
            for(int i=0;i<setSize;i++){
                temp[i] = daySet[i];
            }

            temp[setSize] = input;

            delete[] daySet;

            daySet = temp;

            
            setSize++;
            totalDoy++;
        }
        
    }

    void DayofYearSet :: remove(){
        if(empty()){
            cout << endl << "---Error:there is not any element in set ---" << endl;
            return;
        }

        else{
            
            if(setSize == 1){
                delete[] daySet;
                daySet = nullptr;
                setSize--;
                totalDoy--;
                return;
            }

            DayofYear * temp = new DayofYear[setSize-1];
            
            for(int i=0;i<setSize-1;i++){
                temp[i] = daySet[i];
            }

            delete[] daySet;

            daySet = temp;
            
            setSize--;
            totalDoy--;
        }
    }

    void DayofYearSet :: remove(int index){
        
        if(empty()){
            cout << endl << "---Error:there is not any element in set ---" << endl;
        }

        else{
            
            if(index>setSize){
                cerr << endl <<  "---Error:Invalid index---" << endl;
                return;
            }

            if(setSize == 1){
                delete[] daySet;
                daySet = nullptr;
                setSize--;
                totalDoy--;
                return;
            }

            DayofYear * temp = new DayofYear[setSize-1];
            int j = 0; 
            for(decltype(j)i=0;i<setSize-1;i++,j++){
                
                if(i==index) j++;

                temp[i] = daySet[j];
            }

            delete[] daySet;

            daySet = temp;
            
            setSize--;
            totalDoy--;
        }
    }

    void DayofYearSet :: remove(const DayofYear& input){
        
        if(empty()){
            cout << endl << "---ERROR:there is not any element in set---" << endl;
        }

        else{
            
            if(!isThere(input)){
                cout << endl << "this element is not in the set" << endl;
                return;
            }

            if(setSize == 1){
                delete[] daySet;
                daySet = nullptr;
                setSize--;
                totalDoy--;
                return;
            }

            DayofYear * temp = new DayofYear[setSize-1];
            int j = 0; 
            for(int i=0;i<setSize-1;i++,j++){
                
                if(daySet[i]==input) j++;

                temp[i] = daySet[j];
            }

            delete[] daySet;

            daySet = temp;
            
            setSize--;
            totalDoy--;
        }
        

    }

    bool DayofYearSet :: empty()const{
        if(setSize == 0 || daySet == nullptr)
            return true;
        else return false;
    }

    bool DayofYearSet :: isThere(const DayofYear& input)const{

        for(int i=0;i<setSize;i++){
            if(daySet[i] == input) return true;
        }
        return false;
    }

    ostream& operator<<(ostream &out,const DayofYearSet& input){
        
        //out << endl;

        if(input.empty()){
            out << "There is not any element in this set" << endl;
            return out;
        }

        for(int i=0;i<input.setSize ;i++){
            out << "Element "<< i+1 << "   ->\tDay:" << input.daySet[i].getDay() << "\tMonth:" << input.daySet[i].getMonth() << endl;
        }
        return out;
    }
    
    bool DayofYearSet :: operator==(const DayofYearSet& other)const{
        
        if(setSize != other.size())
            return false;


        for(int i = 0; i < other.size();i++){
            if(!isThere(other[i]) ){return false;}
        }
        return true;
    }

    bool DayofYearSet :: operator!=(const DayofYearSet& other)const{
        
        if( *this == other) return false;
        else return true;
    }

    const DayofYearSet DayofYearSet :: operator-(const DayofYearSet& other)const{
        
        DayofYearSet temp;

        if(empty() || other.empty()){
            return *this;
        }
        
        else{
            for(int i = 0; i<setSize ; i++){
                if(!other.isThere(daySet[i]))
                    temp.add(daySet[i]);
            }
            return temp;
        }
    }

    const DayofYearSet DayofYearSet :: operator+(const DayofYearSet& other)const{
        
        DayofYearSet temp;

        if(empty()){
            return other;
        }

        else if(other.empty()){
            return *this;
        }

        else{
            
            for(int i = 0; i<setSize;i++){
                temp.add(daySet[i]);
            }

            for(int i = 0; i<other.size();i++){
                temp.add(other[i]);
            }

            return temp;
        }
    }

    const DayofYearSet DayofYearSet :: operator^(const DayofYearSet& other)const{
        
        DayofYearSet temp;

        if(empty() || other.empty()){
            return temp;
        }

        else{
            
            for(int i = 0; i<setSize ; i++){
                if(other.isThere(daySet[i]))
                    temp.add(daySet[i]);
            }
            return temp;
        }
    }

    const DayofYearSet DayofYearSet :: operator!()const{
        int const arrMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        DayofYearSet tempSet;
        DayofYear tempDay;
        
        
        for(int i=0 ; i<12;i++){
            for(auto j = 0; j<arrMonth[i];j++){
                tempDay.setAll(j+1,i+1);
                if(!isThere(tempDay))
                    tempSet.add(tempDay);
            }
        }

        return tempSet;
    }

    DayofYearSet :: DayofYear& DayofYearSet :: operator[](int index)const{
        
        //if(index < 0 || index>=setSize){cerr << endl << "---Error: Invalid Selection---" << endl; return  }

        
        return daySet[index];
    }

    int DayofYearSet :: getTotalDoy(){
        return totalDoy;
    }

}