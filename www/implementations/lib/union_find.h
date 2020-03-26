#include <vector>
#include <tuple>
#include <functional>

typedef std::vector<std::vector<int>> int_mat;
typedef std::vector<std::tuple<int, int>> pt_list;

int_mat union_find(int n, int m, pt_list pts);
