#ifndef EIGHTPUZZLE_H
#define EIGHTPUZZLE_H

#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2D.h"

using namespace std;

namespace sBurakYasar{


class EightPuzzle : public BoardGame2D{
    
    public:
        
        void playUser(const string& input);
        void playUser();
        void playAuto();
        void playAutoAll();
        int boardScore();
        bool endGame();
        void initialize();
        void print();
        void bestGame();
           
    private:
    
        vector < vector<int> > gameBoard;
        bool inputCheck(const string& input);
        void swap(const int& row1,const int& column1,const int& row2,const int& column2);

};

}
#endif