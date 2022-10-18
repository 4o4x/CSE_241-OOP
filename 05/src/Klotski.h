#ifndef KLOTSKI_H
#define KLOTSKI_H

#include <iostream>
#include <string>
#include <vector>
#include "BoardGame2D.h"

using namespace std;

namespace sBurakYasar{

class Klotski : public BoardGame2D{
    
    public:
        
        void playUser(const string& input);
        void playUser();
        void playAuto();
        void playAutoAll();
        int boardScore();
        bool endGame();
        void initialize();
        void print();
        virtual void move(char direction) = 0;
        virtual int getType() = 0;

    private:
    
        vector < vector<Klotski*> > gameBoard;
        bool inputCheck(const string& input);

};

}
#endif