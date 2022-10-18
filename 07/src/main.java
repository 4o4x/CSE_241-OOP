import java.util.ArrayList;
import java.io.FileWriter;
import java.io.IOException;   


public class main{
    
    public static void main(String[] args){
        
        /*DayOfYear Tests*/
        
        /*Default Constructor Tests*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear Default Constructor Test 1");
        
        DayofYearSet.DayOfYear defTest1 = new DayofYearSet.DayOfYear();
        
        System.out.printf("\nDay: %d   Month: %d\n",defTest1.getDay(),defTest1.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear Default Constructor Test 2");
        
        DayofYearSet.DayOfYear defTest2 = new DayofYearSet.DayOfYear();
        
        System.out.printf("\nDay: %d   Month: %d\n",defTest2.getDay(),defTest2.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*Constructor Tests with parameter */

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear Constructor Tests with parameter 1");
        
        DayofYearSet.DayOfYear defTest3 = new DayofYearSet.DayOfYear(5,7);
        
        System.out.printf("\nDay: %d   Month: %d\n",defTest3.getDay(),defTest3.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear Constructor Tests with parameter 2");
        
        DayofYearSet.DayOfYear defTest4 = new DayofYearSet.DayOfYear(30,8);
        
        System.out.printf("\nDay: %d   Month: %d\n",defTest4.getDay(),defTest4.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*Setter Test */

        DayofYearSet.DayOfYear setTest = new DayofYearSet.DayOfYear();

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear setDay Test 1");
        
        setTest.setDay(17);
        
        System.out.printf("\nDay: %d   Month: %d\n",setTest.getDay(),setTest.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear setDay Test 2");
    
        setTest.setDay(28);
        
        System.out.printf("\nDay: %d   Month: %d\n",setTest.getDay(),setTest.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");


        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear setMonth Test 1");
    
        setTest.setMonth(3);
        
        System.out.printf("\nDay: %d   Month: %d\n",setTest.getDay(),setTest.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear setMonth Test 2");
    
        setTest.setMonth(11);
        
        System.out.printf("\nDay: %d   Month: %d\n",setTest.getDay(),setTest.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear setAll Test 1");
    
        setTest.setAll(7,7);
        
        System.out.printf("\nDay: %d   Month: %d\n",setTest.getDay(),setTest.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYear setAll Test 2");
    
        setTest.setAll(25,12);
        
        System.out.printf("\nDay: %d   Month: %d\n",setTest.getDay(),setTest.getMonth()); /* Also testing getters*/
        System.out.println("----------------------------------------------");


        /*DayofYearSet Tests*/

        /*Default Constructor Tests*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet Default Constructor Test 1");

        DayofYearSet testDefaultConstructor1 = new DayofYearSet();

        System.out.println(testDefaultConstructor1);
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet Default Constructor Test 2");

        DayofYearSet testDefaultConstructor2 = new DayofYearSet();
        
        System.out.println(testDefaultConstructor2);
        System.out.println("----------------------------------------------");

        /*ArrayList Constructor Tests*/

        DayofYearSet.DayOfYear element1 = new DayofYearSet.DayOfYear(5,4);
        DayofYearSet.DayOfYear element2 = new DayofYearSet.DayOfYear(14,2);
        DayofYearSet.DayOfYear element3 = new DayofYearSet.DayOfYear(29,3);
        DayofYearSet.DayOfYear element4 = new DayofYearSet.DayOfYear(7,1);
        DayofYearSet.DayOfYear element5 = new DayofYearSet.DayOfYear(14,5);
        DayofYearSet.DayOfYear element6 = new DayofYearSet.DayOfYear(9,4);
        DayofYearSet.DayOfYear element7 = new DayofYearSet.DayOfYear(4,8);
        DayofYearSet.DayOfYear element8 = new DayofYearSet.DayOfYear(30,12);

        ArrayList<DayofYearSet.DayOfYear> list1 = new ArrayList<DayofYearSet.DayOfYear>();
        ArrayList<DayofYearSet.DayOfYear> list2 = new ArrayList<DayofYearSet.DayOfYear>();

        list1.add(element1);
        list1.add(element2);
        list1.add(element3);
        list1.add(element4);

        list2.add(element5);
        list2.add(element6);
        list2.add(element7);
        list2.add(element8);



        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet ArrayList Constructor Test 1");

        DayofYearSet testArListConstructor1 = new DayofYearSet(list1);

        System.out.println(testArListConstructor1);
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet ArrayList Constructor Test 2");

        DayofYearSet testArListConstructor2 = new DayofYearSet(list2);
        
        System.out.println(testArListConstructor2);
        System.out.println("----------------------------------------------");


        /*Equals() Tests*/

        DayofYearSet eqTest1 = new DayofYearSet(list1);
        DayofYearSet eqTest2 = new DayofYearSet(list2);
        DayofYearSet eqTest3 = new DayofYearSet(list1);

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet Equals() Test 1");

        if(eqTest1.equals(eqTest2)) System.out.println("Sets are equal");
        else System.out.println("Sets are not equal");
        System.out.println("----------------------------------------------");

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet Equals() Test 2");

        if(eqTest1.equals(eqTest3)) System.out.println("Sets are equal");
        else System.out.println("Sets are not equal");
        System.out.println("----------------------------------------------");

        
        /*add() Tests*/

        DayofYearSet testobj1= new DayofYearSet();

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet add() Test 1\n");

        System.out.println("Before\n------\n"+testobj1);
        testobj1.add(element1);
        System.out.println("\nAfter\n-----\n"+testobj1);

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet add() Test 2 (same element)\n");

        System.out.println("Before\n------\n"+testobj1);
        testobj1.add(element1);
        System.out.println("\nAfter\n-----\n"+testobj1);


        /*remove() Tests*/

        testobj1.add(element2);
        testobj1.add(element3);
        testobj1.add(element4);
        testobj1.add(element5);
        testobj1.add(element6);
        testobj1.add(element7);
        
        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet remove() Test 1\n");

        System.out.println("Before\n------\n"+testobj1);
        testobj1.remove();
        System.out.println("\nAfter\n-----\n"+testobj1);

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet remove() Test 2\n");

        System.out.println("Before\n------\n"+testobj1);
        testobj1.remove();
        System.out.println("\nAfter\n-----\n"+testobj1);

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet remove() with index Test 1\n");

        System.out.println("Before\n------\n"+testobj1);
        testobj1.remove(1);
        System.out.println("\nAfter\n-----\n"+testobj1);

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet remove() with index Test 2\n");

        System.out.println("Before\n------\n"+testobj1);
        testobj1.remove(0);
        System.out.println("\nAfter\n-----\n"+testobj1);

        /*size() Tests*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet set() Test 1\n");
        System.out.println(testobj1+"\nSize:"+ testobj1.size());

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet set() Test 1\n");
        testobj1.remove();
        System.out.println(testobj1+"\nSize:"+ testobj1.size());


        /*Set operation test */

        DayofYearSet testSetA = new DayofYearSet(list1);
        DayofYearSet testSetB = new DayofYearSet(list2);
        testSetB.remove();
        testSetB.remove();
        testSetB.add(element2);
        

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet union() Test 1\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("Set B:\n" + testSetB);

        System.out.println("A union B:\n"+testSetA.union(testSetB));

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet union() Test 2\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("Set B:\n" + testSetA);

        System.out.println("A union B:\n"+testSetA.union(testSetA));


        /*--------------------------------------------------------------------------------*/


        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet intersection() Test 1\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("Set B:\n" + testSetB);

        System.out.println("A intersection B:\n"+testSetA.intersection(testSetB));

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet intersection() Test 2\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("Set B:\n" + testSetA);

        System.out.println("A intersection B:\n"+testSetA.intersection(testSetA));

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet difference() Test 1\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("Set B:\n" + testSetB);

        System.out.println("A difference B:\n"+testSetA.difference(testSetB));

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet difference() Test 2\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("Set B:\n" + testSetA);

        System.out.println("A difference B:\n"+testSetA.difference(testSetA));

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet complement() Test 1\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("complement A:\n" + testSetA.complement());

        

        /*--------------------------------------------------------------------------------*/

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet complement() Test 2\n");
        System.out.println("Set A:\n" + testSetA);
        System.out.println("complement of complement A:\n" + (testSetA.complement()).complement());
        
        System.gc(); /* Calling garbage collector*/

        /*Static function test */
        

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet numberOfLiveDays() Test 1\n");

        System.out.println("Before add: " + DayofYearSet.numberOfLiveDay());
        testSetA.add(element8);
        System.out.println("After add: " + DayofYearSet.numberOfLiveDay());

        System.out.println("----------------------------------------------");
        System.out.println("DayofYearSet numberOfLiveDays() Test 2\n");

        System.out.println("Before remove: " + DayofYearSet.numberOfLiveDay());
        testSetA.remove();
        System.out.println("After remove: " + DayofYearSet.numberOfLiveDay());


        /*De Morgan Tests*/
        System.out.println("----------------------------------------------");
        System.out.println("De Morgan Test\n");
        
        DayofYearSet.DayOfYear element9  = new DayofYearSet.DayOfYear(9,7);
        DayofYearSet.DayOfYear element10 = new DayofYearSet.DayOfYear(14,8);
        DayofYearSet.DayOfYear element11 = new DayofYearSet.DayOfYear(1,4);
        DayofYearSet.DayOfYear element12 = new DayofYearSet.DayOfYear(30,12);

        DayofYearSet s1 = new DayofYearSet();
        DayofYearSet s2 = new DayofYearSet();
        DayofYearSet s3 = new DayofYearSet();
        DayofYearSet s4 = new DayofYearSet();
        DayofYearSet s5 = new DayofYearSet();

        s1.add(element1);
        s1.add(element2);
        s1.add(element3);
        s1.add(element4);
        s1.add(element5);
        s1.add(element6);

        s2.add(element7);
        s2.add(element10);
        s2.add(element1);

        s3.add(element2);
        s3.add(element4);
        s3.add(element6);
        s3.add(element8);
        s3.add(element10);
        s3.add(element12);

        s4.add(element11);
        
        if( ((s1.union(s2).complement()).equals( (s1.complement()).union(s2.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");

        if( ((s1.union(s3).complement()).equals( (s1.complement()).union(s3.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");

        if( ((s1.union(s4).complement()).equals( (s1.complement()).union(s4.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");

        if( ((s1.union(s5).complement()).equals( (s1.complement()).union(s5.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");



        if( ((s2.union(s3).complement()).equals( (s2.complement()).union(s3.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");

        if( ((s2.union(s4).complement()).equals( (s2.complement()).union(s4.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");

        if( ((s2.union(s5).complement()).equals( (s3.complement()).union(s5.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");



        if( ((s3.union(s4).complement()).equals( (s3.complement()).union(s4.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");

        if( ((s3.union(s5).complement()).equals( (s3.complement()).union(s5.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");

        

        if( ((s4.union(s5).complement()).equals( (s4.complement()).union(s5.complement()) ) )) 
        System.out.println("True"); else System.out.println("False");
         
        System.out.println("----------------------------------------------");

        
        
        
        try {  
            
            FileWriter fwrite1 = new FileWriter("set1.txt");
            fwrite1.write(s1.toString()); 
            fwrite1.close();

            FileWriter fwrite2 = new FileWriter("set2.txt");
            fwrite2.write(s2.toString()); 
            fwrite2.close();

            FileWriter fwrite3 = new FileWriter("set3.txt");
            fwrite3.write((s2.complement()).toString()); 
            fwrite3.close();

        
        } catch (IOException e) {  
            
            System.out.println("Error");  
        } 

        


        System.gc();



    }

}

