#include <iostream>
#include <vector>
#include <string>
#include <fstream>

/* These are for generating random numbers*/
#include <ctime>
#include <cstdlib>

using namespace std;

typedef enum{
    emp,    // Empty cells on the board 
    peg,    // Pegs
    wall    // Wall
}typeOfCell;

class PegSolitaire{
    
    public:
        
        class Cell{
            
            private:
                
                typeOfCell cellType;
                char column;
                int row;

            public:
                
                void setCell(const typeOfCell& tCell,const int& rw, const char& clmn);
                void setCell(const typeOfCell& tCell) {cellType = tCell;};
                typeOfCell getCellType();
        };


        PegSolitaire(){
            boardType = 0;
            gameName = "Unknown Game";
        }

        PegSolitaire(const int& typOfbrd){
            boardType = typOfbrd;
            gameName = "Type ";
            gameName.push_back('0'+typOfbrd); 
            createBoard(boardType);
        }

        PegSolitaire(const int& typOfbrd,const string& name){
            boardType = typOfbrd;
            gameName = name;
            createBoard(boardType);
        }

        void getname() const{
            cout << gameName;
        }
        
        void printBoard(); 
        int numberOfPegs(); 
        int numberOfEmpty(); 
        inline int numberOfTakenPeg() {return numberOfEmpty() -1;}

        void play();
        void play(const int& rw,const char& clmn,const char& direction);
        bool finish_test();

        void playGame();

        void boardSave(const string& filename);
        void boardLoad(const string& filename);

        bool compareGames(PegSolitaire secondGame);

        static int numOfTotalPeg(){
            return totalPeg;
        }

        void delTotalPeg(){
            totalPeg = totalPeg - numberOfPegs();
        }
            
    
    
    private:
        
        int boardType;
        string gameName;
        vector < vector<Cell> > gameBoard;
        static int totalPeg;
        
        void createBoard(int boardType);
        
        void board1();
        void board2();
        void board3();
        void board4();
        void board5();
        void board6();

};

int PegSolitaire :: totalPeg = 0;

int main(){
    srand(time(NULL));
    PegSolitaire deneme(4);
    vector <PegSolitaire> games;
    bool flag = true;
    int menu;
    string input,dummy;

    for(int i=0; i<5 ;i++){
        games.push_back(PegSolitaire(i+1));
    }

    while(true){
        
        cout 
            << endl << "Menu\n--------"
            << endl << "1-Play an active game"
            << endl << "2-Create a new game"
            << endl << "3-Delete a game"
            << endl << "4-Auto Play"
            << endl << "5-Active games"
            << endl << "6-Compare two games"
            << endl << "7-All Pegs Number"
            << endl << "0-Exit"
            << endl << "Select: ";

        cin >> menu;
            
        if(menu == 1){
            while(true){
                
                int whichGame;
                cout << endl << "Enter game number(-1 for exit):";
                cin >> whichGame;
                getline(cin,dummy);
                
                if(whichGame==-1){
                    break;
                }

                else if( whichGame < 1 || whichGame > games.size()){
                    cerr << "\n--Invalid selection, Please try again--\n";
                    continue;
                }


                else{
                    
                    whichGame = whichGame -1;

                    while(true){
                        input.clear();
                        games[whichGame].printBoard();

                        if(games[whichGame].finish_test()){
                            cout    << "\n\t--------------"
                            << "\n\t|  Game Over   |"
                            << "\n\t| Your Score:" << games[whichGame].numberOfPegs() << " |" 
                            << "\n\t--------------" << "\n\n\n";
                            break;
                        }

                        cout << "\n\n--------------------------------\n\nYour Move(Enter for auto play/ -1 for exit ): ";
                        getline(cin,input);
                        
                        if(input.size()!=4){ //check input if it is valid
            
                            if(input.compare(0,4,"SAVE")==0){ // for saving
                                
                                input.erase(0,5); // deletes the save part from the input
                                
                                games[whichGame].boardSave(input);
                                cout << endl << "--SAVED--" << endl;
                                
                            }

                            else if(input.compare(0,4,"LOAD")==0){ // for loading
                                input.erase(0,5); // deletes the load part from the input
                                cout << endl << "--LOADED--" << endl;
                                games[whichGame].boardLoad(input);
                                //games[whichGame].printBoard();  
                            }

                            else if(input.compare("-1") == 0)
                                break;

                            else if(input.empty())
                                games[whichGame].play();

                            else
                                cerr << "\n--Invalid selection, Please try again--\n";
                            
                            continue;
                        }
                    
                        games[whichGame].play(input[1]-'0',input[0],input[3]);
                        
                    }

                }

                
            }

        }

        else if(menu == 2){
            
            int typbrd;

            while(true){
                cout << endl << "Select board type:";
                cin >> typbrd;

                if(typbrd<1 || typbrd > 5)
                    cerr << "\n--Invalid selection, Please try again--\n";
                else
                    break;
            }
            games.push_back(PegSolitaire(typbrd));
        }
        
        else if(menu == 3){
            
            int whichGame;
            cout << endl << "Enter game number(-1 for exit):";
            cin >> whichGame;

            while(true){
                
                if(whichGame == -1)
                    break;

                else if( whichGame < 1 || whichGame > games.size()){
                
                    cerr << "\n--Invalid selection, Please try again--\n";
                    continue;
                }
            }

            whichGame = whichGame -1;

            games[whichGame].delTotalPeg();

            games.erase(games.begin()+whichGame);


        }

        else if(menu == 4){
            
            PegSolitaire tempGame;
            tempGame.playGame();
        }
        
        else if(menu == 5){
            cout << endl<< "Active Games\n-------------" << endl ;
            for(int i = 0; i<games.size();i++){
                
                cout << i+1 << ". ";
                games[i].getname();
                cout << endl;
            }

        }

        else if(menu == 6){
            
            int first,second;
            cout << endl << "Enter first game number:";
            cin >> first;

            while(true){
                
                if( first< 1 || first > games.size()){
                
                    cerr << "\n--Invalid selection, Please try again--\n";
                    continue;
                }

                else break;
            }

            first = first -1;

            cout << endl << "Enter second game number(-1 for exit):";
            cin >> second;

            while(true){
                

                if( second< 1 || second > games.size()){
                
                    cerr << "\n--Invalid selection, Please try again--\n";
                    continue;
                }

                else break;
            }

            second = second -1;

            if(games[first].compareGames(games[second]))
                cout << endl << "First game has more pegs than second game"<<endl;
            else if (games[second].compareGames(games[first]))
                cout << endl << "Second game has more pegs than first game"<<endl;
            else
                cout << endl << "Both games have the same number of pegs" << endl;


        }

        else if(menu == 7){
            cout << endl << "Total peg number is " << games[0].numOfTotalPeg() << endl;
        }

        else if (menu == 0)
            return 0;
        
        else cerr << "\nInvalid selection\n";

    }
    
}


void PegSolitaire :: board1(){
    
    int clmn = 9;
    int rw = 9;

    gameBoard.clear();
    
    gameBoard.resize(rw, vector<Cell>(clmn));

    int i,j,k;

    for(i=0;i<rw;i++){
        
        for(j=0;j<clmn;j++){
            gameBoard[i][j].setCell(wall);
        }

    }

    for(i=1;i<2;i++){
        for(j=3;j<6;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=2;i<3;i++){
        for(j=2;j<7;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=3;i<6;i++){
        for(j=1;j<clmn-1;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=6;i<7;i++){
        for(j=2;j<7;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }
    for(i=7;i<8;i++){
        for(j=3;j<6;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    gameBoard[3][4].setCell(emp,3,'A'+3);

}

void PegSolitaire :: board2(){

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

void PegSolitaire :: board3(){
    int clmn = 10;
    int rw = 10;

    gameBoard.clear();
    gameBoard.resize(rw, vector<Cell>(clmn));

    int i,j,k;

    for(i=0;i<rw;i++){
        
        for(j=0;j<clmn;j++){
            gameBoard[i][j].setCell(wall);
        }

    }

    for(i=1;i<4;i++){
        for(j=3;j<6;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=4;i<7;i++){
        for(j=1;j<clmn-1;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=7;i<9;i++){
        for(j=3;j<6;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    gameBoard[5][4].setCell(emp,5,'A'+3);
}

void PegSolitaire :: board4(){
    
    int clmn = 9;
    int rw = 9;

    gameBoard.clear();
    gameBoard.resize(rw, vector<Cell>(clmn));

    int i,j,k;

    for(i=0;i<rw;i++){
        
        for(j=0;j<clmn;j++){
            gameBoard[i][j].setCell(wall);
        }

    }

    for(i=1;i<3;i++){
        for(j=3;j<6;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=3;i<6;i++){
        for(j=1;j<clmn-1;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=6;i<8;i++){
        for(j=3;j<6;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    gameBoard[4][4].setCell(emp,4,'A'+3);

}

void PegSolitaire :: board5(){
    
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

    for(i=1;i<6;i++){
        for(j=6-i;j<5+i;j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }

    for(i=6;i<10;i++){
        for(j=i-6+2;j<9-(i-6);j++){
            gameBoard[i][j].setCell(peg,i,'A'+j-1);
        }
    }


    gameBoard[5][5].setCell(emp,5,'A'+4);
}

void PegSolitaire :: Cell :: setCell(const typeOfCell& tCell,const int& rw, const char& clmn){
    
    cellType = tCell;
    row = rw;
    column = clmn; 
}

typeOfCell PegSolitaire :: Cell :: getCellType(){
    return cellType;
}

void PegSolitaire :: printBoard(){
    
    int i,j,n;

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

}

void PegSolitaire :: createBoard(int boardType){
    
    switch(boardType){

        case 1:
            board1();
            break;
        case 2:
            board2();
            break;
        case 3:
            board3();
            break;
        case 4:
            board4();
            break;
        case 5:
            board5();
            break;
    }

    totalPeg += numberOfPegs();
    
}

int PegSolitaire :: numberOfPegs(){
    
    int i,j,result=0;
    
    for(i=1;i<gameBoard.size()-1;i++){ 
        for(j=0;j<gameBoard[i].size()-1;j++){
            if(gameBoard[i][j].getCellType() == peg)
                result++;
        }
    }

    return result;

}

int PegSolitaire :: numberOfEmpty(){
    
    int i,j,result=0;
    
    for(i=1;i<gameBoard.size()-1;i++){ 
        for(j=0;j<gameBoard[i].size()-1;j++){
            if(gameBoard[i][j].getCellType() == emp)
                result++;
            
        }
    }

    return result;
}

void PegSolitaire :: play(){
    
    int rw ,clmn;
    char direction;
    char arr[4] = {'R','L','D','U'};
    bool flag = false;

    
    
    while(!flag){
        
        rw = 1 + rand()%(gameBoard.size()-2);
        clmn = 1 + rand()%(gameBoard[0].size()-2);
        direction = arr[rand()%4];
        //cout << endl << rw << endl << clmn  << endl << direction  << endl;

        

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
    totalPeg--;
    //cout << endl << rw << endl << clmn  << endl << direction  << endl;
}

void PegSolitaire :: play(const int& rw,const char& ch_clmn,const char& direction){
    
    bool flag = true;

    if(rw < 1 || rw > gameBoard.size()-2){
        cerr << "\n--Invalid selection, Please try again--\n";
        return;
    }
    
    if( (ch_clmn < 'A' || ch_clmn > 'A' + gameBoard[0].size()-3 ) && (ch_clmn < 'a' || ch_clmn > 'a' + gameBoard[0].size()-3 ) ){
        cerr << "\n--Invalid selection, Please try again--\n";
        return;
    }
    
    int clmn;

    if(ch_clmn >= 'a' || ch_clmn <= 'z'){
        clmn = ch_clmn - 'a' + 1;
    }

    else
        clmn = ch_clmn - 'A' + 1;

    
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

    else totalPeg--;
}

bool PegSolitaire :: finish_test(){
    
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

void PegSolitaire :: playGame(){
    
    int input;

    

    while(true){
        cout << endl << "Select board type:";
        cin >> input;

        if(input<1 || input > 5)
            cerr << "\n--Invalid selection, Please try again--\n";
        else
            break;
    }
    
    string dummy;
    getline (cin,dummy);

    createBoard(input);

    printBoard();

    while(!finish_test()){
        play();
        cout <<endl<<"----------------------------------" << endl; 
        printBoard();

        //cout<<endl << game1.numberOfPegs() <<  endl << game1.numberOfEmpty() << endl << game1.numberOfTakenPeg()<<endl;
    }

    cout    << "\n\t--------------"
            << "\n\t|  Game Over   |"
            << "\n\t| Your Score:" << numberOfPegs() << " |" 
            << "\n\t--------------" << "\n\n\n";
    totalPeg = totalPeg - numberOfTakenPeg();
            

}

void PegSolitaire :: boardSave(const string& filename){
    
    ofstream fout;

    fout.open(filename);

    fout << numberOfTakenPeg() << endl; //saves number of moves to file
    fout << gameBoard.size()-2 << " " << gameBoard[0].size()-2 << endl; //saves size of board to file

    int i,j;

    for(i=1;i<gameBoard.size() -1 ;i++){ // saves gameboard to file

        

        for(j=1;j<gameBoard[i].size()-1;j++){
                    
            switch (gameBoard[i][j].getCellType()){         
                
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

void PegSolitaire :: boardLoad(const string& filename){
    
    int row,col,numberOfMoves,i;
    decltype (i) j;
    string readStr;

    gameName = filename;

    ifstream fin;

    fin.open(filename);

    fin 
        >> numberOfMoves //takes number of moves from the file
        >> row  
        >> col // takes size of gameboard from the file
    ;

    getline(fin,readStr); // cin fix
    readStr.clear();
    
    totalPeg = totalPeg - numberOfPegs();

    gameBoard.clear();

    gameBoard.resize(row+2, vector<Cell> (col+2)); //temp gameboard

    for(i=1;i<=row;i++){
        
        getline(fin,readStr); // reads the game board line by line

        gameBoard[i][0].setCell(wall);
        
        for(j=0;j<readStr.length();j++){ // fills gameboard row by row
            
            switch (readStr[j]){         
                
                case ' ':
                    gameBoard[i][j+1].setCell(wall);
                    break;
                
                case 'P':
                    gameBoard[i][j+1].setCell(peg,i,'A' + j - 2);
                    break;
                
                case '.':
                    gameBoard[i][j+1].setCell(emp,i,'A' + j - 2);
                    break;
            }
        
        }
        readStr.clear();

    }

    totalPeg += numberOfPegs();
}

bool PegSolitaire :: compareGames(PegSolitaire secondGame){
        
    if(numberOfPegs() > secondGame.numberOfPegs())
        return true;
    else  return false;


}

