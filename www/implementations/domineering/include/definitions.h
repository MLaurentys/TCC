#ifndef DEFINITION_H
#define DEFINITION_H

#include <tuple>

// gID, left, top, width, height
typedef std::tuple<int,int,int,int,int> semi_board;
// (x,y)
typedef std::tuple<int,int> b_pos;
typedef std::tuple<b_pos, b_pos> move;


#endif