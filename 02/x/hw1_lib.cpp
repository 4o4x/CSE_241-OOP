#include <iostream>
#include <vector>
#include <string>

/* These are for generating random numbers*/
#include <ctime>
#include <cstdlib>
#include "hw1_lib.h"

using namespace std;


void print_board(vector < vector<board> > &map){
    
    int i,j,n;

    cout << endl <<"  ";

    for(i=0;i<map[0].size()-2;i++){  // printing letter for columns
        cout << char('a'+ i);
    }

    cout << endl;

    for(i=1;i<map.size() -1 ;i++){

        cout << i; // printing number for rows

        for(j=0;j<map[i].size()-1;j++){
                    
            switch (map[i][j]){         // printing board
                
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

}


void variant_1(vector < vector<board> > &map){
    
    map = {
        {wall,wall,wall,wall,wall,wall,wall,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,peg ,peg ,peg ,peg ,peg ,wall,wall},
        {wall,peg ,peg ,peg ,emp ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,wall,peg ,peg ,peg ,peg ,peg ,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,wall,wall,wall,wall,wall,wall,wall}};
}

void variant_2(vector < vector<board> > &map){
    
    map = {
        {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,emp ,peg ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall}
        };
}

void variant_3(vector < vector<board> > &map){
    
    map = {
        {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,emp ,peg ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall}
        };
}

void variant_4(vector < vector<board> > &map){
    
    map = {
        {wall,wall,wall,wall,wall,wall,wall,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,emp ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,wall,wall,wall,wall,wall,wall,wall}
        };
}

void variant_5(vector < vector<board> > &map){
    
     map = {
        {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall},
        {wall,wall,wall,wall,wall,peg ,wall,wall,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall,wall},
        {wall,peg ,peg ,peg ,peg ,emp ,peg ,peg ,peg ,peg ,wall},
        {wall,wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,wall,wall,peg ,peg ,peg ,wall,wall,wall,wall},
        {wall,wall,wall,wall,wall,peg ,wall,wall,wall,wall,wall},
        {wall,wall,wall,wall,wall,wall,wall,wall,wall,wall,wall}
        };
}

void variant_6(vector < vector<board> > &map){ /*This board is not correct :(*/
    
    map = {
        {wall,wall,wall,wall,wall,wall,wall,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,peg ,peg ,peg ,peg ,peg ,wall,wall},
        {wall,peg ,peg ,peg ,emp ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,peg ,peg ,peg ,peg ,peg ,peg ,peg ,wall},
        {wall,wall,peg ,peg ,peg ,peg ,peg ,wall,wall},
        {wall,wall,wall,peg ,peg ,peg ,wall,wall,wall},
        {wall,wall,wall,wall,wall,wall,wall,wall,wall}};
}


int game_move(vector < vector<board> > &map,int column,int row, char direction){
    

    if(direction == 'R' || direction =='r'){ //Move Right
 
        if(map[row][column] != peg)
            return -1;
        else if(map[row][column+1] != peg)
            return -1;
        else if (map[row][column+2] != emp)
            return -1;
        else{
            map[row][column] = emp;
            map[row][column+1] = emp;
            map[row][column+2] = peg;
            return 0;
        }
        
    }

    else if(direction == 'L' || direction =='l'){ //Move Left

        if(map[row][column] != peg)
            return -1;
        else if(map[row][column-1] != peg)
            return -1;
        else if (map[row][column-2] != emp)
            return -1;
        else{
            map[row][column] = emp;
            map[row][column-1] = emp;
            map[row][column-2] = peg;
            return 0;
        }
        
    }

    else if(direction == 'U' || direction =='u'){ //Move Up

        if(map[row][column] != peg)
            return -1;
        else if(map[row-1][column] != peg)
            return -1;
        else if (map[row-2][column] != emp)
            return -1;
        else{
            map[row][column] = emp;
            map[row-1][column] = emp;
            map[row-2][column] = peg;
            return 0;
        }
        
    }
    
    else if(direction == 'D' || direction =='d'){ //Move Down

        if(map[row][column] != peg)
            return -1;
        else if(map[row+1][column] != peg)
            return -1;
        else if (map[row+2][column] != emp)
            return -1;
        else{
            map[row][column] = emp;
            map[row+1][column] = emp;
            map[row+2][column] = peg;
            return 0;
        }

    }   

    else
        return -1;

    
}

bool finish_test(vector < vector<board> > &map){
    int i,j;

    //checks if there are any playable moves left in the rows
    for(i=1;i<map.size()-1;i++){ 
        for(j=0;j<map[i].size()-1;j++){
            if(map[i][j] == emp && map[i][j+1]==peg && map[i][j+2]==peg)
                return false;
            else if(map[i][j] == peg && map[i][j+1]==peg && map[i][j+2]==emp)
                return false;
        }
    }

    //checks if there are any playable moves left in the columns
    for(j=1;j<map[0].size()-1;j++){ 
        for(i=0;i<map.size()-1;i++){
            if(map[i][j] == emp && map[i+1][j]==peg && map[i+2][j]==peg)
                return false;
            else if(map[i][j] == peg && map[i+1][j]==peg && map[i+2][j]==emp)
                return false;
        }
    }
    return true;
}

int score( vector < vector<board> > &map){
    
    int i,j;
    auto n=0;
    
    // counts how many pegs left
    for(i=0;i<map.size();i++){
        for(j=0;j<map[i].size();j++){
            
            if(map[i][j] == peg) n++;
            
        }
    }
    
    return n;
}

int variant_selection(vector < vector<board> > &map){
    
    int selection;

    while(true){

        cout<<"Choose Type:";
        cin>>selection;

        if(selection<=6 && selection >=1)
            break;
        else{
            cerr<<"\n--Invalid selection, Please try again--\n";
        }
        
    }

    switch(selection){

        case 1:
        variant_1(map);
        break;

        case 2:
        variant_2(map);
        break;

        case 3:
        variant_3(map);
        break;

        case 4:
        variant_4(map);
        break;

        case 5:
        variant_5(map);
        break;

        case 6:
        variant_6(map);
    }

    return 0;
        
}


int player_selection(){
    
    int player;

    while(true){
        cout<<"\nChoose Player(Human:0/Cpu:1):";
        cin >> player;
        cout <<endl;
        
        string dummy;
        getline(cin,dummy);
        
        if(player == 0)
            return 0;

        else if(player == 1)
            return 1;

        else{
            cerr <<"\n--Invalid selection, Please try again--\n";
        }

    }

    
}

void player_human(vector < vector<board> > &map,int numberOfMoves){
    
    string input;
    

    while(true){
        
        if(finish_test(map)){
            cout    << "\n\t--------------"
            << "\n\t|  Game Over   |"
            << "\n\t| Your Score:" << score(map)<< " |" 
            << "\n\t--------------" << "\n\n\n";
            return;
        }

        print_board(map);

        cout << "\n\n--------------------------------\n\nYour Move: ";
        
        getline(cin,input);

        
        if(input.size()!=4){ //check input if it is valid
            
            if(input.compare(0,4,"SAVE")==0){ // for saving
                
                input.erase(0,5); // deletes the save part from the input
                
                boardSave(input,map,0,numberOfMoves);
                cout << endl << "--SAVED--" << endl;
                
            }

            else if(input.compare(0,4,"LOAD")==0){ // for loading
                input.erase(0,5); // deletes the load part from the input
                cout << endl << "--LOADED--" << endl;
                boardLoad(input,map);
                return;
                
                
            }

            
            else
                cerr << "\n--Invalid selection, Please try again--\n";
            
            continue;
        }
            
        if(input[0]<'a'){  
            input[0] += 32; // It converts input from uppercase to lowercase
        }

        if(input[0] - 'a' +1 > map[0].size()-2 || input[0] - 'a' +1 < 1 ){ //check input if it is valid
            cerr << "\n--Invalid selection, Please try again--\n";
            continue;
        }

        if(input[1] - '0' > map.size()-2 || input[1] - '0' < 1 ){ //check input if it is valid
            cerr << "\n--Invalid selection, Please try again--\n";
            continue;
        }

        if(game_move(map,input[0]-'a'+1,input[1]-'0',input[3]) == -1){ //check input if it is valid
            cerr << "\n--Invalid selection, Please try again--\n";
            continue;
        }

        numberOfMoves++;
        
        
        
    }
}

void player_cpu(vector < vector<board> > &map,int numberOfMoves){
    
    print_board(map);

    string direction= "RLUD"; // for random direction
    string input;

    

   

    while(!finish_test(map)){

        cout << "\nPress enter to move: ";
        getline(cin,input);
        
        

        if(input.size()!=4){ //check input if it is valid
            
            if(input.compare(0,4,"SAVE")==0){ // for saving
                
                input.erase(0,5); // deletes the save part from the input
                
                boardSave(input,map,0,numberOfMoves);
                cout << endl << "--SAVED--" << endl;
                
            }

            else if(input.compare(0,4,"LOAD")==0){ // for loading
                input.erase(0,5); // deletes the load part from the input
                cout << endl << "--LOADED--" << endl;
                boardLoad(input,map);
                return;
                
                
            }
        }

        while(game_move(map,rand()%(map[0].size()-2)+1,rand()%(map.size()-2)+1,direction[rand()%4])!=0){
            // sends random input to function until input is valid
        }
        numberOfMoves++;
        cout<<"\n---------------------------------------------------\n";
        print_board(map);
        cout<<"\n---------------------------------------------------\n";
    }

    cout    << "\n\t--------------"
            << "\n\t|  Game Over   |"
            << "\n\t| Your Score:" << score(map)<< " |" 
            << "\n\t--------------" << "\n\n\n";
    
}

void boardSave(const string& filename,const vector < vector<board> > & map,int playerType,int numberOfMoves){
    
    ofstream fout;

    fout.open(filename);

    fout << playerType<<endl; //saves player type to file
    fout << numberOfMoves << endl; //saves number of moves to file
    fout << map.size()-2 << " " << map[0].size()-2 << endl; //saves size of board to file

    int i,j;

    for(i=1;i<map.size() -1 ;i++){ // saves gameboard to file

        

        for(j=1;j<map[i].size()-1;j++){
                    
            switch (map[i][j]){         
                
                case wall:
                    fout<<" ";
                    break;
                
                case peg:
                    fout<<"P";
                    break;
                
                case emp:
                    fout<<".";
                    break;
            }
                
        }
        fout << endl;
    }
    fout.close();
}

void boardLoad(const string& filename,vector < vector<board> > & map){
    
    int row,col,numberOfMoves,playerType,i;
    decltype (i) j;
    string readStr;


    ifstream fin;

    fin.open(filename);

    fin >> playerType //takes player type from the file
        >> numberOfMoves //takes number of moves from the file
        >> row  
        >> col // takes size of gameboard from the file
    ;

    getline(fin,readStr); // cin fix
    readStr.clear();
    

    vector<vector<board>> loadBoard(row+2, vector<board> (col+2, wall)); //temp gameboard

    for(i=1;i<=row;i++){
        
        getline(fin,readStr); // reads the game board line by line

        
        
        for(j=0;j<readStr.length();j++){ // fills gameboard row by row
            
            switch (readStr[j]){         
                
                case ' ':
                    loadBoard[i][j+1] = wall;
                    break;
                
                case 'P':
                    loadBoard[i][j+1] = peg;
                    break;
                
                case '.':
                    loadBoard[i][j+1] = emp;
                    break;
            }
        
        }
        readStr.clear();
    }

    map = loadBoard; 

    

    if(playerType == 0)
        player_human(map,numberOfMoves);
    else
        player_cpu(map,numberOfMoves);
    
    return;
    

}