#ifndef DOM_DEFINITION_H
#define DOM_DEFINITION_H

#include <tuple>
#include <vector>
#include <iostream>

#include "../../game_numbers/include/definitions.hpp"

/*

o o o o
o o x x
o o x o


3 3 3 3
3 3 -1 -1
3 3 -1 5

sd (3) : 2, 0 | 4, 3
*/

struct semi_board {
    int left;
    int bottom;
    int width;
    int height;
    int gID;
    semi_board (int a, int b, int c, int d, int e) :
        left{a}, bottom{b}, width{c}, height{d}, gID{e} {}

    semi_board (const semi_board& other) : left{other.left},
        bottom{other.bottom}, width{other.width}, height{other.height},
        gID{other.gID} {}
    semi_board& operator= (const semi_board& other) {
        left = other.left; bottom = other.bottom;
        width = other.width; height = other.height;
        gID = other.gID;
        return *this;
    }
};

struct rectangle {
    int width;
    int height;
    rectangle (int wid, int hei) :
        width{wid}, height{hei} {}
    rectangle (const semi_board& sb) :
        width{sb.width}, height{sb.height} {}
    rectangle (const rectangle& other) :
        width{other.width}, height{other.height} {}
    rectangle& operator= (const rectangle& other) {
        width = other.width;
        height = other.height;
        return *this;
    }
    bool operator== (const rectangle& other) const {
        return width==other.width && height==other.height;
    }
    void print () const {
        std::cout << width << " x " << height << "\n"; 
    }

};

struct b_pos {
    int x;
    int y;
    b_pos (int a, int b) : x{a}, y{b} {}
    b_pos (const b_pos& other) : x{other.x}, y{other.y} {}
    bool operator== (const b_pos& other)
        {return other.x == x && other.y == y;}
    b_pos& operator= (const b_pos& other) {
        x = other.x;
        y = other.y;
        return *this;
    }
    b_pos (b_pos&& other) : x{std::move(other.x)}, y{std::move(other.y)}
        {}
};

struct move {
    b_pos pos1;
    b_pos pos2;
    move (const b_pos& p1, const b_pos& p2) : pos1(p1), pos2(p2) {}
    move (const move& other) : pos1(other.pos1), pos2(other.pos2) {}
    move& operator= (const move& other) {
        pos1 = other.pos1; pos2 = other.pos2; return *this;}
};


struct game {
    std::vector<game> left;
    std::vector<game> right;
    game () : left{}, right{} {}
    game (const game& other) : left{other.left}, right{other.right} {}
    game& operator= (const game& other) {
        left = other.left;
        right = other.right;
        return *this;
    }
};
namespace gameF {
    inline float* get_eval (const game&) { return nullptr; }
    inline auto lIter (const game& g) {
        return std::make_tuple(g.left.begin(), g.left.end()); }
    inline auto rIter (const game& g) {
        return std::make_tuple(g.right.begin(), g.right.end()); }
}

namespace std {
  template <>
  struct hash<rectangle> {
    size_t operator()(const rectangle& key) const {
      return 100*key.width + key.height;
    }
  };

}
#endif