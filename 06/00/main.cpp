#include <iostream>

#include "Iterable.h"

#include "GTUIterator.cpp"
#include "GTUIteratorConst.cpp"

#include "GTUVector.h"
#include "GTUVector.cpp"

#include "GTUSet.h"
#include "GTUSet.cpp"

#include "GTUArray.h"
#include "GTUArray.cpp"

#include <string>
#include <algorithm>

using namespace sBurakYasar;
using namespace std;


void VectorTest();
void SetTest();
void ArrayTest();


void print(int i){
    cout << i << endl;
}



int main(){
   
    VectorTest();
    SetTest();
    ArrayTest();

}


void VectorTest(){
    
    GTUVector <int> testObj;
    GTUVector <int> :: GTUIterator testIterator;
    GTUVector <int> :: GTUIteratorConst testIteratorConst;

    cout << "Vector elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){ /*It is also begin() and end() test*/
        cout << *testIterator << endl;
    }
    cout << endl << endl;

    cout << "empty function test" << endl << endl;
    if(testObj.empty()){cout << "Vector is empty" << endl << endl;}


    cout << "add function test" << endl << endl;

    testObj.add(5);
    testObj.add(10000);
    testObj.add(25);
    testObj.add(-789);

    cout << "Vector elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl << endl;


    cout << "size function test" << endl << endl;
    cout << "Size: " << testObj.size() << endl << endl;


    cout << "Vector elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;
    
    cout << "erase function test" << endl << endl;

    testObj.erase(testObj.begin());

    cout << "Vector elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;

    cout << "index operator test" << endl << endl;

    cout << "testObj[0]= " << testObj[0] << endl << endl;

    cout << "cbegin and cend function test" << endl << endl;

    cout << "print vector element" << endl << endl;
    for(testIteratorConst = testObj.cbegin();testIteratorConst != testObj.cend();testIteratorConst++){
        cout << *testIteratorConst << endl;
    }
    cout << endl;

    cout << "begin and end function test" << endl << endl;
    cout << "fill vector element with 9" << endl << endl;

    cout << "Vector elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        *testIterator = 9;
        cout << *testIterator << endl;
    }
    cout << endl;
    
    cout << "clear function test" << endl << endl;

    testObj.clear();

    cout << "Vector elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        *testIterator = 9;
        cout << *testIterator << endl;
    }
    cout << endl;


    cout << "std::sort test" << endl << endl;
    testObj.add(5);
    testObj.add(-9);
    testObj.add(37);
    testObj.add(1678);
    testObj.add(-455);
    testObj.add(-4);
    testObj.add(0);
    testObj.add(0);

    cout << "Before" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;

    sort(testObj.begin(),testObj.end());


    cout << "After" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;

    cout << "std::find test" << endl << endl;

    testIterator = find (testObj.begin(), testObj.end(), -9);
    if (testIterator != testObj.end())
        cout << "Element found in testObj: " << *testIterator << '\n';
    else
        cout << "Element not found in testObj\n";

    cout << "std::for_each test (print)" << endl << endl;

    for_each(testObj.begin(), testObj.end(), print);

    cout << "std::min_element test (print)" << endl << endl;

    testIterator = min_element(testObj.begin(), testObj.end());

    cout << "Min element is " << *testIterator <<endl << endl;

    cout << "std::remove test (-4)" << endl << endl;
    
    remove(testObj.begin(), testObj.end(), -4);
    for_each(testObj.begin(), testObj.end(), print);

    cout << "std::rotate test" << endl << endl;
    
    rotate(testObj.begin(),testObj.begin()+3,testObj.end());
    for_each(testObj.begin(), testObj.end(), print);

}


void SetTest(){
    
    GTUSet <char> testObj;
    GTUSet <char> :: GTUIterator testIterator;
    GTUSet <char> :: GTUIteratorConst testIteratorConst;

    cout << "Set elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){ /*It is also begin() and end() test*/
        cout << *testIterator << endl;
    }
    cout << endl << endl;

    cout << "empty function test" << endl << endl;
    if(testObj.empty()){cout << "Set is empty" << endl << endl;}


    cout << "add function test" << endl << endl;

    testObj.add('a');
    testObj.add('x');
    testObj.add('j');
    testObj.add('a');
    testObj.add('A');

    cout << "Set elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl << endl;


    cout << "size function test" << endl << endl;
    cout << "Size: " << testObj.size() << endl << endl;


    cout << "Set elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;
    
    cout << "erase function test" << endl << endl;

    testObj.erase(testObj.begin());

    cout << "Set elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;

    cout << "cbegin and cend function test" << endl << endl;

    cout << "print set element" << endl << endl;
    for(testIteratorConst = testObj.cbegin();testIteratorConst != testObj.cend();testIteratorConst++){
        cout << *testIteratorConst << endl;
    }
    cout << endl;
    
    cout << "clear function test" << endl << endl;

    testObj.clear();

    cout << "Set elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        *testIterator = 9;
        cout << *testIterator << endl;
    }
    cout << endl;

    cout << "intersection function test" << endl << endl;

    GTUSet <string> :: GTUIterator SetIt;

    GTUSet <string> A;
    A.add("Hi");
    A.add("Hello");
    A.add("c++");
    A.add("MavI");
    A.add("Huk");
    A.add("pH");

    cout << "Set A" << endl;
    for(SetIt = A.begin();SetIt != A.end();SetIt++){
        cout << *SetIt << endl;
    }
    cout << endl;

    
    GTUSet <string> B;
   

    B.add("Hi");
    B.add("Hello");
    B.add("java");
    B.add("c");
    B.add("CSE");
    B.add("241");

    cout << "Set B" << endl;
    for(SetIt = B.begin();SetIt != B.end();SetIt++){
        cout << *SetIt << endl;
    }
    cout << endl;

    

    GTUSet <string> interSectTest;

    interSectTest = A.intersectSet(B);

    cout << "A ^ B" << endl << endl;
    for(SetIt = interSectTest.begin();SetIt != interSectTest.end();SetIt++){
        cout << *SetIt << endl;
    }
    cout << endl;


    GTUSet <string> unionTest;

    unionTest = A.unionSet(B);

    cout << "A u B" << endl << endl;
    for(SetIt = unionTest.begin();SetIt != unionTest.end();SetIt++){
        cout << *SetIt << endl;
    }
    cout << endl;




}

void ArrayTest(){
    

    GTUArray <int,10> testObj;

    GTUArray <int,10> :: GTUIterator testIterator;
    GTUArray <int,10> :: GTUIteratorConst testIteratorConst;

    cout << "fill function test (with 4)" << endl << endl;

    testObj.fill(4);

    cout << "Array elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl << endl;


    cout << "empty function test" << endl << endl;
    if(testObj.empty()){cout << "Array is empty" << endl << endl;}
    else {cout << "Array is empty" << endl << endl;}


    cout << "index operator test" << endl << endl;

    testObj[0] = 894;
    testObj[1] = -15;
    testObj[2] = -451;
    testObj[3] = 0;
    testObj[4] = 5;
    testObj[5] = 5;
    testObj[6] = 789984;
    testObj[7] = -584879;
    testObj[8] = -4;
    testObj[9] = 1;

    cout << "Array elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl << endl;


    cout << "size function test" << endl << endl;
    cout << "Size: " << testObj.size() << endl << endl;


    cout << "Array elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;
    
    cout << "erase function test" << endl << endl;

    testObj.erase(testObj.begin());

    cout << "Array elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;

    cout << "index operator test" << endl << endl;

    cout << "testObj[0]= " << testObj[0] << endl << endl;

    cout << "cbegin and cend function test" << endl << endl;

    cout << "print array element" << endl << endl;
    for(testIteratorConst = testObj.cbegin();testIteratorConst != testObj.cend();testIteratorConst++){
        cout << *testIteratorConst << endl;
    }
    cout << endl;

    cout << "begin and end function test" << endl << endl;
    cout << "fill array element with 9" << endl << endl;

    cout << "Array elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        *testIterator = 9;
        cout << *testIterator << endl;
    }
    cout << endl;
    
    cout << "clear function test" << endl << endl;

    testObj.clear();

    cout << "Array elements" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        *testIterator = 9;
        cout << *testIterator << endl;
    }
    cout << endl;

    cout << "std::sort test" << endl << endl;
    testObj[0] = 894;
    testObj[1] = -15;
    testObj[2] = -451;
    testObj[3] = 0;
    testObj[4] = 5;
    testObj[5] = 5;
    testObj[6] = 789984;
    testObj[7] = -584879;
    testObj[8] = -4;
    testObj[9] = 1;

    cout << "Before" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;

    sort(testObj.begin(),testObj.end());


    cout << "After" << endl;
    for(testIterator = testObj.begin();testIterator != testObj.end();testIterator++){
        cout << *testIterator << endl;
    }
    cout << endl;

    cout << "std::find test" << endl << endl;

    testIterator = find (testObj.begin(), testObj.end(), -9);
    if (testIterator != testObj.end())
        cout << "Element found in testObj: " << *testIterator << '\n';
    else
        cout << "Element not found in testObj\n";

    cout << "std::for_each test (print)" << endl << endl;

    for_each(testObj.begin(), testObj.end(), print);

    cout << "std::min_element test (print)" << endl << endl;

    testIterator = min_element(testObj.begin(), testObj.end());

    cout << "Min element is " << *testIterator <<endl << endl;

    cout << "std::remove test (-4)" << endl << endl;
    
    remove(testObj.begin(), testObj.end(), -4);
    for_each(testObj.begin(), testObj.end(), print);

    cout << "std::rotate test" << endl << endl;
    
    rotate(testObj.begin(),testObj.begin()+3,testObj.end());
    for_each(testObj.begin(), testObj.end(), print);
}