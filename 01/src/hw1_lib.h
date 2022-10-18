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



