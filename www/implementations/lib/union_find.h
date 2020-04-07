#ifndef _UNION_FIND_H
#define _UNION_FIND_H

#include <vector>
#include <tuple>
#include <functional>
#include <unordered_map>

typedef std::vector<std::vector<int>> int_mat;
typedef std::vector<std::tuple<int, int>> pt_list;

std::tuple<int_mat, int> union_find(int n, int m, pt_list pts);

#endif