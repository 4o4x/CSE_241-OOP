#include <iostream>
#include <vector>
#include <string>

/* These are for generating random numbers*/
#include <ctime>
#include <cstdlib>

using namespace std;

/*Board Cell Type*/
typedef enum{
    emp = 0,    // Empty cells on the board 
    peg = 1,    // Pegs
    wall = -1   // Unplayable cells on the board
}board;

/* Types of board to assign*/

void variant_1(vector < vector<board> > &map);
void variant_2(vector < vector<board> > &map);
void variant_3(vector < vector<board> > &map);
void variant_4(vector < vector<board> > &map);
void variant_5(vector < vector<board> > &map);
void variant_6(vector < vector<board> > &map);


int variant_selection(vector < vector<board> > &map); // It asks the user which type of board to play on

int player_selection(); //It asks the user whether the computer or the player is playing 


void player_human(vector < vector<board> > &map); // It takes command from user and plays on board

void player_cpu(vector < vector<board> > &map); // It plays randomly on the board until there are no pegs to move legally


void print_board(vector < vector<board> > &map); // It prints the game board


int game_move(vector < vector<board> > &map,int column,int row, char direction); // It takes commands and if it is legal executes the command

bool finish_test(vector < vector<board> > &map); // It checks if the game is over

int score(vector < vector<board> > &map); // It counts how many pegs left on board and return it



int main(){
    
    srand(time(NULL));

    vector < vector<board> > map;
    variant_selection(map);

    if(player_selection() == 0)
        player_human(map);
    else
        player_cpu(map);

    return 0;
    
}

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

void variant_6(vector < vector<board> > &map){
    
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
    

    switch(direction){
        
        /* */
        case 'R':

        

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
        break ;
    

        case 'L':

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
        break ;

        case 'U':

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
        break ;

        case 'D':

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
        break ;


    }
    return 0;
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
            cout << "\n\tGame Over\n\n\tYour Score: " << score(map)<<endl;
            return;
        }

        print_board(map);

        cout << "\n\n--------------------------------\n Your Move: ";

        cin >> input;

        if(input.size()!=4)
            continue;

        
        
        game_move(map,input[0]-'a'+1,input[1]-'0',input[3]);

        
        
    }
}
void player_cpu(vector < vector<board> > &map){
    
    print_board(map);

    string direction= "RLUD";



    while(!finish_test(map)){
    
        if(game_move(map,rand()%(map[0].size()-2)+1,rand()%(map[0].size()-2)+1,direction[rand()%4])==0){
            print_board(map);
            cout<<"\n---------------------------------------------------\n";
        }
    }

    cout    << "\n\t--------------"
            << "\n\t|  Game Over   |"
            << "\n\t| Your Score:" << score(map)<< " |" 
            << "\n\t--------------" << "\n\n\n";
    
}