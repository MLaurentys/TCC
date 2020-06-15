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
    semi_board (int a, int b, int c, int d, int e) :
        left{a}, top{b}, width{c}, height{d}, gID{e} {}
};

struct b_pos {
    int x;
    int y;
    b_pos (int a, int b) : x{a}, y{b} {}
    b_pos (const b_pos& other) : x{other.x}, y{other.y} {}
    bool operator== (std::tuple<int&,int&> other)
        {return std::get<0>(other) == x && std::get<1>(other) == y;}
    b_pos& operator= (const b_pos& other) {
        x = other.x;
        y = other.y;
        return *this;
    }
};

struct move {
    b_pos pos1;
    b_pos pos2;
    move (const b_pos& p1, const b_pos& p2) : pos1(p1), pos2(p2) {}
    move (const move& other) : pos1(other.pos1), pos2(other.pos2) {}
};


struct game {
    std::vector<game> left;
    std::vector<game> right;
};

#endif