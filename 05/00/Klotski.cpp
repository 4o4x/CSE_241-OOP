
#include <iostream>
#include <string>
#include <vector>
#include "Klotski.h"


using namespace std;

namespace sBurakYasar{

void Klotski :: playUser(const string& input){
    
    int rw;
    int clmn;
    
    if(!inputCheck(input)){return;}
    char direction = input[3];

    rw = input[0] - '0';


    if(input[1] >= 'a' && input[1] <= 'z'){
        clmn = input[1] - 'a' + 1;
    }

    else
        clmn = input[1] - 'A' + 1;

    
}

void Klotski :: playUser(){

}

void Klotski :: playAuto(){

}

void Klotski :: playAutoAll(){

}

int Klotski :: boardScore(){

}

bool Klotski :: endGame(){

}

void Klotski :: initialize(){
    
   
}

void Klotski :: print(){

}

bool Klotski :: inputCheck(const string& input){
    
    if(input.length()!=4){
        cerr << "\n--Invalid selection lenght, Please try again--\n";
        return false;
    }

    if(input[2] != ' '){
        cerr << "\n--Invalid selection space, Please try again--\n";
        return false;
    }

    if(input[0]-'0' < 1 || input[0] -'0' > gameBoard.size()-2){
        cerr << "\n--Invalid selection size rw, Please try again--\n";
        return false;
    }
    
    if( (input[1] < 'A' || input[1] > 'A' + gameBoard[0].size()-3 ) && (input[1]  < 'a' || input[1]  > 'a' + gameBoard[0].size()-3 ) ){
        cerr << "\n--Invalid selection size clmn, Please try again--\n";
        return false;
    }

    if( !(input[3] == 'D' || input[3] == 'd' || input[3] == 'U' || input[3] == 'u' || input[3] == 'r' || input[3] == 'R' || input[3] == 'L' || input[3] == 'l') ){
        cerr << "\n--Invalid selection dir, Please try again--\n";
        return false;
    }

    return true;
}

}
