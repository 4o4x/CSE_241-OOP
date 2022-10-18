#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

#include "PegSolitaire.h"
#include "BoardGame2D.h"
#include "EightPuzzle.h"
#include "Klotski.h"

/*For random vaule*/
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace sBurakYasar;


void test(BoardGame2D * game);


int main(){

    srand(time(NULL));

    BoardGame2D * testObj;

    testObj = new PegSolitaire;
    test(testObj);

    delete testObj;

    testObj = new EightPuzzle;
    test(testObj);
    
    vector<BoardGame2D*> game;

    BoardGame2D * Peg1;
    Peg1 = new PegSolitaire;
    game.push_back(Peg1);

    BoardGame2D * Peg2;
    Peg2 = new PegSolitaire;
    game.push_back(Peg2);

    BoardGame2D * Eight1;
    Eight1 = new EightPuzzle;
    game.push_back(Eight1);

    BoardGame2D * Eight2;
    Eight2 = new EightPuzzle;
    game.push_back(Eight2);
   
    BoardGame2D :: playVector(game); 



}

void test(BoardGame2D * game){

    
    
    /*Initialize and print test*/
    
    cout << endl << "Before initialize" << endl;
    sleep(2);
    
    game->print();sleep(2);

    game->initialize();  // Initializing

    cout << "\033[2J\033[1;1H";

    cout << endl << "After initialize" << endl;
    sleep(2);
    
    game->print();
    sleep(2); 
    

    cout << "\033[2J\033[1;1H";


    

    /*operator<< overloading test*/

    cout << endl << "operator<< overloading test" << endl;
    sleep(2);

    cout << game;
    sleep(2);

    cout << "\033[2J\033[1;1H";
    
    /*Playuser(with parameter) test*/

    cout << endl << "Playuser(with parameter) test" << endl;
    sleep(2);

    cout << "\033[2J\033[1;1H";

    cout << endl << "Before" << endl; 
    
    cout << "\033[2J\033[1;1H";

    sleep(2);


    game->print(); sleep(2);

    string input = "5C R";

    game->playUser(input);

    cout << "\033[2J\033[1;1H";

    cout << endl << "After" << endl;

    sleep(2);

    game->print(); sleep(2);
    
    cout << "\033[2J\033[1;1H";

    /*Playuser(without parameter) test*/

    cout << endl << "Playuser(without parameter) test" << endl;
    sleep(2);

    cout << "\033[2J\033[1;1H";

    game->playUser();
    sleep(2);
    cout << "\033[2J\033[1;1H"; 
    
    sleep(2);

   

    game->initialize();

    

    /*PlayAuto test*/

    cout << endl << "PlayAuto test" << endl;
    sleep(2);

    cout << "\033[2J\033[1;1H";

    cout << endl << "Before" << endl; 
    
    cout << "\033[2J\033[1;1H";

    sleep(2);


    game->print(); sleep(2);

    

    game->playAuto();

    cout << "\033[2J\033[1;1H";

    cout << endl << "After" << endl;

    sleep(2);

    game->print(); sleep(2);
    
    cout << "\033[2J\033[1;1H";
    sleep(2);




    /*PlayAutoAll test*/

    cout << endl << "PlayAutoAll test" << endl;
    sleep(2);

    cout << "\033[2J\033[1;1H";

    game->playAutoAll();

    sleep(1); 

    if(game->endGame()){ 
        cout << endl << endl << "Game is over" << endl; //endGame test
        cout << "Your Score is " << game->boardScore() << endl;
    }
    sleep(2);

}

