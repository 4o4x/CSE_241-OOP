#include <iostream>
#include <vector>
#include <string>

/* These are for generating random numbers*/
#include <ctime>
#include <cstdlib>
#include "hw1_lib.h"

using namespace std;

/*Board Cell Type*/
/*typedef enum{
    emp = 0,    // Empty cells on the board 
    peg = 1,    // Pegs
    wall = -1   // Unplayable cells on the board
}board;*/

/* Types of board to assign*/





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

