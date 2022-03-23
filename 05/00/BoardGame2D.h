#ifndef BOARDGAME2D_H
#define BOARDGAME2D_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace sBurakYasar{

class BoardGame2D{
    
    public:
        virtual void playUser(const string& input) = 0;
        virtual void playUser() = 0;
        virtual void playAuto() = 0;
        virtual void playAutoAll() = 0;
        virtual int boardScore() = 0;
        virtual bool endGame() = 0;
        virtual void initialize() = 0;
        virtual void print() = 0;
        static void playVector(vector<BoardGame2D*> games);
        friend ostream& operator<<(ostream& out,BoardGame2D* obj);

};


}

#endif