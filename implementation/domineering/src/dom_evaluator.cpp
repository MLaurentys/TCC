#include "../include/dom_evaluator.hpp"
std::vector<game> DomEvaluator::evaluate(const Domineering& G){
    auto games = break_configuration(G);
    std::vector<game> ret;
    for (auto& sb : get<1>(games))
        ret.push_back(evaluate_game_fixed(get<0>(games),sb));
    return ret;
}

tuple<vector<move>, vector<move>>
DomEvaluator::get_moves(const int_mat& mat, const semi_board& sb) {
    vector<move> left,right;
    //left moves verticaLLy
    for (int i = std::max(1,sb.top); i < sb.height; ++i)
        for (int j = sb.left; j < sb.width + sb.left; ++j)
            if (mat[i][j] == sb.gID && mat[i-1][j] == sb.gID)
                left.push_back({{i-1,j}, {i,j}});
    //right moves hoRizontally
    for (int i = sb.top; i < sb.top + sb.height; ++i)
        for (int j = std::max(1, sb.left); j < sb.left + sb.width; ++j)
            if (mat[i][j] == sb.gID && mat[i][j-1] == sb.gID)
                right.push_back({{i,j-1}, {i,j}});
    return {left, right};
}

tuple<int_mat, vector<semi_board>>
DomEvaluator::break_configuration(const Domineering& G) {
    auto rems = G.get_sorted_removes();
    int n = G.wid(), m = G.hei(), g_amt;
    int_mat mat;
    std::tie(mat, g_amt) = union_find(n, m, rems);
    vector<semi_board> ret(g_amt, {INT32_MAX, INT32_MAX, 0, 0, -1});
    // During this loop, width and height will mean max x and max y 
    for (int i = 0; i < m; ++i) {
        ret[i].gID = i;
        for (int j = 0; j < n; ++j) {
            int g = mat[i][j];
            if (g == -1) continue;
            if (j < ret[g].left)
                ret[g].left = j;
            if (j > ret[g].width)
                ret[g].width = j;
            if (i < ret[g].top)
                ret[g].top = i;
            if (i > ret[g].height)
                ret[g].height = i;
        }
    }
    for (auto& sb : ret){
        sb.width -= sb.left - 1;
        sb.height -= sb.top - 1;
    }
    return {mat, ret};
}

void toggle (int_mat& mat, move& m, int id) {
    int x1,y1,x2,y2;
    x1 = get<0>(m).x; y1 = get<0>(m).y; x2 = get<1>(m).x; y2 = get<1>(m).y;
    if (mat[x1][y1] == -1) {
        mat[x1][y1] = id;
        mat[x2][y2] = id;
    }
    else{
        mat[x1][y1] = -1;
        mat[x2][y2] = -1;
    }
}

game DomEvaluator::evaluate_game_fixed(int_mat& mat, semi_board sb) {
    auto moves = get_moves(mat, sb);
    int id = sb.gID;
    game ret;
    for (move& m : get<0>(moves)) {
        toggle(mat, m, id);
        ret.left.push_back(evaluate_game_fixed(mat, sb));
        toggle(mat, m, id);
    }
    for (move& m : get<1>(moves)) {
        toggle(mat, m, id);
        ret.right.push_back(evaluate_game_fixed(mat, sb));
        toggle(mat, m, id);
    }
    return ret;
}

std::string build_eval_string (game& G) {
    std::string s = "< { ";
    for (int i = 0; i < G.left.size() - 1; ++i)
        s += build_eval_string(G.left[i]) + ", ";
    s += build_eval_string(G.left[G.left.size()-1]);
    s += " } | { ";
    for (int i = 0; i < G.right.size() - 1; ++i)
        s += build_eval_string(G.right[i]) + ", ";
    s += build_eval_string(G.right[G.right.size()-1]);
    s += " } >";
    return s;
}

void DomEvaluator::print_evaluation(game G){
    cout << build_eval_string(G);
}