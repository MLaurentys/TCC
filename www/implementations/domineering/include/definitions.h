#ifndef DEFINITION_H
#define DEFINITION_H

#include <tuple>

// left, top, width, height, gID
typedef std::tuple<int,int,int,int,int> semi_board;
// (x,y)
typedef std::tuple<int,int> b_pos;
typedef std::tuple<b_pos, b_pos> move;

template<typename T, typename U>
constexpr auto game = std::tuple<vector<T>, vector<U>>;

#endif