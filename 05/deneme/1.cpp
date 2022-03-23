#include <iostream>
#include <vector>

using namespace std;

void print(const vector<vector<int>>&game);

int main(){

    vector<vector<int>> x ={
    {1,0,0,2},
    {1,0,0,2},
    {3,4,4,5},
    {3,6,7,5},
    {8,-1,-1,9}
    };

    print(x);

    //cout << "\033[2J";
    //cout << "\033[1;1H";


}

void print(const vector<vector<int>>&game){

    for(int i = 0; i<game.size();i++){
        for(int j = 0; j<game[0].size();j++){
            
            if(game[i][j] == 0){
                cout << "\033[48;5;1m\u256C\033[0m";
            }
            else if(game[i][j] == 1){
                cout << "\033[38;5;2m\u2588";
            }
            else if(game[i][j] == 2){
                cout << "\033[38;5;3m\u2588";
            }
            else if(game[i][j] == 3){
                cout << "\033[38;5;4m\u2588";
            }
            else if(game[i][j] == 4){
                cout << "\033[38;5;5m\u2588";
            }
            else if(game[i][j] == 5){
                cout << "\033[38;5;6m\u2588";
            }
            else if(game[i][j] == 6){
                cout << "\033[38;5;13m\u2588";
            }
            else if(game[i][j] == 7){
                cout << "\033[38;5;8m\u2588";
            }
            else if(game[i][j] == 8){
                cout << "\033[38;5;9m\u2588";
            }

            else if(game[i][j] == 9){
                cout << "\033[38;5;10m\u2588";
            }

            else if(game[i][j] == -1){
                cout << "\033[38;5;15m\u2588";
            }

        }
        cout << "\033[0m" << endl;
    }

    cout << "\033[0m";

}