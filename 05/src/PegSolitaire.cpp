
#include <vector>
#include <string>
#include <iostream>
#include "PegSolitaire.h"
#include <unistd.h>
//#include "BoardGame2D.h"

using namespace std;

namespace sBurakYasar{

void PegSolitaire :: playUser(const string& input){
    
    bool flag = true;
    int rw;
    int clmn;

    if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
    }
    
    
    if(!inputCheck(input)){return;}
    char direction = input[3];

    rw = input[0] - '0';


    if(input[1] >= 'a' && input[1] <= 'z'){
        clmn = input[1] - 'a' + 1;
    }

    else
        clmn = input[1] - 'A' + 1;

    
    if(direction == 'R' || direction =='r'){ //Move Right
 
        if(gameBoard[rw][clmn].getCellType() != peg)
            flag = false;
        else if(gameBoard[rw][clmn+1].getCellType() != peg)
            flag = false;
        else if (gameBoard[rw][clmn+2].getCellType() != emp)
            flag = false;
        else{
            gameBoard[rw][clmn].setCell(emp);
            gameBoard[rw][clmn+1].setCell(emp);
            gameBoard[rw][clmn+2].setCell(peg);
        }
        
    }

    else if(direction == 'L' || direction =='l'){ //Move Left

        if(gameBoard[rw][clmn].getCellType() != peg)
            flag = false;
        else if(gameBoard[rw][clmn-1].getCellType() != peg)
            flag = false;
        else if (gameBoard[rw][clmn-2].getCellType() != emp)
            flag = false;
        else{
            gameBoard[rw][clmn].setCell(emp);
            gameBoard[rw][clmn-1].setCell(emp);
            gameBoard[rw][clmn-2].setCell(peg);
            
        }
        
    }

    else if(direction == 'U' || direction =='u'){ //Move Up

        if(gameBoard[rw][clmn].getCellType() != peg)
            flag = false;
        else if(gameBoard[rw-1][clmn].getCellType() != peg)
            flag = false;
        else if (gameBoard[rw-2][clmn].getCellType() != emp)
            flag = false;
        else{
            gameBoard[rw][clmn].setCell(emp);
            gameBoard[rw-1][clmn].setCell(emp);
            gameBoard[rw-2][clmn].setCell(peg);
            
        }
        
    }
    
    else if(direction == 'D' || direction =='d'){ //Move Down

        if(gameBoard[rw][clmn].getCellType() != peg)
            flag = false;
        else if(gameBoard[rw+1][clmn].getCellType() != peg)
            flag = false;
        else if (gameBoard[rw+2][clmn].getCellType() != emp)
            flag = false;
        else{
            gameBoard[rw][clmn].setCell(emp);
            gameBoard[rw+1][clmn].setCell(emp);
            gameBoard[rw+2][clmn].setCell(peg);
            
        }

    }   

    else
        flag = false;
    
    if(!flag){
        cerr << "\n--Invalid selection, Please try again--\n";
    }
}

void PegSolitaire :: playUser(){
    
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

void PegSolitaire :: playAuto(){
    
    int rw ,clmn;
    char direction;
    char arr[4] = {'R','L','D','U'};
    bool flag = false;

    if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
    }
    
    
    while(!flag){
        
        rw = 1 + rand()%(gameBoard.size()-2);
        clmn = 1 + rand()%(gameBoard[0].size()-2);
        direction = arr[rand()%4];
        

        

        if(direction == 'R' || direction =='r'){ //Move Right
    
            if(gameBoard[rw][clmn].getCellType() != peg)
                continue;
            else if(gameBoard[rw][clmn+1].getCellType() != peg)
                continue;
            else if (gameBoard[rw][clmn+2].getCellType() != emp)
                continue;
            else{
                gameBoard[rw][clmn].setCell(emp);
                gameBoard[rw][clmn+1].setCell(emp);
                gameBoard[rw][clmn+2].setCell(peg);
                flag = true;
            }
            
        }

        else if(direction == 'L' || direction =='l'){ //Move Left

            if(gameBoard[rw][clmn].getCellType() != peg)
                continue;
            else if(gameBoard[rw][clmn-1].getCellType() != peg)
                continue;
            else if (gameBoard[rw][clmn-2].getCellType() != emp)
                continue;
            else{
                gameBoard[rw][clmn].setCell(emp);
                gameBoard[rw][clmn-1].setCell(emp);
                gameBoard[rw][clmn-2].setCell(peg);
                flag = true;
            }
            
        }

        else if(direction == 'U' || direction =='u'){ //Move Up

            if(gameBoard[rw][clmn].getCellType() != peg)
                continue;
            else if(gameBoard[rw-1][clmn].getCellType() != peg)
                continue;
            else if (gameBoard[rw-2][clmn].getCellType() != emp)
                continue;
            else{
                gameBoard[rw][clmn].setCell(emp);
                gameBoard[rw-1][clmn].setCell(emp);
                gameBoard[rw-2][clmn].setCell(peg);
                flag = true;
            }
            
        }
        
        else if(direction == 'D' || direction =='d'){ //Move Down

            if(gameBoard[rw][clmn].getCellType() != peg)
                continue;
            else if(gameBoard[rw+1][clmn].getCellType() != peg)
                continue;
            else if (gameBoard[rw+2][clmn].getCellType() != emp)
                continue;
            else{
                gameBoard[rw][clmn].setCell(emp);
                gameBoard[rw+1][clmn].setCell(emp);
                gameBoard[rw+2][clmn].setCell(peg);
                flag = true;
            }

        }   
    }
}

void PegSolitaire :: playAutoAll(){
    while(!endGame()){
        
        if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
        }

        usleep(500000);
        print();
        playAuto();
    }
    print();
}

int PegSolitaire :: boardScore(){
    
    int i,j,result=0;
    
    for(i=1;i<gameBoard.size()-1;i++){ 
        for(j=0;j<gameBoard[i].size()-1;j++){
            if(gameBoard[i][j].getCellType() == peg)
                result++;
        }
    }

    return result;
}

bool PegSolitaire :: endGame(){
    int i,j;

    //checks if there are any playable moves left in the rows
    for(i=1;i<gameBoard.size()-1;i++){ 
        for(j=0;j<gameBoard[i].size()-1;j++){
            if(gameBoard[i][j].getCellType() == emp && gameBoard[i][j+1].getCellType()==peg && gameBoard[i][j+2].getCellType()==peg)
                return false;
            else if(gameBoard[i][j].getCellType() == peg && gameBoard[i][j+1].getCellType()==peg && gameBoard[i][j+2].getCellType()==emp)
                return false;
        }
    }

    //checks if there are any playable moves left in the columns
    for(j=1;j<gameBoard[0].size()-1;j++){ 
        for(i=0;i<gameBoard.size()-1;i++){
            if(gameBoard[i][j].getCellType() == emp && gameBoard[i+1][j].getCellType()==peg && gameBoard[i+2][j].getCellType()==peg)
                return false;
            else if(gameBoard[i][j].getCellType() == peg && gameBoard[i+1][j].getCellType()==peg && gameBoard[i+2][j].getCellType()==emp)
                return false;
        }
    }
    return true;
}

void PegSolitaire :: initialize(){
    
    int clmn = 11;
    int rw = 11;

    gameBoard.clear();
    gameBoard.resize(rw, vector<Cell>(clmn));

    int i,j,k;

    for(i=0;i<rw;i++){
        
        for(j=0;j<clmn;j++){
            gameBoard[i][j].setCell(wall);
        }

    }

    for(i=1;i<4;i++){
        for(j=4;j<7;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=4;i<7;i++){
        for(j=1;j<clmn-1;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=7;i<10;i++){
        for(j=4;j<7;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    gameBoard[5][5].setCell(emp,5,'A'+4);
}

/*void PegSolitaire :: print(){
    
    string dummy;
    int i,j,n;
    
    cout << "\033[2J";
    cout << "\033[1;1H";

    cout << endl <<"  ";

    for(i=0;i<gameBoard[0].size()-2;i++){  // printing letter for columns
        cout << char('A'+ i);
    }

    cout << endl;

    for(i=1;i<gameBoard.size() -1 ;i++){

        cout << i ; // printing number for rows

        for(j=0;j<gameBoard[i].size()-1;j++){
                    
            switch (gameBoard[i][j].getCellType()){         // printing board
                
                case wall:
                    cout<<" ";
                    break;
                
                case peg:
                    cout<<"P";
                    break;
                
                case emp:
                    cout<<".";
                    break;
            }
                
        }
        cout<<endl;
    }

}*/

void PegSolitaire :: print(){ /* If it prints weird stuff use the other print function above */
    
    if(gameBoard.empty()){
        cerr << "--ERROR-- :Empty Board" << endl;
        return;
    }

    string dummy;
    int i,j,n;
    
    cout << "\033[2J";
    cout << "\033[1;1H";

    cout << endl <<"   ";

    for(i=0;i<gameBoard[0].size()-2;i++){  // printing letter for columns
        cout << char('A'+ i) << " ";
    }

    cout << endl;

    for(i=1;i<gameBoard.size() -1 ;i++){

        cout << i ; // printing number for rows

        for(j=0;j<gameBoard[i].size()-1;j++){
                    
            switch (gameBoard[i][j].getCellType()){         // printing board
                
                case wall:
                    cout<< "  " ;
                    break;
                
                case peg:
                    cout<<"\033[31;31m\u25CF\033[31;0m ";
                    break;
                
                case emp:
                    cout<<"\u25CB ";
                    break;
            }
                
        }
        cout<<endl;
    }

} 

bool PegSolitaire :: inputCheck(const string& input){
    
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

void PegSolitaire :: Cell :: setCell(const typeOfCell& tCell,const int& rw, const char& clmn){
    
    cellType = tCell;
    row = rw;
    column = clmn; 
}

typeOfCell PegSolitaire :: Cell :: getCellType(){
    return cellType;
}

}