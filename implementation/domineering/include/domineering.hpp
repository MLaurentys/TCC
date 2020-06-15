#ifndef DOMINEERING_H
#define DOMINEERING_H

#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>

#include "definitions.hpp"
#include "../../lib/union_find.hpp"

using std::tuple;
using std::vector;
using std::cout;
using std::get;

class Domineering{
    public:
    int wid() const {return n;};
    int hei() const {return m;};
    void make_move(move);
    Domineering(int n, int m);
    Domineering(int n, int m, vector<b_pos> remove);
    Domineering(const Domineering& other);
    void print_board();
    vector<b_pos> get_sorted_removes() const;

    private:
    int n; //horizontal
    int m; //vertical
    vector<move> moves;
    vector<b_pos> removed;
    void sort_removed(vector<b_pos>&) const;
};


#endif