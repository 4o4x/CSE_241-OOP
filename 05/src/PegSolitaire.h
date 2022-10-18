#ifndef PEGSOLITIARE_H
#define PEGSOLITIARE_H

#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2D.h"

using namespace std;

namespace sBurakYasar{

typedef enum{
    emp,    // Empty cells on the board 
    peg,    // Pegs
    wall    // Wall
}typeOfCell;

class PegSolitaire : public BoardGame2D{
    
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

        void playUser(const string& input);
        void playUser();
        void playAuto();
        void playAutoAll();
        int boardScore();
        bool endGame();
        void initialize();
        void print();
           
    private:
    
        vector < vector<Cell> > gameBoard;
        bool inputCheck(const string& input);

};

}
#endif