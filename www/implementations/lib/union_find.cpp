#include "union_find.h"

int_mat union_find(int n, int m, pt_list pts){
    int_mat parents(m, std::vector<int>(n));

    //accessor with necessary bound check
    auto check = [&] (int i, int j) {
        int ret = -1;
        if (i >= 0 && j >= 0) {
            ret = parents[i][j];
        }
        return ret;
    };
    //cell index calculation = base parent index
    auto cell_index = [&] (int i, int j){
        return i*n + m;
    };
    //UF find with path compression
    std::function<int(int,int)> find = [&] (int i, int j) {
        int v = parents[i][j];
        if (v != cell_index(i,j)) {
            int nj = v%n;
            parents[i][j] = find(v-nj, nj);
        }
        return parents[i][j];
    };
    //UF union

    int rems_ind = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (std::tie(i, j) == pts[rems_ind]) {
                parents[i][j] = -1;
                continue;
            }
            int t = check(i-1, j);
            int l = check(i, j-1);
            if (t == -1 && l == -1) {
                parents[i][j] = cell_index(i,j);
                continue;
            }
            if (t != -1) {
                t = find(i-1, j);
                if (l != -1) {
                    l = find(i, j-1);
                    parents[i][j] = 
                }
                else
                    parents[i][j] = t;
            }
            else {
                l = find(i, j-1);
                parents[i][j] = l;
            }
        }
    }
}