#ifndef DOM_DEFINITION_H
#define DOM_DEFINITION_H

#include <tuple>
#include <vector>

#include "../../game_numbers/include/definitions.hpp"

struct semi_board {
    int left;
    int top;
    int width;
    int height;
    int gID;
    semi_board (int a, int b, int c, int d, int e)
        {left = a; top = b; width = c; height = d; gID = e;}
};

struct b_pos {
    int x;
    int y;
    b_pos (int a, int b) {x=a;y=b;}
    bool operator== (std::tuple<int&,int&> other)
        {return std::get<0>(other) == x && std::get<1>(other) == y;}
};

typedef std::tuple<b_pos, b_pos> move;


struct game {
    std::vector<game> left;
    std::vector<game> right;
};

#endif