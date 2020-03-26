#include "union_find.h"

std::tuple<int_mat, int> union_find(int n, int m, pt_list pts){
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
        return i*n + j;
    };
    auto get_cell = [&] (int p) {
        int nj = p%n;
        return std::make_tuple<>((p - nj)/n, nj);
    };
    //UF find with path compression
    std::function<int(int,int)> find = [&] (int i, int j) {
        int v = parents[i][j];
        if (v != cell_index(i,j)) {
            int k,l;
            std::tie(k,l) = get_cell(v);
            parents[i][j] = find(k, l);
        }
        return parents[i][j];
    };
    //UF union
    auto make_union = [&] (int p, int q) {
        if (p == q) return p;
        int k,l;
        std::tie(k,l) = get_cell(p);
        parents[k][l] = q;
        return q;
    };
    //flattens parents
    auto flatten = [&] () {
        std::unordered_map<int, int> hm;
        std::vector<int> groups;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (parents[i][j] == -1) continue;
                if (parents[i][j] == cell_index(i,j)){
                    groups.push_back(parents[i][j]);
                    continue;
                }
                int k,l;
                do {
                    std::tie(k,l) = get_cell(parents[i][j]);
                    parents[i][j] = parents[k][l];
                } while (parents[k][l] != cell_index(k,l));
            }
        }
        for (int i = 0; i < groups.size(); ++i)
            hm[groups[i]] = i;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (parents[i][j] == -1) continue;
                parents[i][j] = hm[parents[i][j]];
            }
        }
        return groups.size();
    };

    int rems_ind = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (std::tie(i, j) == pts[rems_ind]) {
                ++rems_ind;
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
                    parents[i][j] = make_union(l, t);
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
    int g_amt = flatten();
    return std::make_tuple<>(parents, g_amt);
}