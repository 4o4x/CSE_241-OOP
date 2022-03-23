
#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2D.h"
#include "EightPuzzle.h"
#include <unistd.h>



using namespace std;

namespace sBurakYasar{

void BoardGame2D :: playVector(vector<BoardGame2D*> games){

    for(int i=0; i<games.size();i++){
        games[i]->initialize();
    }

    for(int i=0; i<games.size();i++){
        games[i]->playAutoAll();
        sleep(1);
    }

}

ostream& operator<<(ostream& out,BoardGame2D* obj){
    obj->print();
    return out;
}

}
