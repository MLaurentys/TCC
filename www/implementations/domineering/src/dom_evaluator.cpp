#include "../include/dom_evaluator.h"

float DomEvaluator::evaluate(const Domineering& game){
    auto games = break_configuration(game);
    return 0.0f;
}

tuple<vector<move>, vector<move>> DomEvaluator::get_moves(
        const int_mat& mat,
        const semi_board& sb) {
    vector<move> left,right;
    int r_it = 0;
    //left moves verticaLLy
    for (int i = get<0>(sb); i < get<2>(sb); ++i)
        for (int j = std::max(1,get<1>(sb)); j < get<3>(sb); ++j)
            if (mat[i][j] == get<4>(sb) && mat[i][j-1] == get<4>(sb))
                left.push_back({{i,j-1}, {i,j}});
    //right moves hoRizontally
    for (int i = std::max(1, get<0>(sb)); i < get<2>(sb); ++i)
        for (int j = get<1>(sb); j < get<3>(sb); ++j)
            if (mat[i][j] == get<4>(sb) && mat[i-1][j] == get<4>(sb))
                right.push_back({{i-1,j}, {i,j}});
    return {left, right};
}

tuple<int_mat, vector<semi_board>> DomEvaluator::break_configuration(
        const Domineering& g) {
    auto rems = g.get_sorted_removes();
    int n = g.wid(), m = g.hei(), g_amt;
    int_mat mat;
    std::tie(mat, g_amt) = union_find(n, m, rems);
    vector<semi_board> ret(g_amt, {INT32_MAX, INT32_MAX, 0, 0, -1});
    for (int i = 0; i < m; ++i) {
        get<4>(ret[i]) = i;
        for (int j = 0; j < n; ++j) {
            int g = mat[i][j];
            if (g == -1) continue;
            if (j < get<0>(ret[g])) {
                get<2>(ret[g]) += get<0>(ret[g]) - i;
                get<0>(ret[g]) = i;
            }
            else
                get<2>(ret[g]) = std::max(get<2>(ret[g]), j - get<0>(ret[g]));
            if (i < get<1>(ret[g])) {
                get<3>(ret[g]) += get<1>(ret[g]) - i;
                get<1>(ret[g]) = i;
            }
            else
                get<3>(ret[g]) = std::max(get<3>(ret[g]), i - get<1>(ret[g]));
        }
    }
    return {mat, ret};
}
