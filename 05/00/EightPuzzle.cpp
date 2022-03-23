
#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2D.h"
#include "EightPuzzle.h"
#include <unistd.h>



using namespace std;

namespace sBurakYasar{

void EightPuzzle :: initialize(){
    
    gameBoard.resize(3, vector<int>(3));
    
    int temp = 1;
    for(int i = 0; i<3;i++){
        for(int j=0;j<3;j++){
            gameBoard[i][j] = temp;
            temp++;
        }
    }

    gameBoard[2][2] = 0;

    for(int i=0;i<100000;i++){
        playAuto();
    }


}

void EightPuzzle :: swap(const int& row1,const int& column1,const int& row2,const int& column2){
    
    int temp = gameBoard[row1][column1];

    gameBoard[row1][column1] = gameBoard[row2][column2];
    gameBoard[row2][column2] = temp;
}

/*void EightPuzzle :: print(){
    
    int i,j,k;

    cout << "\033[2J";
    cout << "\033[1;1H";

    cout << "    A   B   C" << endl;

    

    for(i=0;i<3;i++){
        cout << "  ";
        for(k=0;k<12;k++){
            cout << "-";
        }
        cout << "-\n" << i+1 << " ";
        
        for(j=0;j<3;j++){
            
            if(gameBoard[i][j]==0)              
                cout << "|   ";
            
            else cout << "| " << gameBoard[i][j] << " ";
        }
        cout << "|\n" ;
    }
    cout << "  ";
    for(k=0;k<13;k++){
        
        cout << "-" ;
    }

    cout << "\n";
}*/

void EightPuzzle :: print(){/* If it prints weird stuff use the other print function above */
    
    if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
    }

    int i,j,k;

    cout << "\033[2J";
    cout << "\033[1;1H";

    cout << "    A   B   C" << endl;

    
    cout << "  \u250C";

    
    for(int a = 0; a<gameBoard.size();a++){
        for(k=0;k<3;k++){
            cout << "\u2500";
        }
        if(a==gameBoard.size()-1)
            break;
        cout << "\u252C";
        
    }
    
    cout << "\u2510";
    cout << endl;

    for(i=0;i<gameBoard.size();i++){
        cout << i+1 <<" ";
    
        for(j=0;j<gameBoard.size();j++){
            
            if(gameBoard[i][j]==0)              
                cout << "\u2502   ";
            
            else cout << "\u2502 " << gameBoard[i][j] << " ";
        }

        cout << "\u2502" ;

        if(i==gameBoard.size()-1)
            break;
        
        cout << endl;

        cout << "  \u251C";
        for(int a = 0; a<gameBoard.size();a++){
            for(k=0;k<3;k++){
                cout << "\u2500";
            }
            if(a==gameBoard.size()-1)
                break;
            cout << "\u253C";
            
        }

        
        cout << "\u2524";
        cout << endl;


        
    }
    cout << endl;
    cout << "  \u2514";
    
    for(int a = 0; a<gameBoard.size();a++){
        for(k=0;k<3;k++){
            cout << "\u2500";
        }
        if(a==gameBoard.size()-1)
            break;
        cout << "\u2534";        
    }

    cout << "\u2518";

    cout << endl;
}

void EightPuzzle :: playUser(const string& input){

    int rw,clmn;

    if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
    }

    if(!inputCheck(input)){return;}
    char direction = input[3];

    rw = input[0] - '0' - 1;

    cout << "rw: " << rw << endl;
    cout << "clmn: " << input[1] - 'A' << endl;


    if(input[1] >= 'a' && input[1] <= 'z'){
        clmn = input[1] - 'a';
    }

    else
        clmn = input[1] - 'A';

    

    int i,j;
    

    if(direction == 'R' || direction =='r'){ //Move Right

        for(i=clmn;i<3;i++){
        
            if(gameBoard[rw][i] == 0){
                
                for(j=i;j>clmn;j--){
                    swap(rw,j,rw,j-1);
                
                }
                
                break;
            }
        
        }
    }
            

    
        

    else if(direction == 'L' || direction =='l'){ //Move Left
            
        for(i=clmn;i>=0;i--){
        
            if(gameBoard[rw][i] == 0){
                
                for(j=i;j<clmn;j++){
                    swap(rw,j,rw,j+1);
                
                }
                break;
            }
        
        }

    }

    else if(direction == 'U' || direction =='u'){ //Move Up
            
        for(i=rw;i>=0;i--){
        
            if(gameBoard[i][clmn] == 0){
                
                for(j=i;j<rw;j++){
                    swap(j,clmn,j+1,clmn);
                
                }
                break;
            }
        
        }
            
    }
        
    else if(direction == 'D' || direction =='d'){ //Move Down
        
        for(i=rw;i<3;i++){
        
            if(gameBoard[i][clmn] == 0){
                
                for(j=i;j>rw;j--){
                    swap(j,clmn,j-1,clmn);
                
                }
                break;
            }
        
        }
    }
}

void EightPuzzle :: playUser(){
    
    while(!endGame()){
        
        if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
        }

        string input;
        print();

        cout << endl << "Please Enter Input: ";
        getline(cin,input);
        
        if(inputCheck(input)) playUser(input);
        
    }
    
}

void EightPuzzle :: playAuto(){
    int i,j;
    int rw ,clmn;
    char direction;
    char arr[4] = {'R','L','D','U'};
    bool flag = false;

    if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
    }
    
    while(!flag){
        
        rw = rand()%3;
        clmn = rand()%3;
        direction = arr[rand()%4];

        
        /* cout << "rw: " << rw << endl;
        cout << "clmn: " << clmn << endl;
        cout << "direc: " << direction << endl; */

        
    

        if(direction == 'R' || direction =='r'){ //Move Right

            for(i=clmn+1;i<3;i++){
            
                if(gameBoard[rw][i] == 0){
                    flag = true;
                    for(j=i;j>clmn;j--){
                        swap(rw,j,rw,j-1);
                    
                    }
                    
                    break;
                }
            
            }
        }
                

        
            

        else if(direction == 'L' || direction =='l'){ //Move Left
                
            for(i=clmn-1;i>=0;i--){
            
                if(gameBoard[rw][i] == 0){
                    flag = true;
                    for(j=i;j<clmn;j++){
                        swap(rw,j,rw,j+1);
                    
                    }
                    break;
                }
            
            }

        }

        else if(direction == 'U' || direction =='u'){ //Move Up
                
            for(i=rw-1;i>=0;i--){
                
                if(gameBoard[i][clmn] == 0){
                    flag = true;
                    for(j=i;j<rw;j++){
                        swap(j,clmn,j+1,clmn);
                    
                    }
                    break;
                }
            
            }
                
        }
            
        else if(direction == 'D' || direction =='d'){ //Move Down
            
            for(i=rw+1;i<3;i++){
            
                if(gameBoard[i][clmn] == 0){
                    flag = true;
                    
                    for(j=i;j>rw;j--){
                        swap(j,clmn,j-1,clmn);
                    
                    }
                    break;
                }
            
            }
        }
    }
    return;
}

void EightPuzzle :: playAutoAll(){
    while(!endGame()){
        if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
        }

        playAuto();
        print();
        usleep(100000);
    }
}

bool EightPuzzle :: inputCheck(const string& input){
    
    if(input.length()!=4){
        cerr << "\n--Invalid selection lenght, Please try again--\n";
        return false;
    }

    if(input[2] != ' '){
        cerr << "\n--Invalid selection space, Please try again--\n";
        return false;
    }

    if(input[0]-'0' < 1 || input[0] -'0' > 3){
        cerr << "\n--Invalid selection size rw, Please try again--\n";
        return false;
    }
    
    if( (input[1] < 'A' || input[1] > 'C' ) && (input[1]  < 'a' || input[1]  > 'c') ){
        cerr << "\n--Invalid selection size clmn, Please try again--\n";
        return false;
    }

    if( !(input[3] == 'D' || input[3] == 'd' || input[3] == 'U' || input[3] == 'u' || input[3] == 'r' || input[3] == 'R' || input[3] == 'L' || input[3] == 'l') ){
        cerr << "\n--Invalid selection dir, Please try again--\n";
        return false;
    }

    return true;
}

bool EightPuzzle :: endGame(){
    
    int i,j,counter=1;
    
    for(i=0;i<gameBoard.size();i++){
        for(j=0;j<gameBoard.size();j++){
            
            if(gameBoard[i][j] != counter){
                
                if(i==2 && j == 2) /*the last element has not be 9 */
                    return true;

                else 
                    return false;}
            
            counter++;
        }
    }
    return true;
}

int EightPuzzle :: boardScore(){
    
    int i,j,counter=1,score=0;
    
    for(i=0;i<gameBoard.size();i++){
        for(j=0;j<gameBoard.size();j++){
            
            if(gameBoard[i][j] != counter){

                
                if(i==2 && j == 2 && gameBoard[i][j] == 0)
                    continue;

                else
                    score++;
                }
            
            counter++;
        }
    }
    return score;
}

}
