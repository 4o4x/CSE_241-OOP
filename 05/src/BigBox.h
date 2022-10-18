#ifndef BIGBOX_H
#define BIGBOX_H

#include <iostream>
#include <string>
#include <vector>
#include "Klotski.h"

using namespace std;

namespace sBurakYasar{


class BigBox : public Klotski{
    
    public:
        void BigBox();
        void move(char direction);
    private:
        vector<int> matrix;
};

}
#endif