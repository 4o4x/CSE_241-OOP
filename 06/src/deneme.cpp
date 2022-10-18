
/* Situation 1*/
class base1{

    class Iterator1{
    };
};

class child1 : public base1{
    
    class Iterator1 : public base1::Iterator1{

    };

};

/*Situation 2*/

class base2{
};

class Iterator2{
};

class child2 : public base2{
    class Iterator2 : public Iterator2{

    }; 
};