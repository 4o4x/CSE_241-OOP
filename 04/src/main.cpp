#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "dayofyearset.h"

using namespace std;
using namespace sBurakYasar;

void pdash();
void callByVauleTest(DayofYearSet test);
void callByReferenceTest(DayofYearSet& test);
void saveText(string textname, const DayofYearSet& set);

int main(){
    
    /*DayOfYear Tests*/

    /*cout << endl << "DayofYear Tests" << endl;
    pdash();

    /*Default Constructor Tests*/
    
    pdash();
    cout << "DayofYear Default Constructor Test 1" << endl;
    DayofYearSet :: DayofYear defTest1;
    cout << endl << "Day:" << defTest1.getDay() << endl <<  "Month:" << defTest1.getMonth() << endl; /* Also testing getters*/
    pdash();

    pdash();
    cout << "DayofYear Default Constructor Test 2" << endl;
    DayofYearSet :: DayofYear defTest2;
    cout << endl << "Day:" << defTest2.getDay() << endl <<  "Month:" << defTest2.getMonth() << endl; /* Also testing getters*/
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "DayofYear Default Constructor with Parameter Test 1" << endl;
    DayofYearSet :: DayofYear defTest3(7,8);
    cout << endl << "Day:" << defTest3.getDay() << endl <<  "Month:" << defTest3.getMonth() << endl; /* Also testing getters*/
    pdash();

    pdash();
    cout << "DayofYear Default Constructor  with Parameter Test 2" << endl;
    DayofYearSet :: DayofYear defTest4(25,2);
    cout << endl << "Day:" << defTest4.getDay() << endl <<  "Month:" << defTest4.getMonth() << endl; /* Also testing getters*/
    pdash();

    /*Setters Test*/

    pdash();
    cout << "DayofYear SetAll Test1" << endl;
    DayofYearSet :: DayofYear setTest;
    setTest.setAll(2,12);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/
    pdash();

    cout << "DayofYear SetAll Test2" << endl;
    setTest.setAll(31,8);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    cout << "DayofYear SetDay Test1" << endl;
    setTest.setDay(8);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/
    pdash();

    cout << "DayofYear SetDay Test2" << endl;
    setTest.setDay(15);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    cout << "DayofYear SetMonth Test1" << endl;
    setTest.setMonth(3);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/
    pdash();
    
    cout << "DayofYear SetMonth Test2" << endl;
    setTest.setMonth(9);
    cout << endl << "Day:" << setTest.getDay() << endl <<  "Month:" << setTest.getMonth() << endl; /* Also testing getters*/
    pdash();


    /*-------------------------------------------------------------------------------------------------*/

    /*DayofYearSet Tests*/


    /*Default Constructor Test 1*/

    pdash();
    cout <<"DayofYearSet Default Constructor Test 1" << endl;
    DayofYearSet testDefaultConstructors1;
    cout << endl << testDefaultConstructors1;
    pdash();

    /*Default Constructor Test 2*/
    pdash();
    cout << "DayofYearSet Default Constructor Test 2" << endl;
    DayofYearSet testDefaultConstructors2;
    cout << endl << testDefaultConstructors2 ;
    pdash();
    
    
    /*Vector Constructor Test 1 (without invalid dayofyears)*/
    pdash();
    cout << "DayofYearSet Vector Constructor Test 1 (without invalid dayofyears)" << endl;
    vector<DayofYearSet :: DayofYear> vConstructor1 = {DayofYearSet :: DayofYear(5,7),DayofYearSet :: DayofYear(2,9),DayofYearSet :: DayofYear(11,11),DayofYearSet :: DayofYear(30,8)};
    DayofYearSet testVectorConstructors1(vConstructor1);
    cout << endl << testVectorConstructors1 << endl;
    pdash();

    
    /*Vector Constructor Test 2 (with invalid dayofyears)
    
    pdash();
    cout << "Vector Constructor Test 2 (with invalid dayofyears)" << endl;
    vector<DayofYearSet :: DayofYear> v2 = {DayofYearSet :: DayofYear(-25,7),DayofYearSet :: DayofYear(29,2),DayofYearSet :: DayofYear(31,4),DayofYearSet :: DayofYear(1,25)}; 
    DayofYearSet testVectorConstructors2(v2);
    cout << testVectorConstructors2 << endl;
    pdash();*/


    /*Overloading Operator== and Operator!= Test*/
    
    pdash();
    cout << "DayofYearSet Overloading Operator== and Operator!= Tests" << endl;
    
    vector<DayofYearSet :: DayofYear> vEq1 = {DayofYearSet :: DayofYear(5,7),DayofYearSet :: DayofYear(2,9),DayofYearSet :: DayofYear(11,11),DayofYearSet :: DayofYear(30,8)};
    vector<DayofYearSet :: DayofYear> vEq2 = {DayofYearSet :: DayofYear(2,9),DayofYearSet :: DayofYear(30,8),DayofYearSet :: DayofYear(5,7),DayofYearSet :: DayofYear(11,11)};
    vector<DayofYearSet :: DayofYear> vEq3 = {DayofYearSet :: DayofYear(17,4),DayofYearSet :: DayofYear(8,12)};
    
    DayofYearSet testEq1(vEq1);
    DayofYearSet testEq2(vEq2);
    DayofYearSet testEq3(vEq3);

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Operator== Test 1" << endl;
    if(testEq1 == testEq2) cout << "True" << endl;
    else cout << "False" << endl;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Operator== Test 2" << endl;
    if(testEq1 == testEq3) cout << "True" << endl;
    else cout << "False" << endl;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();    
    cout << "Operator!= Test 1" << endl;
    if(testEq1 != testEq2) cout << "True" << endl;
    else cout << "False" << endl;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Operator!= Test 2" << endl;
    if(testEq1 != testEq3) cout << "True" << endl;
    else cout << "False" << endl;
    pdash();
    
     
    
    /*Add remove and size test*/

    vector<DayofYearSet :: DayofYear> vAddRemoveSize = {DayofYearSet :: DayofYear(14,2),DayofYearSet :: DayofYear(2,7),DayofYearSet :: DayofYear(9,2),DayofYearSet :: DayofYear(10,1),DayofYearSet :: DayofYear(30,3),DayofYearSet :: DayofYear(4,4)};
    DayofYearSet testAddRemoveSize(vAddRemoveSize);

    pdash();
    cout << endl << "Add Function Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.add(DayofYearSet::DayofYear(13,9));
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();

   

    pdash();
    cout << "Add Function Test 2 (Adding the element that is already in the set)" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.add(DayofYearSet::DayofYear(14,2));
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/
    
    pdash();
    cout << "Remove Function(no parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove();
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();


    pdash();
    cout << "Remove Function(no parameter) Test 2" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove();
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Remove Function(valid index parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(3);
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();
    
    pdash();
    cout << "Remove Function(invalid index parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(8);
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Remove Function(valid DayofYear parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(DayofYearSet:: DayofYear(2,7));
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();
    
    pdash();
    cout << "Remove Function(invalid DayofYear parameter) Test 1" << endl;
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove(DayofYearSet:: DayofYear(1,1));
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();
 
    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Remove Function(empty set) Test" << endl;
    testAddRemoveSize.remove(); testAddRemoveSize.remove(); testAddRemoveSize.remove();
    cout << endl << "Before:" << endl << testAddRemoveSize;
    testAddRemoveSize.remove();
    cout << endl << "After:" << endl << testAddRemoveSize;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Size Function Test 1" << endl;
    testAddRemoveSize.add(DayofYearSet:: DayofYear(1,1)); testAddRemoveSize.add(DayofYearSet:: DayofYear(3,5)); testAddRemoveSize.add(DayofYearSet:: DayofYear(22,11));
    cout << endl << "Set:" << endl << testAddRemoveSize;
    cout << "Size of test:" << endl << testAddRemoveSize.size() << endl;
    pdash();

    pdash();
    cout << "Size Function (empty set) Test 2" << endl;
    testAddRemoveSize.remove(); testAddRemoveSize.remove(); testAddRemoveSize.remove();
    
    cout << "Size of test:" << testAddRemoveSize.size() << endl;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/
    
    /*Set operation test */

    pdash();
    vector<DayofYearSet ::DayofYear> vOperation1 = {DayofYearSet::DayofYear(1,3),DayofYearSet::DayofYear(17,9),DayofYearSet::DayofYear(23,3)};
    vector<DayofYearSet ::DayofYear> vOperation2 = {DayofYearSet::DayofYear(14,1),DayofYearSet::DayofYear(17,9),DayofYearSet::DayofYear(5,7),DayofYearSet::DayofYear(1,3)};
    
    DayofYearSet testOperation1(vOperation1);
    DayofYearSet testOperation2(vOperation2);
    
    cout << "Union Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation2;

    cout << endl << "A + B:" << endl << testOperation1 + testOperation2;
    cout << endl << "B + A:" << endl << testOperation2 + testOperation1;
    pdash();


    pdash();
    cout << "Union (same set) Test 2" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation1;

    cout << endl << "A + B:" << endl << testOperation1 + testOperation1;
    cout << endl << "B + A:" << endl << testOperation1 + testOperation1;
    pdash(); 

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Diffrence Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation2;

    cout << endl << "A - B:" << endl << testOperation1 - testOperation2;
    cout << endl << "B - A:" << endl << testOperation2 - testOperation1;
    pdash();


    pdash();
    cout << "Diffrence (same set) Test 2" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation1;

    cout << endl << "A - B:" << endl << testOperation1 - testOperation1;
    cout << endl << "B - A:" << endl << testOperation1 - testOperation1;
    pdash();

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Intersection Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "Set B :" << endl << testOperation2;

    cout << endl << "A ^ B:" << endl << (testOperation1 ^ testOperation2);
    cout << endl << "B ^ A:" << endl << (testOperation2 ^ testOperation1);
    pdash();


    pdash();
    cout << "Intersection (same set) Test 2" << endl;

    cout << endl << "Set A :" << endl << (testOperation1);
    cout << endl << "Set B :" << endl << (testOperation1);

    cout << endl << "A ^ B:" << endl << (testOperation1 ^ testOperation1);
    cout << endl << "B ^ A:" << endl << (testOperation1 ^ testOperation1);
    pdash(); 

    /*-------------------------------------------------------------------------------------------------*/

    pdash();
    cout << "Complement Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;
    cout << endl << "!A:" << endl << !testOperation1;
    pdash();


    pdash();
    cout << "Complement Test 2" << endl;

    cout << endl << "Set A :" << endl << testOperation1;

    cout << endl << "!(!A):" << endl << !(!testOperation1);
    
    pdash();

    /*-------------------------------------------------------------------------------------------------*/
    
    /*Index Operator test */
    
    pdash();
    cout << "Index Operator Test 1" << endl;

    cout << endl << "Set A :" << endl << testOperation1;

    cout << endl << "Second Element of A:" << testOperation1[1];
    
    pdash();

    pdash();
    cout << "Index Operator Test 2" << endl;

    cout << endl << "Set A :" << endl << testOperation1;

    cout << endl << "First Element of A " << testOperation1[0];
    
    pdash(); 


    /*-------------------------------------------------------------------------------------------------*/

    /*Static function test */

    pdash();
    cout << "Static Function Test" << endl;

    cout << endl << "Total number of DayOfYear objects:" << DayofYearSet::getTotalDoy() << endl;
    
    testOperation1.add(DayofYearSet::DayofYear(4,4));
    testOperation1.add(DayofYearSet::DayofYear(9,8));

    cout << endl << "After adding two element:" << DayofYearSet::getTotalDoy() << endl;

    testOperation1.remove();testOperation1.remove();testOperation1.remove();

    cout << endl << "After removing three element:" << DayofYearSet::getTotalDoy() << endl;
    pdash();


    /*-------------------------------------------------------------------------------------------------*/

    /*Call by Vaule test */

    pdash();
    cout << "Call by Vaule Set Test" << endl << endl;

    vector<DayofYearSet ::DayofYear> vCall = {DayofYearSet::DayofYear(1,3),DayofYearSet::DayofYear(17,9),DayofYearSet::DayofYear(23,3)};
    DayofYearSet testCall(vCall);

    cout << "Before Set is sent to the function:" << endl << testCall << endl;
    callByVauleTest(testCall);
    cout << "After Set is sent to the function:" << endl << testCall << endl;
    pdash();


    /*Call by Reference test */

    pdash();
    cout << "Call by Reference Set Test" << endl << endl;

    cout << "Before Set is sent to the function:" << endl << testCall << endl;
    callByReferenceTest(testCall);
    cout << "After Set is sent to the function:" << endl << testCall << endl;
    pdash();

    /*De Morgan Tests*/

    pdash();

    vector<DayofYearSet ::DayofYear> vDeMorgan1 = {DayofYearSet::DayofYear(11,12)};
    vector<DayofYearSet ::DayofYear> vDeMorgan2 = {DayofYearSet::DayofYear(24,7),DayofYearSet::DayofYear(1,2),DayofYearSet::DayofYear(31,8)};
    vector<DayofYearSet ::DayofYear> vDeMorgan3 = {DayofYearSet::DayofYear(4,9),DayofYearSet::DayofYear(17,2),DayofYearSet::DayofYear(26,5),DayofYearSet::DayofYear(10,10)};
    vector<DayofYearSet ::DayofYear> vDeMorgan4 = {DayofYearSet::DayofYear(11,11),DayofYearSet::DayofYear(1,1),DayofYearSet::DayofYear(17,2),DayofYearSet::DayofYear(2,2),DayofYearSet::DayofYear(5,7)};
    
    
    DayofYearSet s1(vDeMorgan1);
    DayofYearSet s2(vDeMorgan2);
    DayofYearSet s3(vDeMorgan3);
    DayofYearSet s4(vDeMorgan4);
    DayofYearSet s5;

    cout << "De Morgan Tests" << endl << endl;
    cout << "Sets:" << endl;

    cout << "s1:" << endl << s1 << endl;
    cout << "s2:" << endl << s2 << endl;
    cout << "s3:" << endl << s3 << endl;
    cout << "s4:" << endl << s4 << endl;
    cout << "s5:" << endl << s5 << endl;

    cout << endl << "!(s1 + s2) == !s1 ^ !s2 -> ";
    if((!(s1 + s2)) == ((!s1)^(!s2))) cout << "True"; else cout << "False";

    cout << endl << "!(s1 + s3) == !s1 ^ !s3 -> ";
    if((!(s1 + s3)) == ((!s1)^(!s3))) cout << "True"; else cout << "False";

    cout << endl << "!(s1 + s4) == !s1 ^ !s4 -> ";
    if((!(s1 + s4)) == ((!s1)^(!s4))) cout << "True"; else cout << "False";

    cout << endl << "!(s1 + s5) == !s1 ^ !s5 -> ";
    if((!(s1 + s5)) == ((!s1)^(!s5))) cout << "True"; else cout << "False";

    
    cout << endl << "!(s2 + s3) == !s2 ^ !s3 -> ";
    if((!(s2 + s3)) == ((!s2)^(!s3))) cout << "True"; else cout << "False";

    cout << endl << "!(s2 + s4) == !s2 ^ !s4 -> ";
    if((!(s2 + s4)) == ((!s2)^(!s4))) cout << "True"; else cout << "False";

    cout << endl << "!(s2 + s5) == !s2 ^ !s5 -> ";
    if((!(s2 + s5)) == ((!s2)^(!s5))) cout << "True"; else cout << "False";


    cout << endl << "!(s3 + s4) == !s3 ^ !s4 -> ";
    if((!(s3 + s4)) == ((!s3)^(!s4))) cout << "True"; else cout << "False";

    cout << endl << "!(s3 + s5) == !s3 ^ !s5 -> ";
    if((!(s3 + s5)) == ((!s3)^(!s5))) cout << "True"; else cout << "False";

    
    cout << endl << "!(s4 + s5) == !s4 ^ !s5 -> ";
    if((!(s4 + s5)) == ((!s4)^(!s5))) cout << "True"; else cout << "False";

    cout << endl;

    pdash();

    saveText("s1.txt",s1);
    saveText("s2.txt",s2);
    saveText("s3.txt",!s3);
    
    

}


void pdash(){
    cout << "------------------------------------------------------" << endl;
}

void callByVauleTest(DayofYearSet test){
    cout << "Adding element to set" <<  endl;
    test.add(DayofYearSet::DayofYear(1,1));
    cout << "Set in function:" << endl << test << endl;
}

void callByReferenceTest(DayofYearSet& test){
    cout << "Adding element to set" << endl;
    test.add(DayofYearSet::DayofYear(1,1));
    cout << "Set in function:" << endl << test << endl;
}

void saveText(string textname, const DayofYearSet& set){

    ofstream fout;

    fout.open(textname);

    fout << set;

    fout.close();

    return;

    
}