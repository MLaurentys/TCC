#ifndef DOMINEERING_H
#define DOMINEERING_H

#include <vector>
#include <tuple>
#include <iostream>

#include "definitions.h"

using std::tuple;
using std::vector;

class Domineering{
    public:
    void make_move();
    Domineering(int n, int m);
    Domineering(int n, int m, vector<b_pos> remove);
    void print();

    private:
    int n; //horizontal
    int m; //vertical
    vector<b_pos> removed;
    vector<move> moves;
};


#endif