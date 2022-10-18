import java.util.ArrayList;

/**
 * DayofYearSet
 *
 * @author s.burak
 * @version 1.0.0
 * @since  2022-05-01
 */

public class DayofYearSet{
    
    static class DayOfYear{
        
        private int day;
        private int month;

        public DayOfYear(){
            day = 1;
            month = 1;
        }

        public DayOfYear(int d,int m){
            int numberOfDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

            if(m<=0 || m >12){
                //ERROR
                month = 1;
                day = 1;
                return;
            }

            else if(d<=0 || d>numberOfDay[m-1]){
                //ERROR
                month = m;
                day = 1;
                return;
            }

            else {
                month = m;
                day = d;
                return;
            }
                

        }

        public void setDay(int d){
            int numberOfDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};
            
            if(d<=0 || d>numberOfDay[month-1]){
                //ERROR
                return;
            }
            
            else day = d;
        }

        public void setMonth(int m){
            
            if(m<=0 || m >12){
                //ERROR
                return;

            }

            else month = m;

        }

        public void setAll(int d,int m){
            
            int numberOfDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

            if(m<=0 || m >12){
                return;
            }

            else if(d<=0 || d>numberOfDay[m-1]){
                return;
            }

            else {
                month = m;
                day = d;
                return;
            }

        }

        public int getDay(){
            return day;
        }
        
        public int getMonth(){
            return month;
        }


    }

    /** Constructs an empty set */

    public DayofYearSet(){
        setSize = 0;
    }

    /** 
    * Constructs a set containing the elements of the ArrayList
    * @param dayOfYearList ArrayList of DayofYear */

    public DayofYearSet(ArrayList<DayofYearSet.DayOfYear> dayOfYearList){
        setSize = 0;

        for(int i = 0;i<dayOfYearList.size();i++){
            add(dayOfYearList.get(i));
        }

    }

    /** 
    *Adds an element to the set. 
    * @param element to be added to the set
    */

    public void add(DayOfYear element){
        
        if(isThere(element))
            return;
        
        DayOfYear temp[] = new DayOfYear[size()+1];

        for(int i=0;i<size();i++){
            temp[i] = setArr[i];
        }

        temp[size()] = element;
        
        setArr = temp;

        setSize++;

        liveDays++;
        
    }

    /** Removes last element from the set. */

    public void remove(){
        
        DayOfYear temp[] = new DayOfYear[size()-1];
        
        for(int i=0;i<size()-1;i++){
            temp[i] = setArr[i];
        }
    
        setArr = temp;

        setSize--;

        liveDays--;
        
    }

    /**
    * Removes the element at the specified position in this set.
    * @param index of the element to be removed
     */
    public void remove(int index){
        
        DayOfYear temp[] = new DayOfYear[size()-1];
        
        for(int i=0,j=0;i<size();i++,j++){
            
            if(i==index){
                j--;
                continue;
            }

            temp[j] = setArr[i];
        }
    
        setArr = temp;

        setSize--;

        liveDays--;
        
    }

    /** 
    * Prints DayofYearSet details. 
    * @return string representation of this set*/

    public String toString(){
        
        if(size() ==0)
        return "Set is empty\n";
        
        String strOutput = "";

        for(int i = 0; i<size();i++){
            strOutput += "Element " + i + "  ->   Day:" + setArr[i].getDay() + "   Month:"+ setArr[i].getMonth()+"\n";
        }

        return strOutput;
    }

    /** 
    * Takes another DayofYearSet and compares with this. 
    * @param obj other set to compare with this set
    * @return true if their elements are equal regardless of the keeping order ,otherwise false*/

    public boolean equals(Object obj){
        
        if(obj==this)
            return true;
        
        if((obj.getClass() != this.getClass()))
            return false;
        
        DayofYearSet other = (DayofYearSet) obj;


        for(int i=0;i<size();i++){
            if(!other.isThere(setArr[i])){
                return false;
            }
        }
        return true;
    }

    /** 
    * Returns the complement of this set
    * @return complement of set*/

    public DayofYearSet complement(){
        int numberOfDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};

        DayofYearSet tempSet = new DayofYearSet();
        
        
        
        for(int i=0 ; i<12;i++){
            for(int j = 0; j<numberOfDay[i];j++){
                DayOfYear tempDay = new DayOfYear(j+1,i+1);
                
                if(!isThere(tempDay))
                    tempSet.add(tempDay);
            }
        }

        return tempSet;
    }

    /** 
    * Takes another DayofYearSet and returns the union of these two sets
    * @param other the set to be union with this set 
    * @return union of two set
    
    
     */
    public DayofYearSet union(DayofYearSet other){
        
        DayofYearSet temp = new DayofYearSet();

        if(empty()){
            return other.copy();
        }

        else if(other.empty()){
            return copy();
        }

        else{
            
            for(int i = 0; i<setSize;i++){
                temp.add(setArr[i]);
            }

            for(int i = 0; i<other.size();i++){
                temp.add(other.setArr[i]);
            }

            return temp;
        }
    }

    /** 
    *Takes another DayofYearSet and returns the intesection of these two sets
    * @param other the set to be intersection with this set 
    * @return intersection of two set*/
    public DayofYearSet intersection(DayofYearSet other){
        
        DayofYearSet temp = new DayofYearSet();

        if(empty() || other.empty()){
            return temp;
        }

        else{
            
            for(int i = 0; i<setSize ; i++){
                if(other.isThere(setArr[i]))
                    temp.add(setArr[i]);
            }
            return temp;
        }
    }

    /** 
    *Takes another DayofYearSet and returns the difference of these two sets 
    * @param other the set to be difference with this set 
    * @return difference of two set*/


    public DayofYearSet difference(DayofYearSet other){
        
        DayofYearSet temp = new DayofYearSet();

        if(empty() || other.empty()){
            return copy();
        }
        
        else{
            
            for(int i = 0; i<setSize ; i++){
                if(!other.isThere(setArr[i]))
                    temp.add(setArr[i]);
            }
            
            return temp;
        }
    
    }

    private DayofYearSet copy(){
        
        DayofYearSet tempSet = new DayofYearSet();
        
        for(int i=0;i<size();i++){
            tempSet.add(setArr[i]);
        }

        return tempSet;
    }

    /** 
    * Returns the number of elements. 
    * @return number of elements */

    public int size(){
        return setSize;
    }

    /** Checks if set is empty. 
    * @return true if there is no element in the set ,otherwise false*/

    public boolean empty(){
        if(setSize == 0)
            return true;
        else return false;
    }

    protected void finalize(){
        liveDays = liveDays - size();
    }


    private boolean isThere(DayOfYear element){
        for(int i=0;i<size();i++){
            if(setArr[i].getDay() == element.getDay() && setArr[i].getMonth() == element.getMonth()){
                return true;
            }
        }

        return false;
    }

    /** 
    *returns the total number of DayOfYear objects alive in all the sets. 
    *@return the total number of DayOfYear objects alive in all the sets. */

    public static int numberOfLiveDay(){
        return liveDays;
    }

    public static int liveDays = 0;
    private DayOfYear[] setArr;
    private int setSize;
    
}