#include <iostream>
#include <vector>

using namespace std;

namespace sBurakYasar{

    class DayofYearSet{

        public:

        class DayofYear{
            
            public:

            /*Default constructor*/
            DayofYear(int d =1 , int m=1); 
             
            /*Setters*/
            void setDay(int d);
            void setMonth(int m);
            void setAll(int d,int m);

            /*Getters*/
            int getDay()const;
            int getMonth()const;

            /*operator overloading*/
            
            bool operator ==(const DayofYear& other);
            friend ostream& operator<<(ostream &out,const DayofYear& input);

            private:
            
            int day;
            int month;

        };
        
        /*Constructor*/
        DayofYearSet();
        explicit DayofYearSet(const vector<DayofYear> &input);

        void add(const DayofYear& input);
        int size()const;
        void remove();
        void remove(int index);
        void remove(const DayofYear& input);
        bool empty()const;

        bool isThere(const DayofYear& input)const; // checks if the input is in the set already
        
        /*operator overloading*/
        friend ostream& operator<<(ostream &out,const DayofYearSet& input);
        bool operator==(const DayofYearSet& other)const;
        bool operator!=(const DayofYearSet& other)const;

        DayofYear& operator[](int index)const;

        const DayofYearSet operator+(const DayofYearSet& other)const;
        const DayofYearSet operator-(const DayofYearSet& other)const;
        const DayofYearSet operator^(const DayofYearSet& other)const;
        const DayofYearSet operator!()const;
        const DayofYearSet operator=(const DayofYearSet& other);

        ~DayofYearSet();
        DayofYearSet(const DayofYearSet& other);
        
        static int getTotalDoy();

        private:

        DayofYear * daySet;
        int setSize;
        static int totalDoy;

        
    };


}