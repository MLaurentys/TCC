#ifndef DEFINITION_H
#define DEFINITION_H

#include <tuple>

// left, top, width, height, gID
typedef std::tuple<int,int,int,int,int> semi_board;
// (x,y)
typedef std::tuple<int,int> b_pos;
typedef std::tuple<b_pos, b_pos> move;

template <typename T>
constexpr auto mt = std::make_tuple<T,T>;

#endif