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

    for(i=1;i<map.size()-1;i++){
        for(j=0;j<map[i].size()-1;j++){
            if(map[i][j] == emp && map[i][j+1]==peg && map[i][j+2]==peg)
                return false;
            else if(map[i][j] == peg && map[i][j+1]==peg && map[i][j+2]==emp)
                return false;
        }
    }

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

int score(vector < vector<board> > &map){
    int i,j,n=0;

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
            cout<<"\n--Invalid selection, Please try again--\n";
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
        cin>>player;
        
        if(player == 0)
            return 0;

        else if(player == 1)
            return 1;

        else{
            cout<<"\n--Invalid selection, Please try again--\n";
        }

    }
}

void player_human(vector < vector<board> > &map){
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

        cout << "\n\n--------------------------------\n Your Move: ";

        cin >> input;

        if(input.size()!=4){
            cout << "\n--Invalid selection, Please try again--\n";
            continue;
        }
            
        if(input[0]<'a'){  
            input[0] += 32; // It converts input from uppercase to lowercase
        }

        if(input[0] - 'a' +1 > map[0].size()-2 || input[0] - 'a' +1 < 1 ){
            cout << "\n--Invalid selection, Please try again--\n";
            continue;
        }

        if(input[1] - '0' > map.size()-2 || input[1] - '0' < 1 ){
            cout << "\n--Invalid selection, Please try again--\n";
            continue;
        }

        if(game_move(map,input[0]-'a'+1,input[1]-'0',input[3]) == -1){
            cout << "\n--Invalid selection, Please try again--\n";
            continue;
        }

        
        
    }
}
void player_cpu(vector < vector<board> > &map){
    
    print_board(map);

    string direction= "RLUD";



    while(!finish_test(map)){
    
        if(game_move(map,rand()%(map[0].size()-2)+1,rand()%(map.size()-2)+1,direction[rand()%4])==0){
            print_board(map);
            cout<<"\n---------------------------------------------------\n";
        }
    }

    cout    << "\n\t--------------"
            << "\n\t|  Game Over   |"
            << "\n\t| Your Score:" << score(map)<< " |" 
            << "\n\t--------------" << "\n\n\n";
    
}