#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include "../domineering/include/definitions.h"
#include <vector>
#include <tuple>
#include <functional>
#include <unordered_map>

typedef std::vector<std::vector<int>> int_mat;
typedef std::vector<b_pos> pt_list;

std::tuple<int_mat, int> union_find(int n, int m, pt_list pts);

#endif