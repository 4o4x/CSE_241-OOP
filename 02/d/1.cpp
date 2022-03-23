#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


typedef enum{
    emp = 0,    // Empty cells on the board 
    peg = 1,    // Pegs
    wall = -1   // Unplayable cells on the board
}board;

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
void boardSave(const string& filename,const vector < vector<board> > & map,int playerType,int numberOfMoves);
void boardLoad(const string& filename,vector < vector<board> > & map);


int main(){
    
    string x;

    //int i=0,j=15;

    vector < vector<board> > map;

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

    
    

    getline(cin,x);

    if(x.compare(0,4,"SAVE")==0){
        x.erase(0,5);
        cout << '-' << x << '-' << endl;
        boardSave(x,map,0,7);
    }

    else if(x.compare(0,4,"LOAD")==0){
        x.erase(0,5);
        cout << '-' << x << '-' << endl;
        boardLoad(x,map);
    }
    
}

void boardSave(const string& filename,const vector < vector<board> > & map,int playerType,int numberOfMoves){
    
    ofstream fout;

    fout.open(filename);

    fout << playerType<<endl;
    fout << numberOfMoves << endl;
    fout << map.size()-2 << " " << map[0].size()-2 << endl;

    int i,j;

    for(i=1;i<map.size() -1 ;i++){

        //cout << i; // printing number for rows

        for(j=1;j<map[i].size()-1;j++){
                    
            switch (map[i][j]){         // printing board
                
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
    
    int row,col,numberOfMoves,playerType,i,j,k;
    string readStr;


    ifstream fin;

    fin.open(filename);

    fin >> playerType
        >> numberOfMoves
        >> row
        >> col
    ;

    getline(fin,readStr);
    readStr.clear();
    

    vector<vector<board>> loadBoard(row+2, vector<board> (col+2, wall));

    for(i=1;i<=row;i++){
        
        getline(fin,readStr);

        cout<< "girdim: "<<readStr << endl;
        
        for(j=0;j<readStr.length();j++){
            
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

    //print_board(map);

    //boardSave("3.txt",map,0,7);

    /*if(playerType == 0)
        player_human(map,numberOfMoves);
    else
        player_cpu(map,numberOfMoves);
    
    return;*/
    

}



